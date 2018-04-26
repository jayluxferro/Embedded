#include <VirtualWire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(8);
  vw_setup(4000);
  vw_rx_start();  
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if(vw_get_message(buf, &buflen)){
     Serial.println("Data received");
    }
}
