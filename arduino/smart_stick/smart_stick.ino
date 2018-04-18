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

int moisture_status = 0;

void setup() {
  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(motor, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(water_detect, INPUT);
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("init failed");

}


void loop() {
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    int i;
    // Message with a good checksum received, dump it.
    Serial.print("Message: ");
    Serial.println((char*)buf);
    trigger(500);
  }
  long duration, distance;

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  //distance = (duration/2) / 29.1;
  distance = duration * 0.034 / 2;

  //Serial.println(distance);
  if (distance  < 100)// This is where checking the distanceyou can change the value

  {
    trigger(distance * 10);
    //Serial.println(distance);
  }
  else

  {

    digitalWrite(motor, LOW); // when greater than 100cm

    digitalWrite(buzzer, LOW);

  }
  delay(500);

  //Serial.println(digitalRead(water_detect));
  //Serial.println(distance);
  //Serial.println(moisture());
  moisture(500);
}

void moisture(int distance) {
  /*
    output_value= analogRead(sensor_pin);

    output_value = map(output_value,550,0,0,100);
  */
  //Serial.println(analogRead(A0));

  //return;
  long output_value =  analogRead(A0);
  if (output_value < 500) {
    trigger(distance);
  }
}


void trigger(int timeout) {
  digitalWrite(motor, HIGH); // When the the distance below 100cm

  digitalWrite(buzzer, HIGH);

  delay(timeout);

  digitalWrite(motor, LOW);

  digitalWrite(buzzer, LOW);

  delay(timeout);
}


