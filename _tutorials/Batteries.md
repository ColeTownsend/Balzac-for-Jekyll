---
layout: post-no-feature
title: Batteries
description: Charge
category: tutorial
comments: true
tags: [Charge, Robotics, Battery]
image:
  feature: robo_rises.jpg
---

### Introduction

![Drawing B]({{ site.url }}/images/Batteries/battery1.jpg)

With the advent of portable personal electronics, from cell phones to mp3 players, to laptops and even watches, there has been a massive surge in battery research within the last decade. No longer are your robots limited to bulky low power non-rechargeable batteries, and instead today there is a large assortment to suit your robots' demands. 

### Ratings

How are batteries rated? With any battery you will see a voltage and a powerrating. Battery voltages can be somewhat complicated. When fully recharged, a battery will often be 15% above its voltage rating. When fully discharged, about 15% below its rating. A fully charged battery will also immediately drop below its rating when driving heavy loads, such as DC Motors. To increase battery voltage, wire multiple of them in series.

Batteries also cannot supply an infinite current. So expect batteries of different types but equal voltages to have different current outputs. To increase battery current output, wire multiple of them in parallel. This is why batteries often come in assembled packs of smaller cells. So when using a battery, make sure your circuit handles changes in battery voltage. For the power rating you will see something like 1200mAh. mAh means miliamps per hour. So if it is 1200mAh, that means the battery can supply 1.2 amps for one hour. Or 2.4 amps for 30 minutes. Or .6 amps for two hours. You do the math.

### Whats the difference between mA and mAh? 

mAh is how much current it 'stores', while mA is the max power it can give.
For example 1500mAh means it can give your robot 1.5 A for one hour before the battery dies. Or 3A for 30 min. Or 6A for 15 min.
While 1500mA means it can give your robot 1.5A until the cows come home, but no more than that.

### Notes on Parallel Batteries 

You must be very careful when wiring batteries into parallel. If you do not follow these following rules, your batteries will do whats called self discharging. This is when one battery charges another battery in parallel, resulting in high inefficiency, overheating, and damage.
When you put two batteries together in parallel that do not have equal charges, self discharging occurs. You must make sure that both batteries are the same exact type, and you should only charge and discharge them while connected in parallel. You also should not combine an old battery with a new battery, even if they are the same type, as charge/discharge rates change with age.

### Types of batteries

* **Alkaline batteries** are the most common, easiest to get, and cheapest too. However they are useless, dont buy them. They have low power capacities, are heavy, have trouble supplying large amounts of current in short time periods, and get expensive to constantly replace. The same goes for Zinc-carbonbatteries, which suck even more.

![Drawing B]({{ site.url }}/images/Batteries/battery2.jpg)


* **Fuel Cell batteries** are finally here for robot builders! Although they are still probably too expensive for most hobbyists (~$400). The technology is rapidly improving, so only a few more years until they become cheaply available. Fuel cells are heavily being pursued in research by companies who want to out do the lithium batteries and make billions of dollars. Basically a fuel cell is a tiny engine the size of a battery, and refillable with methanol or ethanol. They are expected to have a two to three times improvement in energy density over today�s Lithium-ion batteries. However it has been estimated that Lithium Ion batteries themselves will probably be developed to have twice the energy capacity as they have today.


![Drawing B]({{ site.url }}/images/Batteries/battery3.jpg)
 
* **Lead Acid batteries** were developed in the late 1800s, and were the first commercially practical batteries. They remain popular because they are easy and inexpensive to manufacture. Rechargeable lead-acid batteries have been available since the 1950s and have become the most widely used type of battery today. 

![Drawing B]({{ site.url }}/images/Batteries/battery4.jpg)

So what does this mean for you? Motorcycle lead acid batteries work great for larger low performance type robots. They are great for solar power robots too. Best of all, they are cheap and available off the shelf. Just remember that lead acid batteries have the serious problem of being very large and heavy, need to always be kept charged, and do not have the high discharge rates as the more modern batteries.

There are three main types of lead acid batteries. Wet Cell (flooded), Gel Cell, and Absorbed Glass Mat (AGM). The Gel Cell and the AGM batteries are specialty batteries that typically cost twice as much as a premium wet cell. However they store very well and do not tend to sulfate or degrade as easily or as easily as wet cell. There is little chance of a hydrogen gas explosion or corrosion when using these batteries. Gel Cell batteries, which are best used in very deep cycle applications, still are being sold but AGM batteries are typically better. In most cases AGM batteries will give greater life span and greater cycle life than a wet cell battery.

80% of all battery failure is related to sulfation build-up. This build-up occurs when the sulfur molecules in the electrolyte (battery acid) become so deeply discharged that they begin to coat the battery's lead plates. The buildup will become so bad that the battery will die. There are several things you need to remember when managing lead acid batteries to prevent battery failure. First, make sure they always remain fully charged. This means recharge as often as possible, and no partial recharging either. Next, batteries not used for awhile will slowly discharge internally, so you need to make sure they are kept fully charged often. For some batteries several times a week. Also, really hot temperatures or subzero temperatures are bad too. And make sure you always use the proper charger and charging rate for the right type of battery. Call the manufacturer if uncertain.


* **Lithium (Li-ion batteries**) are the new standard for portable power. Li-ion batteries have the same high energy capacity as NiMHs, power output rates of NiCads, and weigh about 20%-35% less. They also have zero memory effect problems, meaning you can recharge whenever. Although lithium batteries are the most advanced for portable power, they are also usually the most expensive. Prices have been significantly dropping lately however, and I predict NiMH and NiCAD types soon becoming obsolete. They are made out of totally non-toxic material, making them safe for cute squirrels and pretty trees. Just remember, lithium ignites very easily, and forms large quantities of hydrogen when put in contact with water, so don't shoot at it or blow it up or anything of that nature. Also, fire extinguishers are usually water based, so dont use them on lithium battery fires. Bad stuff will happen. There are also lithium polymer batteries. This battery type has extremely high current output capabilities (30A+), but less power density than lithium ion batteries.

![Drawing B]({{ site.url }}/images/Batteries/battery5.jpg)


* **NiCad (Nickel Cadmium) batteries** are good for small to medium size range robots. They have the highest current output, are more affordable than NiMH's, and can be recharged within one or two hours. However recharging NiCad batteries is a black art. Ever notice how some older cell phone batteries just do not last as long on a single charge as when you first bought it? This is called memory effect. A NiCad, over many charges, can only store less and less energy after each recharge. To prevent memory effect, whenever you wish to recharge your NiCad, you must first fully discharge it. Just hook up both battery leads to a cute kitten until it stops moving. I guess a motor would work too . . . And remember, NiCad batteries contain toxic cadmium stuff, so save a squirrel and recycle/dispose of it properly.

![Drawing B]({{ site.url }}/images/Batteries/battery6.jpg)

* **NiMH (Nickel Metal Hydride) batteries** are really neat. Older cell phone batteries were often NiMH. You can recharge them as much as you want, they have good current output, and have the highest energy capacity. I would recommend them for small size robots and for powering circuits. Note, NiMH batteries usually take like 10 hours to recharge depending on various factors. Also, some NiMH batteries have a high self-discharge rate. In other words, leave it for a week or so, and you will find an entirely discharged battery. But fortunately NiMH battaries can last many more cycles than your typical NiCad battery.

![Drawing B]({{ site.url }}/images/Batteries/battery7.jpg)

