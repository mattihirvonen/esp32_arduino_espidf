// File: arduino.cpp

#include "Arduino.h"


void setup( void )
{
  Serial.begin( 115200 );
  while( !Serial )
  {   // wait for serial port to connect
  }
  delay( 100 );
  Serial.println("");
  Serial.println("setup");
}


void loop( void )
{
    static int  counter = 0;
    static int  run = 0;
    static char s[64];      // Save stack space

    if ( !run ) {
        run = 1;
        snprintf(s, sizeof(s), "%s : Running on core %i (priority %i)",
                    __func__, xPortGetCoreID(), uxTaskPriorityGet(NULL) );

        Serial.println(s);
    }
    delay( 1000 );
    Serial.print( "loop " );
    Serial.println( ++counter );
}
