// file: main.cpp
//
// https://docs.espressif.com/projects/arduino-esp32/en/latest/esp-idf_component.html
//
#include "Arduino.h"



#if 1

extern "C" void app_main()
{
  initArduino();

  // Arduino-like setup()
  Serial.begin(115200);
  while( !Serial )
  {
    ; // wait for serial port to connect
  }

  // Arduino-like loop()
  while(true)
  {
    Serial.println("loop");
  }

  // WARNING: if program reaches end of function app_main() the MCU will restart.
}

#else

void setup() {
  Serial.begin(115200);
  while(!Serial){
    ; // wait for serial port to connect
  }
}

void loop() {
    Serial.println("loop");
    delay(1000);
}

#endif
