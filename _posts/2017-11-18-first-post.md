---
layout: post-no-feature
title: Is 0.9999... = 1?
description: "What happens if we keep writing 9's infinitely many times in the n<sup>th</sup> decimal place? Will we get arbitrarily close to 1 or does it precisely equal 1?"
categories: Mathematics
image: 
        feature: soft-trees.jpg
comments: true
---
Here is an informal, but intuitive proof that I came up with back in highschool.

The trick is to take your calculator and enter: 

1/9 = 0.1111...

Then,

2/9 = 0.2222...

3/9 = 0.3333...

8/9 = 0.8888...

We're beginning to see a pattern here.

So,

9/9 must be 0.9999...

But, 9/9 = 1 

Hence, 0.9999... = 1

And we're done!

## Mathjax Test

$$
\begin{align*}
  & \phi(x,y) = \phi \left(\sum_{i=1}^n x_ie_i, \sum_{j=1}^n y_je_j \right)
  = \sum_{i=1}^n \sum_{j=1}^n x_i y_j \phi(e_i, e_j) = \\
  & (x_1, \ldots, x_n) \left( \begin{array}{ccc}
      \phi(e_1, e_1) & \cdots & \phi(e_1, e_n) \\
      \vdots & \ddots & \vdots \\
      \phi(e_n, e_1) & \cdots & \phi(e_n, e_n)
    \end{array} \right)
  \left( \begin{array}{c}
      y_1 \\
      \vdots \\
      y_n
    \end{array} \right)
\end{align*}
$$
