#include <VirtualWire.h>
char *controller;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(12);
  vw_setup(4000);
  vw_rx_start();  
}

void loop() {
  // put your main code here, to run repeatedly:
  controller = "1";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx();
  delay(2000);
}
