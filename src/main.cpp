// file: main.cpp
//
// https://docs.espressif.com/projects/arduino-esp32/en/latest/esp-idf_component.html
//
// NOTE(s):
// ESP-IDF + Arduino frameworks combination do not allow to use user definef function
// - void vApplicationIdleHook( void );

#include "Arduino.h"


#if 1

extern "C" void app_main()
{
  initArduino();

  // Arduino-like setup()
  setup();

  // Arduino-like loop()
  while( true )
  {
    loop();
  }
  // WARNING: if program reaches end of function app_main() the MCU will restart.
}

#else

void setup()
{
  Serial.begin( 115200 );
  while( !Serial )
  {  // wait for serial port to connect
  }
  Serial.println("setup");
}


void loop()
{
    delay( 1000 );
    Serial.println( "loop" );
}

#endif
