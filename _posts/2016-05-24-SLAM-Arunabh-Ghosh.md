---
layout: post
title: "SLAM"
author: Arunabh Ghosh
description: Basics of Simultaneous Localisation and Mapping
category: blog
comments: true
tags: [SLAM, Robotics, localisation, mapping]
image:
  feature: robo_rises.jpg
---

## Introduction

The term SLAM is as stated an acronym for __Simultaneous Localization And Mapping__. Mapping is all about building maps of the environment. There are a number of different methods for building maps and some of them are quite sophisticated. All these methods have in common that they build a model of the environment while also addressing the fact that the robot itself accrues uncertainty while it moves. 

## Steps involved in SLAM algorithms

The various algorithm consists of multiple parts; Landmark extraction, data association, state estimation, state update and landmark update. This post will explain what happens in each step. There are many different algorithms to accomplish each of these steps and one can follow any one of the methods. The fundamentals of each algorithm is what this post will explain.

* **Landmark Extraction**

 ![Drawing B]({{ site.url }}/images/SLAM/SLAM1.jpg)
Landmarks are distinct, salient features like blobs or corners within an image/frame. Salient features in computer vision are an art in itself. There are dozens of different approaches to extract, describe and match such features. Once extracted they help the robot keep track of where it is by measuring its position relative to the landmark. Landmarks act as memory and helps the robot identify whether it has visited a certain place in the past or not which brings us to the next part.

* **Data association** 

 ![Drawing B]({{ site.url }}/images/SLAM/SLAM2.jpg)
The problem of data association is that of matching observed landmarks from different (laser) scans with each other. We have to accurately tell whether we have seen a landmark or if it’s a new landmark. If it’s new we add it to the list of observed landmarks, if it’s old we we can measure the relative position of the robot and then accordingly update the position of the robot as well as the landmark on the map. This brings it to the next logical step.

* **State Estimation and State Update**

Here we try to estimate position of the robot using input from number of sensors. There are two types of sensors internal and external sensors.

*Internal sensors* : These are sensors that are attached to the robot. They include accelerometer, gyroscopes, motor encoders, cameras which help the robot localize itself without any external interference.

*External sensors*: As the name suggests these the robot gets its input from sources not attached to the robot. It includes navigation systems like GPS, electric beacons etc.

Using just internal sensors usually gives small amount of error which over time adds up to produce significant errors. This is why we also employ the use of external sensors to facilitate internal sensors. 
We update the estimated state using sensor data. Using observed landmarks we calculate what should have been our position. Usually there is some difference between the estimated state and the calculated state, this is called the innovation.
Finally depending upon how sure are we about the landmarks and the sensor data we update the robot position to be somewhere between estimated state and calculated state.



* **Landmark update**

When we observe a previously unseen feature we update the list of landmarks to include this new feature. Also when we observe a old landmark, if it appears at the same position as in the previous measurement our confidence in that Landmark is increased. This used to decide if we should trust the sensors more than the landmarks or vice-versa.


After Landmark update the robot moves and then the whole cycle repeats again. When the robot moves the uncertainty of its position increases. After the cycle not only the robot is confident of its position but has also extracted information about the environment and associated itself with it. In this way the robot not __only maps the environment but also knows where it is in it__.


## Conclusion

The main aim of this post was to familiarize one with the basics of a SLAM Algorithm to the level that he/she is now able to go further, read tutorials from the internet and implement a SLAM based robot. The applications of this technology are huge. It is the key to __self-driving cars__, __unmanned aerial vehicles__, __autonomous underwater vehicles__, __planetary rovers__, newly emerging __domestic robots__ and even __robots inside the human body__. It is a big and active research field with many unsolved problems.

 ![Drawing C]({{ site.url }}/images/SLAM/SLAM3.jpg)
__Hope you had a good time reading this blog and were able to learn something new!!__ 

