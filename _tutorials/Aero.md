---
layout: post
title: Aerodynamics
description: Aerodynamics in Race Cars
category: tutorial
comments: true
tags: [Aerodynamics, Mechanical]
image:
  feature: robo_rises.jpg
---

Aerodynamics is the science that studies objects moving through air. It is closely related to fluid dynamics as air is considered a compressible fluid. Nowadays, aerodynamics is the utmost important factor in Formula One car performance. It has even nearly become one of the only aspects of performance gain due to the very marginal gains that can currently be made by engine changes or other mechanical component development. This downforce can be likened to a virtual increase in weight, pressing the car down onto the road and increasing the available frictional force between the car and the road, therefore enabling higher cornering speeds.

![Pic]({{ site.url }}/images/Aero/a.png)

Furthermore, as Formula One teams have the greatest resources to develop aero efficiency of its cars, the greatest strives are made here. F1 teams have unrivalled CFD computing power and at least one full time wind tunnel only for validating and improving their designs.

While basic aerodynamic methods and formulas can be simply resolved, other properties are verifiable with empirical formulas. More complex shapes such as airplanes or racing cars are however impossible to calculate precisely, rendering computational fluid dynamic systems (CFD applications on super computers) and wind tunnels an absolute requirement to validate designs.

Application in Formula One
F1 (and in general, all winged racing cars) can be considered to be canard configurations in the sense that the front and back wings are on opposite sides of the centre of gravity and both are "lifting" (strongly) in the same direction, in this case creating downforce.
In the engineering of the aerodynamics of an F1 or any racing car, drag and downforce are the two most important components. And they are interlinked to one another. Methods adopted to increase downforce automatically results in increase in drag. So it is a challenge for the engineer to find the optimum setup and strike the perfect balance between maximum downforce and minimum drag possible. 
From a spectator's point of view, a car can be considered in (at least) 3 parts: the front wing, the car's body and the rear wing. Each of the parts can be optimised for the required downforce at a minimum of drag. Practically however, every component has its influence on the behaviour of the car and cannot be regarded as an individual component. As a result, no element is tested individually, but always a complete scale model of a car.
Because a complete racing car is a very complex system, teams of engineers usually evolve the car step by step, developing a particular item and check its effect on the car. Such overall effect can then be calculated with Amdahl's law:

![Pic]({{ site.url }}/images/Aero/b.png)

After verifying its improvement, the car's efficiency is determined and then simulated on different tracks to see on where it is useful. That usefulness is always the result of a reduction in drag or an increase in downforce.
Drag
Drag is the aerodynamic force that is opposite to the velocity of an object moving through air (or any other fluid). Its size is proportional to the speed differential between the air and the solid object. It is therefore unimportant if either the air is moving around a static object or if the object is moving at a speed through static air. In an F1 or racing car, the drag slows down the car on the straights. 
Drag comes in various forms, one of them being friction drag which is the result of the friction of the solid molecules against air molecules in their neighbourhood. Friction and its drag depend on both the fluid and the solid properties. A smooth surface of the solid for example produces less skin friction compared to a rough one. For the fluid, the friction varies along with its viscosity and the relative magnitude of the viscous forces to the motion of the flow, expressed as the Reynolds number. Along the solid surface, a boundary layer of low energy flow is generated and the magnitude of the skin friction depends on conditions in the boundary layer.
Additionally, drag is a form of resistance from the air against the solid moving object. This form of drag is dependent on the particular shape of a wing, and is therefore called form drag. As air flows around a body, the local velocity and pressure are changed, effectively creating a force.
Interference drag or induced drag on the other hand is the result of vortices that are generated behind the solid object. Due to the change of direction of air around the wing, a vortex is created where the airflow meets unchanged, straight flow. The size of the vortex, and thereby its drag strength increases with an increasing angle of attack of the aerofoil. As a primary source of possible drag reduction, Formula One teams try to counteract this drag by adding end plates to wings or with fillets at the suspension arms.

![Pic]({{ site.url }}/images/Aero/c.png)

Other sources of drag include wave drag and ram drag. The first is unimportant for normal race cars as it occurs when the moving object speeds up to the speed of sound. Ram drag on the other hand is the result of slowing down the free airstream, as in an air inlet.
The amount of drag that a certain object generates in an airflow is quantified in a drag coefficient. This coefficient expresses the ratio of the drag force to the force produced by the dynamic pressure times the area. Therefore, a  of 1 denotes that all air flowing onto the object will be stopped, while a theoretical 0 is a perfectly clean air stream.

![Pic]({{ site.url }}/images/Aero/i.png)

Drag can be understood in a very simple way. We know that vacuum attracts strongly due to the massive pressure difference generated. What happens in a F1 car is somewhat similar. As the air flows at high speed above and below the car a vacuum or a low pressure region is created directly behind the rear of the car. It is this vacuum that pulls the car opposite to its velocity and is what is known as drag. Also the bodywork and wings of the bend the air flowing above the car upwards slightly at various strategically located places in order to gain downforce. This also results in increased drag.

One of the several ways to counter drag that are used is to use the diffuser at the rear end of the car. The diffuser is almost like a venturimeter and works on identical principles like continuity theorem and Bernoulli’s principle. In the diffuser air at high speed suddenly flows into large vacant volume and hence its velocity decreases and pressure increases. Using this technique the effect of drag is decreased while maintaining the high downforce levels. Also there are vertical plates in the diffuser running parallel to each other acting as dividers to make the air flow in a linear way instead of the turbulent or swirling fashion so that we do not lose the effect just gained.

![Pic]({{ site.url }}/images/Aero/d.png)

Another mechanical way of reducing drag which is currently being used in F1 is the DRS or Drag Reduction System, in which the flaps of the rear open, i.e. rotate to position where they don’t face/obstruct the airflow but lie parallel to the flow allowing more air to pass unhindered through the rear wing instead of being routed upwards. This is applied on the straights where you definitely need less drag and high downforce is not so necessary. This system gives a speed advantage of about 30kmph alone. The rear wing remains closed in the corners and twisty parts of the circuit where high downforce is critical. 


![Pic]({{ site.url }}/images/Aero/e.png)


Downforce
Aerofoils in motorsports are often called wings, referring to aircraft wings. In fact they are very similar. F1 wings and winglets aim to generate high downforce, by having a high angle of attack, thus also increasing the drag of the aerofoil.
The evolution of aerofoils to what they are now is mainly thanks to the genious and research of a few well known scientists. In 1686, Sir Isaac Newton presented his three laws of motion, one of them being the conservation of energy. He stated that energy is constant in a closed system, although it can be converted from one type to another. Out of that theory, Daniel Bernouilli deducted a formula proving that the total energy in a steadily flowing fluid system is a constant along the flow path. An increase in the fluid’s speed must therefore be matched by a decrease in its pressure. Adding up the pressure variation times the area around the entire body determines the aerodynamic force on the body.
An aerofoil's operation can be easily explained when you consider a wing in a steady, laminar flow of air. As air is a gas, its molecules are free to move around and may have a different speed at different locations in the airstream. As downforce generating aerofoils(front wings) are mostly designed with more thickness on the lower side, that is they have more curved bottom side which results in the lower airstream having a slightly reduced cross-sectional area in surface, hence increasing the flow speed(according continuity theorem of flow) and decreasing the pressure. On top of the wing, the airspeed is lower, and thus the pressure difference will generate a downward force on the front wing helping in keeping the front end of the car stuck to ground even when it travels at a speed of 200mph.

![Pic]({{ site.url }}/images/Aero/f.png)

 Additionally, and in line with Newton's third law of motion, downforce wings are never straight and induce a new turning of the airflow. More specifically, the shape of the wing will turn air upwards and change its velocity. Such speed creates a net force on the body.

![Pic]({{ site.url }}/images/Aero/g.png)

Note that a velocity is a vectorial unit, having a speed and a direction component. So, to change of either of these components, you must impose a force. And if either the speed or the direction of a flow is changed, a force is generated. This is nothing more than a reaction force but a crucial contributor to the downforce none the less.
Now here comes the crucial aspect of optimising the downforce generated by the front wing. One way of increasing downforce is increasing the angle of attack but while by increasing the angle of attack the downforce increases, it comes at the cost of increased drag. Also the angle of attack can only be increased the upto a certain point beyond which we begin to have flow separation. Flow separation happens when the air has too low kinetic energy to follow/stick to the surface and it separates resulting in a loss of downforce. In modern F1 cars, one way in which engineers have found out to optimize this process is by using multielement wings instead of a single element wing. Multielement wing functions better as compared to a single element because we are continuously bringing in more and more new air flow streams into our aerodynamic system and thereby increasing the amount of air that flows underneath at high velocity which naturally results in increased downforce.    
It is very important to note that the turning of the fluid occurs because the molecules of the fluid stay in contact with the solid body since the molecules are free to move. Any part of the solid body can deflect a flow. Parts facing the oncoming flow are said to be windward, and parts facing away from the flow are said to be leeward. Both windward and leeward parts deflect a flow.
                                                   Downforce is however often explained by the "equal transit time" or "longer path" theory, stating that particles that split ahead of the aerofoil will join together behind it. In reality however, the speed difference of air particles above and below a wing is much larger than what is expected with this theory.

![Pic]({{ site.url }}/images/Aero/h.png)


From the front wing we come to body of the car and the rear end. Here, similarly a part of the air is made to bend around the curved underneath of the car while some amount of the above airstream is cleverly channelled inside the car for important cooling purpose and the rest is moved upward slightly creating downforce. So basically what we have here is air flowing at very high speed below the floor of the car. According to Bernoulli’s theorem, we have low pressure underneath the car and higher pressure(atmospheric pressure) above it. This pressure difference times the area computed over the entire surface give the total downforce on the car. This can be simply imagined in another way. We know that vacuum pulls strongly. So, what we try to do is create almost a vacuum type of thing below the car and this makes the car stick to track and very high levels of traction resulting in high level of control even at very high speeds.
Towards the rear end of the car we have the diffuser where the air flowing at high speed suddenly gets a greater volume to occupy and naturally expands and its velocity drops and hence the pressure increases. Think like a stream of gas flowing through a small tube suddenly coming out into a large open space and its velocity decreases as it diffuses into the volume. This increase in pressure at the rear end is used to counter drag as explained in the previous part.
While these simplified versions are the basics of lift and downforce generation, the reality can hardly be simplified and is a complex study, requiring high power computer systems. For a gas, we have to simultaneously conserve the mass, momentum, and energy in the flow. Hence, a change in the velocity of a gas in one direction results in a change in the velocity of the gas in a direction perpendicular to the original change. The simultaneous conservation of mass, momentum, and energy of a fluid (while neglecting the effects of air viscosity) are called the Euler Equations
after Leonard Euler. Several computer algorithms are based on these equations to make an approximation of the real situation.
Because of the complexity, today's Formula One cars are designed with CFD (computational fluid dynamics) and CAD (computer aided design) that allows engineers to design a car, and immediately simulate the airflow around it, incorporating environmental parameters like traction, wind speed and direction, and much more.






Author: Dipayan Sarkar
