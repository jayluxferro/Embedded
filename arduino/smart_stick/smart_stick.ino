/*
  Project: Smart Blind Stick
  Date: 29th March, 2018
  Receiver code
*/
#include <VirtualWire.h>

#define trigPin 9

#define echoPin 8

#define motor 7

#define buzzer 6

#define water_detect 5

void setup() {
  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(motor, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(water_detect, INPUT);
  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(12);
  vw_setup(4000);
  vw_rx_start();

}


void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    //int i;
    // Message with a good checksum received, dump it.
    Serial.println("Stick found... ");
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


