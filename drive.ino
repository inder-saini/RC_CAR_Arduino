char t;
 
void setup() {
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors reverse
pinMode(10,OUTPUT);   //right motors forward

Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(10,LOW);
}
 
else if(t == 'L'){      //turn left 
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW); 
}
 
else if(t == 'R'){      //turn right 
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(10,LOW);
}

 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
delay(100);
}
