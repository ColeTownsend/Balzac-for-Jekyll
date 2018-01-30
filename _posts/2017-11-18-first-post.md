---
layout: post-no-feature
title: 0.999... = 1
description: "Throughout my journey in mathematics I have uncovered many surprising details about our reality. One of my first revelations was that 0.999... and 1 represent the same number."
categories: Mathematics
comments: true
---
# Introduction

As a high school student, mathematics was the subject I struggled the most with. However, I was rather intrigued by the mysteries surrounding math and although I had no idea what most of the symbols were, I enjoyed playing around with my calculator. 

I first came across the idea that 0.999... = 1 (where the 9's are repeating infinitely many times, of course) whilst studying [Geometric Series](http://mathworld.wolfram.com/GeometricSeries.html) and I must say, even after seeing the proof, I was not yet fully convinced. This was due to my lack of understanding of what "infinitely many" really meant. At the time, I needed something tangible that I could grasp. 

# An Informal Proof

The basic intuition I had was to use the fact that 1 is a rational number and so is 0.999..., since they are equal, then I must be able to express 0.999... as a ratio of two integers which are equal to 1. This is very easy since the ratio of any integer, except 0, with itself is equal to 1. That is, 

$${a \over a} = 1, a \ne 0, a \in \mathbb{Z}$$.

Now, after spending some time playing around with the numbers on my calculator, I discovered the following pattern:

$${1 \over 9} = 0.111$$...

$${2 \over 9} = 0.222$$...

$${3 \over 9} = {1 \over 3} = 0.333$$...

$${4 \over 9} = 0.444$$...

$${5 \over 9} = 0.555$$...

$${6 \over 9} = {2 \over 3} = 0.666$$...

$${7 \over 9} = 0.777$$...

$${8 \over 9} = 0.888$$...

Here it was reasonable to assume by induction that,
$${9 \over 9} = 1 = 0.999...$$

# Rigorous Proof

First, we rewrite 0.999... as the sequence of partial sums denoted by $$s_n$$ where n is the number of terms (or number of 9's) and is given by:

$$s_n = {9 \over 10} + {9 \over 10^2} + {9 \over 10^3} + ... + {9 \over 10^n}$$

Multiplying both sides by ${1 \over 10}$ gives

$${1 \over 10} s_n = {9 \over 10^2} + {9 \over 10^3} + {9 \over 10^4} + ... + {9 \over 10^{n+1}}$$

Subtracting $(2)$ from $(1)$ then gives

$$(1 - {1 \over 10}) s_n = ({9 \over 10} + {9 \over 10^2} + {9 \over 10^3} + ... + {9 \over 10^n}) - ({9 \over 10^2} + {9 \over 10^3} + {9 \over 10^4} + ... + {9 \over 10^{n+1}})$$

so

$$(1 - {9 \over 10}) s_n = {9 \over 10} - {9 \over 10^{n+1}}$$.

Therefore,

$$s_n = \frac { \frac {9}{10} - \frac {9}{10^{n+1}}}{1 - \frac {1}{10}} = 1 - {1 \over 10^n}$$.

Hence,

$$\mathop {\lim }\limits_{n \to \infty } {s_n} = \mathop {\lim }\limits_{n \to \infty } {1 - {1 \over 10^n}} = 1$$.

Thus, we conclude that 1 and 0.999... are different decimal representations of the same real number.

