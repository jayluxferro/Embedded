/*
  Project: Smart Blink Stick
 Date:    29th March, 2018
 Transmitter
 */

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0; 

void setup()
{
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);   // Debugging only
  if (!driver.init())
    Serial.println("init failed");
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // send data
    Serial.println("Finding smart blind stick...");
    
    const char *msg = "Find stick!";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);    
  }
}


