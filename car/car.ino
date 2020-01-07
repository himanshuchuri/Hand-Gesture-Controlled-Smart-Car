#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
int forward=0;
int backward=0;
int right=0;
int left=0;
void setup() 
{
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
 pinMode(A4,INPUT);
 pinMode(A5,INPUT);
 Serial.begin(9600);
 motor1.setSpeed(255);
 motor2.setSpeed(255);
 motor3.setSpeed(255);
 motor4.setSpeed(255);
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);
 
}
void loop() 
{
  forward=digitalRead(A2);
  backward=digitalRead(A3);
  right=digitalRead(A4);
  left=digitalRead(A5
  );
   if(forward==HIGH)
    {
     motor1.run(FORWARD);
     motor2.run(FORWARD);
     motor3.run(FORWARD);
     motor4.run(FORWARD);
     Serial.println("Forward");
    }
   if(backward==HIGH)
    {       
     motor1.run(BACKWARD);
     motor2.run(BACKWARD);
     motor3.run(BACKWARD);
     motor4.run(BACKWARD);
     Serial.println("Reverse");
    }
    if(right==HIGH)
     {
      motor1.run(RELEASE);
     motor2.run(RELEASE);
     motor3.run(FORWARD);
     motor4.run(FORWARD);
      Serial.println("RIGHT");
     }
     if(left==HIGH)
      {
       motor4.run(RELEASE);
     motor3.run(RELEASE);
     motor2.run(FORWARD);
     motor1.run(FORWARD);
       Serial.println("LEFT");
      }
   if(left==LOW&&right==LOW&&forward==LOW&&backward==LOW)
   {
      motor1.run(RELEASE);
     motor2.run(RELEASE);
      motor4.run(RELEASE);
     motor3.run(RELEASE);
   }
   delay(100);
}
