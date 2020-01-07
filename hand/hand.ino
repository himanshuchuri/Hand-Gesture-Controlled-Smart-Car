int x_axis = 0;
int y_axis = 0;
int forward = 9;
int backward = 10;
int right = 11;
int left = 12;
void setup()
{
 pinMode(A0, INPUT);      //X-Axis
 pinMode(A3, INPUT);     //Y-Axis
 pinMode(forward, OUTPUT);    //HIGH to move Forward
 pinMode(backward, OUTPUT);   //HIGH to move Backward
 
 pinMode(right, OUTPUT);      //HIGH to move Right
 pinMode(left, OUTPUT);       //HIGH to move Left
 Serial.begin(9600);
}
void loop()
{
 x_axis = analogRead(A0);
 y_axis = analogRead(A3);
 Serial.print(" X = ");
 Serial.println(x_axis);
 Serial.print(" Y = ");
 Serial.println(y_axis);
 if (y_axis >= 390)
 {
   Serial.println("Forward");
   digitalWrite(forward, HIGH);
 }
 else
 {
   if (y_axis <= 310)
   {
     Serial.println("BACK");
     digitalWrite(backward, HIGH);
   }
   else
   {
     if (x_axis >= 380)
     {
       Serial.println("RIGHT");
       digitalWrite(right, HIGH);
     }
     else
     {
       if (x_axis <= 320)
       {
         Serial.println("LEFT");
         digitalWrite(left, HIGH);
       }
       Serial.println(" ");
     }
   }
 }
 delay(200);
 if (x_axis > 320 && x_axis < 380 && y_axis > 310 && y_axis < 390)
 {
   digitalWrite(forward, LOW);
   digitalWrite(backward, LOW);
   digitalWrite(right, LOW);
   digitalWrite(left, LOW);
 }
}
