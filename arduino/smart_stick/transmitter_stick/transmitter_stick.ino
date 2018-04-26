/*
  Project: Smart Blink Stick
 Date:    29th March, 2018
 Transmitter
 */

#include <VirtualWire.h>

const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0; 
char *controller;
void setup()
{
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);   // Debugging only
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(12);
  vw_setup(4000);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // send data
    controller = "1";
    vw_send((uint8_t *)controller, strlen(controller));
    vw_wait_tx();
    delay(2000);
    Serial.println("Searching for stick");
  }
}


