
#include <Servo.h>
Servo scan_servo;
int trig = 2;
int echo = 3;
int wheel_1_f = 5;
int wheel_1_b = 6;
int wheel_2_b = 7;
int wheel_2_f = 8;
int enable1 = 9;
int enable2 = 10;
int gripper_up = 11;
int gripper_down =12;
int gripper1 = 13;
int gripper2 = A0;
int gripper_up = 11;
int gripper_down =12;

unsigned long distance,duration;
int pos,pos1,pos_mod;
int pos2 = pos1 - 90;
int t_pos ;
int t_pos1;
int t_dist;
int dist[15];
int min_dist;
int i = 0;


void setup()
{
pinMode(trig, OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
scan_servo.attach(4);
pinMode(wheel_1_f, OUTPUT);
pinMode(wheel_1_b, OUTPUT);         	//motors controlling motion
pinMode(wheel_2_b, OUTPUT);
pinMode(wheel_2_f, OUTPUT);

pinMode(gripper_up,OUTPUT);
pinMode(gripper_down,OUTPUT);       	//gripper motors
pinMode(gripper1,OUTPUT);
pinMode(gripper2,OUTPUT);

pinMode(enable1,OUTPUT);
pinMode(enable2,OUTPUT);
digitalWrite(enable1,LOW);         	//speed control  enable 1 = pin 1 of L293D
digitalWrite(enable1,LOW);         	//enable 2 = pin 9 of L293D



digitalWrite(wheel_1_f,LOW);
digitalWrite(wheel_1_b,LOW);
digitalWrite(wheel_2_b,LOW);
digitalWrite(wheel_2_f,LOW);
digitalWrite(gripper_up,LOW);
digitalWrite(gripper_down,LOW);
digitalWrite(gripper1,LOW);
digitalWrite(gripper2,LOW);
digitalWrite(4,LOW);
digitalWrite(1,LOW);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(enable1,LOW);
digitalWrite(enable2,LOW);
}

void loop()
{                                   	//void loop starts here

//scanning starts here
pos = 20;
min_dist = 200;
for (int i=0;i<15;i++)
{
scan_servo.write(pos);
delay(300);                              	//the sensor must be static for proper reading
digitalWrite(trig, LOW);                 	//ultrasonic code stsrts here
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duration =  pulseIn(echo, HIGH,8000);
distance = (duration / 2) / 29.1;         	//ultrasonic code ends here
dist[i] = distance;
Serial.print(i);
Serial.print("   ");

if(dist[i] == 0)
{
dist[i] = 200;                         	// ignoring the area where there are no objects
}

Serial.print("distance :  ");
Serial.print(dist[i]);
Serial.print("   position:  ");
Serial.println(pos);

if(dist[i] < min_dist)
{
min_dist = dist[i];
pos1 = i*10 + 20;
}
pos = pos + 10;
}                                          	// for loop ends here
Serial.print ("minimum distannce :	");
Serial.print (min_dist);
Serial.print ("   position	");
Serial.println (pos1);
scan_servo.write(pos1);
delay(2000);                                          	//servo will point towards the detected object




// bot directing itself towards the object

if(min_dist>8)                                    	//if(min_dist>8) starts here
{

if(pos1>95)
{
digitalWrite(wheel_1_f,LOW);
digitalWrite(wheel_1_b,LOW);
digitalWrite(wheel_2_f,LOW);
digitalWrite(wheel_2_b,LOW);

pos2 = pos1 - 90;
t_pos1 = pos2*7;
digitalWrite(4,LOW);

analogWrite(enable1,255);           	//255  is arbitrary proper calibration is needed
analogWrite(enable2,255);           	//255  is arbitrary proper calibration is needed
Serial.println("turning right..................");
digitalWrite(wheel_1_f,HIGH);
digitalWrite(wheel_1_b,LOW);
digitalWrite(wheel_2_f,LOW);
digitalWrite(wheel_2_b,HIGH);
delay(t_pos1);                                              	// t will be functon of positio or use if() and put conditions of position
digitalWrite(wheel_1_f,LOW);
digitalWrite(wheel_1_b,LOW);
digitalWrite(wheel_2_f,LOW);
digitalWrite(wheel_2_b,LOW);
}

if(pos1 <85)
{
/*
//scan continuously
digitalWrite(wheel_1_f,LOW);
digitalWrite(wheel_1_b,LOW);
digitalWrite(wheel_2_f,LOW);
digitalWrite(wheel_2_b,LOW);
pos = 20;
min_dist = 200;
for (int i=0;i<15;i++)
{
scan_servo.write(pos);
delay(200);                              	//the sensor must be static for proper reading
digitalWrite(trig, LOW);                 	//ultrasonic code stsrts here
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duration =  pulseIn(echo, HIGH,8000);
distance = (duration / 2) / 29.1;         	//ultrasonic code ends here
dist[i] = distance;
Serial.print(i);
Serial.print("   ");

if(dist[i] == 0)
{
dist[i] = 200;                         	// ignoring the area where there are no objects
}

Serial.print("distance :  ");
Serial.print(dist[i]);
Serial.print("   position:  ");
Serial.println(pos);

if(dist[i] < min_dist)
{
min_dist = dist[i];
pos1 = i*10 + 20;
}
pos = pos + 10;
}                                          	// for loop ends here
Serial.print ("minimum distannce :	");
Serial.print (min_dist);
Serial.print ("   position	");
Serial.println (pos1);
scan_servo.write(pos1);
delay(2000);                                          	//servo will point towards the detected object



digitalWrite(4,LOW);
pos2 = 90-pos1;
t_pos1 = pos2*7;

analogWrite(enable2,255);           	//255  is arbitrary proper calibration is needed
analogWrite(enable1,255);           	//255  is arbitrary proper calibration is needed

Serial.println("turning left..................");
digitalWrite(wheel_1_f,LOW);
digitalWrite(wheel_1_b,HIGH);                                     	//working properly
digitalWrite(wheel_2_f,HIGH);
digitalWrite(wheel_2_b,LOW);
delay(t_pos1);
digitalWrite(wheel_1_f,LOW);
digitalWrite(wheel_1_b,LOW);
digitalWrite(wheel_2_f,LOW);
digitalWrite(wheel_2_b,LOW);
}



pos2 = pos1-90;
pos_mod = abs(pos2);

if(pos_mod<6)

{
Serial.print("abs check   ");
Serial.println(pos1);
t_dist = min_dist*40;
digitalWrite(4,LOW);
Serial.print (t_dist);
Serial.println("moving forward..................");
digitalWrite(wheel_1_b,HIGH);
digitalWrite(wheel_1_f,LOW);
digitalWrite(wheel_2_b,HIGH);
digitalWrite(wheel_2_f,LOW);
delay(t_dist);                             	// t  =  time require for the bot to reach near the bot
digitalWrite(wheel_1_f,LOW);
digitalWrite(wheel_1_b,LOW);
digitalWrite(wheel_2_f,LOW);
digitalWrite(wheel_2_b,LOW);
}

/*if(pos1== 90)
{
pos2 = pos1-90;
pos_mod = abs(pos2);
Serial.print("abs check   ");
Serial.println(pos_mod);
t_dist = min_dist*35;
digitalWrite(4,LOW);
Serial.println("moving forward..................");
digitalWrite(wheel_1_b,LOW);
digitalWrite(wheel_1_f,HIGH);
digitalWrite(wheel_2_b,LOW);
digitalWrite(wheel_2_f,HIGH);
delay();                             	// t  =  time require for the bot to reach near the bot
digitalWrite(wheel_1_f,LOW);
digitalWrite(wheel_1_b,LOW);
digitalWrite(wheel_2_f,LOW);
digitalWrite(wheel_2_b,LOW);
}
*/
}                    	//if (min_dist < 8 ends here)



/*
if(min_dist<8)
{
// bot has reached the object

//starting the griping action

digitalWrite(4,LOW);
digitalWrite(wheel_1_f,LOW);
digitalWrite(wheel_1_b,LOW);
digitalWrite(wheel_2_f,LOW);
digitalWrite(wheel_2_b,LOW);

Serial.print ("starting gripping action");


digitalWrite(gripper_up,HIGH);
digitalWrite(gripper_down,LOW);
delay(300);                             	//gripper comes down
digitalWrite(gripper_up,LOW);
digitalWrite(gripper_down,LOW);

digitalWrite(gripper2,HIGH);
digitalWrite(gripper1,LOW);
delay(300);                     	// gripper closes
digitalWrite(gripper1,LOW);
digitalWrite(gripper2,LOW);

digitalWrite(gripper_up,LOW);
digitalWrite(gripper_down,HIGH);
delay(300);
digitalWrite(gripper_up,LOW);
digitalWrite(gripper_down,LOW);         	//gripper comes up

}
*/
}
`                                   	//  void loop ends her
