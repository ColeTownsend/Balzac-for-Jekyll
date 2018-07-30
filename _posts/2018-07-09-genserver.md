---
layout: post
title: Elixir Concurrent Programming
description: "GenServer module for concurrent programming in Elixir"
categories: articles
date: 2018-07-09
image: 
    feature: mind.jpg
comments: true
excerpt: A not so light overview of the Elixir GenServer module for concurrent programming 
---

## Introduction

In `Elixir` if you need to write concurrent code, the `GenServer` module offers you lots of nice functions to handle the boilerplate it takes.

Let’s imagine we have a module called `Concurrent` and you want it to be run into a detached process; all it takes is to wrap it using the `GenServer` module: it exposes a bunch of special functions that help you define the way your concurrent module must work.

Let’s start with a very simple example.

{% gist 224cb9869e83853ddfa9748658a33b31 %}

The `start_link` function is used to launch a `GenServer` process.

To try it, just type `iex -S mix` and type `Concurrent.start_link`; here’s the output you should be seeing:

```
iex(5)> Concurrent.start_link
  {:ok, #PID<0.164.0>}
```


As you can see, a tuple is returned: the `:ok` atom and the process id for the process.

**Note**: the special `__MODULE__` variable is used to automatically provide the module name to the `start_link` function, which is supposed to receive it. Also, the second argument, the empty list [], is the initial state of the process, which in this example is empty.

If, by any chance, you need to make some stuff when the process starts, you can implement the `init` function (if you don’t provide your own implementation, a warning will be shown and a default implementation will be injected by the compiler).

{% gist 6f27e8d61dd67aa8d274fe660998e9c1 %}

Execute this (don’t forget to type recompile if you’re still in the old `iex` session) and you will see:

```
21:25:33.310 [info] Starting Elixir.Concurrent
  {:ok, #PID<0.177.0>}
```


So now you can also see the log message we injected in our init implementation. Please also note that you must return the tuple {:ok, initial_data} when you provide your function implementation.
On the other side, the initial_data is whatever is passed to the start_link function.

### What about the state ?

I have previously mentioned that the `GenServer` module gives you the chance to store the state of the process. Let’s understand how.

We have seen that whatever is passed to `start_link` is injected into the `initial_data`, which represents the inital state of the module. So, we can retrieve the state of the process by using the call function of the `GenServer` module:

```
GenServer.call(pid, {:get_state})
```


Anytime the `GenServer.call` function is invoked the compiler looks for any existing implementation of the `handle_call` function, selecting the right one by applying pattern matching using the second argument provided. For example, assuming the following implementation is provided:

{% gist cc0e3f614e0d020820c264677536f7f9 %}

By typing in the `iex` session:

```
GenServer.call(pid, {:get_state})
```

will make you obtain:

```
iex(4)> GenServer.call(pid, {:get_state})
  []
```

The `handle_call` function takes 3 arguments:

1. the identifier and the arguments for the function 
2. a reference to the caller
3. the current state of the process

So this is the signature that your function must have. On the other side, the return value is always a tuple with the `:reply` atom as first argument, indicating that the function is actually returning something; the second one is the response value, and the last one is the new state that this process will hold (as you can understand, they are the same in our implementation since we are not changing anything here).

Note: the `handle_call` function is synchronous, meaning that it will be blocking the code execution until the response is ready and returned.

Of course, we might create an helper function to retrieve the state of the process:

{% gist bc023a938bd440e89e010295d7f18d2f %}


### Updating the state of a process

If i have not lost you so far, it might be pretty easy to understand that changing the state of a process can be a very easy task. For example:

{% gist b2db8c0563ecc722e2878a5653ccd2c7 %}

which will give us:

```
iex(7)> {:ok, pid} = Concurrent.start_link
  22:46:50.703 [info] Starting Elixir.Concurrent
  {:ok, #PID<0.469.0>}
  iex(8)> Concurrent.get_state(pid)
  []
  iex(9)> Concurrent.set_state(pid, "test")
  %{state: "test"}
```

**Note**: this is of course a pretty useless state management logic, consider it just a placeholder for something worth showing :D

### Interprocess communication

In order to make possible for processes to communicate `GenServer` exposes, among the others, 3 functions:

- handle_call
- handle_cast
- handle_info

All of them access the current state of the process, and all of them return it.

The one that differs the most from the others is the `handle_call` one, which receives the from parameter and returns a tuple with 3 elements, the second one being the response value. Do not confuse this with the last argument, the new state, which is used to update the current state of the process.

We have already seen how to use the `handle_call` one, which, i remember, is synchronous. `handle_cast`, instead, is triggered by the `GenServer.cast` call, and is the one to be used if you do not need immediate response and can afford to go asynchronous.

```
GenServer.cast(pid, {:something_to_cast})
```

This method will only return the `:ok` atom.

About `GenServer.handle_info`, we must observe that no `GenServer.info` will exist, and can be used to receive messages from any `Elixir` process except `GenServer`. For example, the one to send a message to our `GenServer` process can be the standard `Elixir` Process module, by using the send function. Like `handle_cast` it always returns the `:ok` atom.

### An example of synchronous vs asynchronous scenario

Imagine we have a payment system, where clients send a payload that describes the item to purchase; we can have two types of implementation:

- a _synchronous_ one: the client must wait for a response from the process, and so the user
- an _asynchronous_ one: the client gets detached after the payload delivery and the user can keep on using the application

Of course, the second implementation requires other features, like the ability to notify a client about a successful (or not) purchase; it is by far the more convenient for a good user experience, but it’s not that unusual to find synchronous implementations around.

In this scenario we will be having the following code:

{% gist c387737db88ec633f56983719d431dd1 %}

Also, we have added a new module, to better outline concepts and responsibilities:

{% gist b0b53724bf55d5c5cb5552127efd12cd %}

After recompiling the code in the `iex` session, we will see:


```
iex(20)> {:ok, pid} = Concurrent.start_link
  10:08:51.953 [info] Starting Elixir.Concurrent
  {:ok, #PID}
  iex(21)> PaymentProcessor.process_payment("payload")
  :ok
  10:08:53.233 [info] Starting Elixir.Concurrent
  10:08:53.233 [info] Elixir.Concurrent: done
  10:08:53.233 [info] Elixir.PaymentProcessor: payment processed
```

So we start the `Concurrent` process, that will be handling payments, and use the `PaymentProcess` one to trigger the process of a payment.

If we want to go asynchronous, we must slightly modify our code. We need a function to handle the `GenServer.cast` call:

{% gist f9ec7978cea140ec808b4f95ead256dd %}

As well as a helper function in the `Concurrent` module:

{% gist 9c81c6b36401ec3f295ede692257a3cf %}

Last, but not least, to have consistent names, we add the following function to the `PaymentProcessor` module:

{% gist bc6f45684b8defd1941f577a6ea95269 %}

Recompiling the code and executing again:

```
iex(48)> {:ok, pid} = Concurrent.start_link
  10:54:29.690 [info] Starting Elixir.Concurrent
  {:ok, #PID}
  iex(49)> PaymentProcessor.submit_payment("test")
  10:54:30.475 [info] Starting Elixir.Concurrent
  10:54:30.475 [info] Elixir.Concurrent: done
  10:54:30.475 [info] Elixir.PaymentProcessor: payment processed. Process detached.
  :ok
  iex(50)>
  10:54:33.476 [info] Payload test has been processed.
```

As you can see, the client is totally detached from the payment process, and after 3 seconds (because of the `:timer.sleep(3000)` command) the `Payload test has been processed` pops up.

So, we made hopefully clear that if you have clear in mind what problem you are resoliving, if it needs concurrent code execution, `GenServer` module can be a great help.

The next reasonable question is: how can I be sure that a given process does not crash ? The answer is **Supervisor**.

## The Supervisor module

The `Supervisor` module is able to control a `GenServer` process and respawn it if crashes, according to some specific policies.

Let’s jump straight on the code:

{% gist 6287a85c6e979c113127974133c759cb %}

If you, as always, test it in the `iex` session, you will see:

```
iex(5)> ConcurrentSupervisor.start_link
  09:55:47.943 [info] Starting Elixir.Concurrent
  {:ok, #PID<0.142.0>}
```

So basically we are having back the pid of the `Supervisor` process, and we can see the log of the `Concurrent` process that is started.

As you can see, the children list is made by the modules we want to run, wrapped in a `worker` function, which represents a sort of template; it receives the module to wrap and the list of options to pass to it. Pay attention here: what you pass to the worker is used as argument of the module `start_link` function, where you have to correctly handle them before injecting in the `GenServer.start_link` call in your module.

Basically, if you pass values there, the signature of your module `start_link` must accept them.

Once the `Supervisor` starts and launches the workers, it calls, by default, the `start_link` method of the module it wraps.

### Supervisor strategies

In the `supervise` command we must pass a strategy type. Possible values are:

- `:one_for_one`: if any of the worker crashes, it gets restarted
- `:one_for_all`: if any of the worker crashes, all of them are restarted
- `:rest_for_one`: if one of the worker crashes, only the ones defined right below it (in the children list) get restarted
- `:simple_one_for_one`: this is slightly different from other strategies; we’ll see this laters.

For example, imagine that we have a children like the following:

```
children = [
  worker(ConcurrentA, []),
  worker(ConcurrentB, []),
  worker(ConcurrentC, [])
]
```

with 3 existing modules, `:one_for_one` would cause that any of the workers crashing will be automatically restarted, always; `:one_for_all` means that if one of the workers crashes, all of them will be restarted; `:rest_for_one` means that if `ConcurrentB` crashes, it and `ConcurrentC` will be restarted.

### A different strategy: :simple_on_for_one

If you create a `Supervisor` that uses such strategy and you try to start it you will see that no workers are launched; it’s because this strategy pretends explicit and manual starting of the workers, by using `Supervisor.start_child`; this means that you have the flexibility to spawn multiple occurrences of the same process. Basically, the whole idea of this strategy is that you might need an undefined number of processes, spawning more of them, for example, due to some specific demand or needs. The lifecycle of the workers of a Supervisor so defined must explicitly be controlled, as already told, by using some Supervisor functions like `stat_child` and `terminate_child`.

### The restart option

The worker function takes an optional restart argument that can define the restart policies for the process. Possible values are:

- `:permanent`: the crashing process will always be restarted. This option is default for all the strategies except the :simple_rest_for_one one.
- `:transient`: the process is restarted only in case of cerash. Nothing will be done if the process will be termined by user command, for example. This option is default for :simple_rest_for_one.
- `:temporary`: a terminating process will never be restarted.

It’s not unusual that an `Elixir` application spawns a big number of processes, so dealing with pids might be tricky and error prone. Since version 1.4, the `Registry` module is there to help us giving the chance to play with processes and using them by names and not pids. I will cover the `Registry` in a separated article in the near future.