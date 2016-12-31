---
layout: post
comments: true
assets_dir: /images/dl
description: A self-motivated winter project.
title: Automated Gripper Bot
author: Pranav Sankhe
category: blog
tags: [Gripper, Bot, Automated]
---
<p>In winters of my freshie year I wanted to built a bot which when left into some unknown location can detect the objects around it and grip them one by one. I am going to share my experience as in how I went about making this bot.</p>

### WHAT WENT INSIDE:

<p>To detect objects there are two ways one is using light and other is using sound. I chose sound since I wanted a good range of about 2 metres. For this I needed a sound emitting cum detecting sensor to measure the distance from the object.The sensor
which I used was HC SR04 ultrasonic sensor which is capable of emitting as well as detecting ultrasonic sound signals. Here is how it looks:<br>

<img src="{{ site.url }}/images/Gripper/A.png" alt="ultrasonic sensor" height="24" width="32">

This sensor which was fixed to a servo motor which essentially was attached to the front of the bot. The bot had 3 wheels one of them was a castor wheel which was in front and the other two were the rear wheels.
For the gripper I used worm-screw mechanism.<br>
<img src="{{ site.url }}/images/Gripper/B.png" alt="Gripper" height="32" width="40">
So enough for the hardware I guess :p .</p>



### WORKING:
<p>As the servo motor rotated in quantum steps the ultrasonic sensor sent the signals to the  microcontroller(arduino). The microcontroller analysed the data and processed it to give the further instructions to the bot as to how to proceed towards the nearest object. Let’s see the logic of the arduino code which I used for my bot.</p>

#### Algorithm :

##### Step 1:
<p> At various positions of the servo motor the ultrasonic sensor is instructed to fire off an ultrasonic sound signal and the time required to detect back the signal after bouncing from the object is measured.</p>

##### Step 2:
<p>After having scanned the area, the distance and the angle w.r.t median of the bot's body from the nearest object is noted down.</p>


##### Step 3:
<p> Now all we need to do is to instruct the motors of the bot to function and voila!  we are at our desired position. </p>

##### Step 4:
 <p>Here the gripper comes to action.The motor of the gripper is instructed to function for a predefined span of time which ensures that the object has been gripped.</p>

---
<h3> Code:</h3>

Here's the **Arduino code** (a pretty clumsy code because i am a noob in programming :p)<br>
<a href="{{ site.url }}/sankhe_gripper.ino"> Code </a>
