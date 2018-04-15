/*
  Project: Smart Blind Stick
 Date: 29th March, 2018
 */
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

#define trigPin 9

#define echoPin 8


#define motor 7

#define buzzer 6

RH_ASK driver;

#define water_detect 5

void setup(){
  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(motor, OUTPUT);

  pinMode(buzzer,OUTPUT);
  pinMode(water_detect, INPUT);
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("init failed");

}


void loop(){
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    int i;
    // Message with a good checksum received, dump it.
    Serial.print("Message: ");
    Serial.println((char*)buf);    
    trigger();    
  }
  long duration, distance;

  digitalWrite(trigPin, LOW); 

  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); 

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  //distance = (duration/2) / 29.1;
  distance= duration*0.034/2;

  if (distance  < 100)// This is where checking the distanceyou can change the value

  { 
     trigger();
  } 
  else

  {

    digitalWrite(motor,LOW);// when greater than 100cm

    digitalWrite(buzzer,LOW); 

  } 
  delay(500);

  //Serial.println(digitalRead(water_detect));
  //Serial.println(distance);
  //Serial.println(moisture());
  moisture();
}

void moisture(){
  /*
    output_value= analogRead(sensor_pin);
   
   output_value = map(output_value,550,0,0,100);
   */
  long output_value =  analogRead(A0);
  if(output_value < 1022){
     trigger(); 
  }
}


void trigger(){
    digitalWrite(motor,HIGH); // When the the distance below 100cm

    digitalWrite(buzzer,HIGH);

    delay(500);

    digitalWrite(motor, LOW);

    digitalWrite(buzzer, LOW);

    delay(500);
}


