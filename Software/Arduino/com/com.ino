/*
 * test
 */

// Useful defines.
#define BAUDRATE              115200                          // Serial communication baudrate

// Call auxiliary functions library
#include "MqttFunctions.h"

void setup() {

  Serial.begin( BAUDRATE );                                   // Start serial monitor

  /*  Connect to Wi-Fi and setup MQTT communications */
  setup_WiFi();                                               // Connect to WiFi
  MQTT_connect( 250 );                                        // Connecto to MQTT broker

} // end of setup loop...

void loop() {

  // connection stuff...
  if ( !mqtt.connected() )                                    // Ensure we are connected
    MQTT_connect( 125 );                                      // to MQTT server

  // do stuff with sensors here...
  char    buff[156] = {'\0'};                                 // String buffer
  // connection stuff...
  if ( devOutput.publish( buff ) ) {                              // Make sure it publishes
    //Serial.println( buff );
    Serial.println("hola");// ...
  } else {                                                          // In case it fails, disconnect from MQTT Server
    mqtt.disconnect();                                          // ...
  }

  delay( 10 );
}
