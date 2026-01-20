// file: main.cpp
//
// https://docs.espressif.com/projects/arduino-esp32/en/latest/esp-idf_component.html
//
// NOTE(s):
// --------
// * ESP-IDF + Arduino frameworks combination do not allow to use user definef function
//   -  void vApplicationIdleHook( void );
// * sdkconfig.esp32dev: select "CONFIG_AUTOSTART_ARDUINO"
//   - not set   run function app_main()

#include "Arduino.h"

// NOTE: Set following define to simulate setting in file
// "sdkconfig.esp32dev"
#define  CONFIG_AUTOSTART_ARDUINO  0   // 1=y, 0=not set

// -------------------------------------------------------------------------------------

#if CONFIG_AUTOSTART_ARDUINO

// Use functions defined in example file "arduino.cpp" !!!
#if 0 
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
#else  // CONFIG_AUTOSTART_ARDUINO not set

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

#endif  // CONFIG_AUTOSTART_ARDUINO
