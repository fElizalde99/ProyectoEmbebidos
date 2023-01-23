#include <Arduino.h>
#include <ESP32Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int pinservo1=32;
int pinservo2=25;
int pinservo3=26;
int pinservo4=27;
int pinservo5=33;


int pinPot5=12;


void setup()
{
   Serial.begin(9600);
   servo1.attach(pinservo1,610,2550);
   servo2.attach(pinservo2,670,2540);
   servo3.attach(pinservo3,660,2600);
   servo4.attach(pinservo4,660,2600);
   //servo5.attach(pinservo5,660,2600);
   servo5.attach(pinservo5,0,2600);


   pinMode(pinPot5,INPUT);

   servo1.write(0);
   servo2.write(0);
   servo3.write(0);
   servo4.write(0);
   servo5.write(0);

}

void loop()
{
   int value=analogRead(pinPot5);
   float value2= value/(4096.0)*100.0;
   //value2=map(value,0,1024,0,180);
   
   if(value2<=20){
      servo1.write(180);
      Serial.println(value2);
      servo2.write(0);
      servo3.write(0);
      servo4.write(0);
      servo5.write(0);
      delay(300);
   }

   if((value2>20) && (value2<=40)){
      servo2.write(180);
      Serial.println(value2);
      servo1.write(0);
      servo3.write(0);
      servo4.write(0);
      servo5.write(0);
      delay(300);
   }

   if((value2>40) && (value2<=60)){
      servo3.write(180);
      Serial.println(value2);
      servo2.write(0);
      servo1.write(0);
      servo4.write(0);
      servo5.write(0);
      delay(300);
   }

   if((value2>60) && (value2<=80)){
      servo4.write(180);
      Serial.println(value2);
      servo2.write(0);
      servo3.write(0);
      servo1.write(0);
      servo5.write(0);
      delay(300);
   }

   if((value2>80) && (value2<=100)){
      servo5.write(180);
      Serial.println(value2);
      servo2.write(0);
      servo3.write(0);
      servo4.write(0);
      servo1.write(0);
      delay(300);
   }

}