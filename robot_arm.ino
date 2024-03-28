#include <SoftwareSerial.h>
#include <Servo.h>

#define servo1 1
#define servo2 2
#define servo3 3
#define servo4 4

Servo mservo1, mservo2, mservo3, mservo4;

int pos = 0;
char Incoming_value;
char usechar = '0';

SoftwareSerial Genotronex(10, 11);  //tx,rx

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  Genotronex.begin(9600);
  // put your setup code here, to run once:
  
  mservo1.attach(servo1); // 150-50
  mservo2.attach(servo2); // 0-180
  mservo3.attach(servo3); // 40-120
  mservo4.attach(servo4); // 0-35 

  //default servo position
  mservo1.write(100); //up-down
  mservo2.write(100); //left-right
  mservo3.write(80); //forward-back
  mservo4.write(0); //clamp
}

int srv1 = 100;
int srv2 = 100;
int srv3 = 80;
int srv4 = 0;

void loop() 
{

  if(Genotronex.available() > 0)  
  {
    Incoming_value = Genotronex.read();
    //Genotronex.print(usechar);
    usechar = Incoming_value;
  }
  
  if(usechar=='0')
  {
    
  }
  
  if(usechar==(char)65)  //UP(A)
  {
    while(srv1!=100)
    {
      srv1--;
      mservo1.write(srv1);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(5);
     }
  }
  
  if(usechar==(char)66)  //DOWN(B)
  {
    
    while(srv1!=150)
    {
      srv1++;
      mservo1.write(srv1);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(5);
     }
  }
  digitalWrite(LED_BUILTIN, LOW);

  if(usechar==(char)67)  //LEFT(C)
  {
    if(srv2<=180)
    {
      srv2++;
      mservo2.write(srv2);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(10);
     }
  }

  if(usechar==(char)73)   //Center(I)
  {
      if(srv2>100)
      {
        srv2--;
        mservo2.write(srv2);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(10);
      }
      
      if(srv2<100)
      {
        srv2++;
        mservo2.write(srv2);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(10);
      }
  }

  if(usechar==(char)68)   //RIGHT(D)
  {
    if(srv2>0)
    {
      srv2--;
      mservo2.write(srv2);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(10);
     }
  }

  if(usechar==(char)69)  //FORWARD(E)
  {
    if(srv3>40)
    {
      srv3--;
      mservo3.write(srv3);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(10);
     }
   }
   
   if(usechar==(char)74)  //Center 2(J)
   {
    if(srv3>80)
      {
        srv3--;
        mservo3.write(srv3);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(10);
      }
      
      if(srv3<80)
      {
        srv3++;
        mservo3.write(srv3);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(10);
      }
   }
   
   if(usechar==(char)70)  //BACKWARD(F)
   {
    if(srv3<105)
    {
      srv3++;
      mservo3.write(srv3);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(10);
     }
   }

   if(usechar==(char)71)  //HOLD(G)
  {
    if(srv4!=0)
    {
      srv4--;
      mservo4.write(srv4);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(2);
     }
   }
   
   if(usechar==(char)72)  //RELEASE(H)
   {
    if(srv4!=55)
    {
      srv4++;
      mservo4.write(srv4);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(2);
     }
   }
}
