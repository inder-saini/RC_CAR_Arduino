#include <Arduino.h>
#include <Wire.h>
#include <HMC5883L_Simple.h>

// Create a compass
HMC5883L_Simple Compass;
String D;
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  Wire.begin();

  Compass.SetDeclination(10, 17, 'W');  //Declination for TORONTO, CANADA

  Compass.SetSamplingMode(COMPASS_SINGLE);

  Compass.SetScale(COMPASS_SCALE_130);
  
  Compass.SetOrientation(COMPASS_HORIZONTAL_Y_NORTH);
  
}


void loop() { 
 bluetooth();
}

void bluetooth(){
  while(Serial.available()){
    {
     D = Serial.readStringUntil('\n');
    Serial.println(D);
  }
int  bVal = D.toInt();
  switch(bVal){
    case 1:
         Serial.println("Forward");
         Forward();
         break;
    case 2:
         Serial.println("Backward");
         Backward();
         break; 
    case 3:
         Serial.println("Stop");
         Stop();
         break; 
    case 4:
         Serial.println("North");
         northDirection();
         break;
    case 5:
         Serial.println("South");
         southDirection();
         break; 
    case 6:
         Serial.println("East");
         eastDirection();
         break;
    case 7:
         Serial.println("West");
         westDirection();
         break; 
    case 8:
         Serial.println("heading: \t");
         int head = getCompass();
         Serial.println(head);
         break;
  }
  }
}
int getCompass(){
  int heading = Compass.GetHeadingDegrees();
  return heading;
}

void Forward(){
  digitalWrite(13,HIGH);
  digitalWrite(10,HIGH);
}
void Backward(){
    digitalWrite(13,LOW);
    digitalWrite(10,LOW);
  int temp = Compass.GetHeadingDegrees();
  const int currentDirection = temp;
  int forBackward;
  Serial.println("Current Direction of the car is: \t");
  Serial.println(currentDirection);
  delay(1000);

  if (currentDirection <180){
    forBackward = currentDirection+180;
  }else {
    forBackward = currentDirection-180;
  }
  Serial.println("Backward Direction of the car is: \t");
  Serial.println(forBackward);
  delay(1000);
   while(1){
    digitalWrite(10,HIGH);
    delay(800);
    int temp2 = Compass.GetHeadingDegrees();
    Serial.println(temp2);
      if((temp2 <= forBackward+10 && temp2 >= forBackward-10)){
    digitalWrite(10,LOW);
    break;
   }
   }
   }
   

   void Stop(){
    digitalWrite(13,LOW);
    digitalWrite(10,LOW);
   }
 
 void northDirection(){
    digitalWrite(13,LOW);
    digitalWrite(10,LOW);
int temp = Compass.GetHeadingDegrees();
     if(temp >= 180){
        digitalWrite(13,HIGH);
      }
      else if(temp<180){
        digitalWrite(10,HIGH);
      }

    while(1){
      int temp2 = Compass.GetHeadingDegrees();
      if(temp2 <= 5 || temp2 >=355){
       digitalWrite(13,LOW);
       digitalWrite(10,LOW);
       Serial.println("We are facing the north direction");
       break;
      } } }

  void southDirection(){
    digitalWrite(13,LOW);
    digitalWrite(10,LOW);
int temp = Compass.GetHeadingDegrees();
Serial.println(temp);
     if(temp >= 190){
        digitalWrite(10,HIGH);
      }
      else if(temp<170){
        digitalWrite(13,HIGH);
      }
    while(1){
      int temp2 = Compass.GetHeadingDegrees();
      if(temp2 <= 190 && temp2 >=170){
       digitalWrite(13,LOW);
       digitalWrite(10,LOW);
       Serial.println("This is the temp2 in south: \t");
       Serial.println(temp2);
       Serial.println("We are facing the South direction");
       break;
      }
    }
 }

  void eastDirection(){
  
    digitalWrite(13,LOW);
    digitalWrite(10,LOW);

int temp = Compass.GetHeadingDegrees();
Serial.println(temp);
     if(temp > 100){
        digitalWrite(10,HIGH);
      }
      else if(temp<80){
        digitalWrite(13,HIGH);
      }
     

    while(1){
      int temp2 = Compass.GetHeadingDegrees();
      if(temp2 <= 100 && temp2 >=80){
       digitalWrite(13,LOW);
       digitalWrite(10,LOW);
       Serial.println("We are facing the East direction");
       break;
      }
    }
 }

   void westDirection(){
  
    digitalWrite(13,LOW);
    digitalWrite(10,LOW);

int temp = Compass.GetHeadingDegrees();
Serial.println(temp);
     if(temp > 280){
        digitalWrite(10,HIGH);
      }
      else if(temp<260){
        digitalWrite(13,HIGH);
      }

    while(1){
      delay(500);
      int temp2 = Compass.GetHeadingDegrees();
      Serial.println(temp2);
      if(temp2 <= 280 && temp2 >= 260){
       digitalWrite(13,LOW);
       digitalWrite(10,LOW);
       Serial.println("We are facing the West direction");
       break;
      }
    }
 }
