/*
  Project: Smart Blind Stick
  Date: 29th March, 2018
*/
#include <VirtualWire.h>

#define trigPin 9

#define echoPin 8


#define motor 7

#define buzzer 6

int moisture_status = 0;

void setup() {
  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(motor, OUTPUT);

  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(4000);  // Bits per sec

  vw_rx_start();       // Start the receiver PLL running
}


void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  long duration, distance;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    if ((buf[0] == '1')) {
      trigger();
    }
    /*if ((buf[0] == 'A') && (buf[1] == '1')) {
      trigger();
      Serial.println("Found stick");
      }*/
    //trigger();
    Serial.println("Data Received");
  }

  //
  //  digitalWrite(trigPin, LOW);
  //
  //  delayMicroseconds(2);
  //
  //  digitalWrite(trigPin, HIGH);
  //
  //  delayMicroseconds(10);
  //
  //  digitalWrite(trigPin, LOW);
  //
  //  duration = pulseIn(echoPin, HIGH);
  //
  //  //distance = (duration/2) / 29.1;
  //  distance = duration * 0.034 / 2;
  //
  //  if (distance  < 100)// This is where checking the distanceyou can change the value
  //
  //  {
  //    trigger();
  //  }
  //  else
  //
  //  {
  //
  //    digitalWrite(motor, LOW); // when greater than 100cm
  //
  //    digitalWrite(buzzer, LOW);
  //
  //  }
  //  delay(500);
  //  moisture();
}

void moisture() {
  /*
    output_value= analogRead(sensor_pin);

    output_value = map(output_value,550,0,0,100);
  */
  long output_value =  analogRead(A0);
  if (output_value < 1022) {
    moisture_status += 1;
    if (moisture_status >= 3) {
      trigger();
      moisture_status = 0;
    }
  }
}


void trigger() {
  digitalWrite(motor, HIGH); // When the the distance below 100cm

  digitalWrite(buzzer, HIGH);

  delay(500);

  digitalWrite(motor, LOW);

  digitalWrite(buzzer, LOW);

  delay(500);
}


