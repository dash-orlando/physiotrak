 /*
 * test
 */

 /*Madelene */

// Heart Rate Call auxiliary functions library
#include "MQTT_Functions.h"

//Heart Rate Call i2c library
#include <Wire.h>

//Heart Rate Call sparkfun Heartrate sensor library?
#include "MAX30105.h"
#include "heartRate.h"

// Useful defines.
#define BAUDRATE              115200                          // Serial communication baudrate

//HeartRate
MAX30105 particleSensor;

// Variables
//int buff; //Fluvio's buff

int irValue;

//HeartRate Variables 
const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good. 
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occured 
float beatsPerMinute;
int beatAvg;

// String def.
//String data_outString;
 

void setup() 
{

  Serial.begin( BAUDRATE );                                   // Start serial monitor

  /*  Connect to Wi-Fi and setup MQTT communications */
  setup_WiFi();                                               // Connect to WiFi
  MQTT_connect( 250 );                                        // Connecto to MQTT broker

//Heart Rate void setup
Serial.println("Initializing..."); 
//Initialize sensor
if (!particleSensor.begin(Wire, I2C_SPEED_FAST))//Use default I2C port, 400Hz speed
{
  Serial.println("MAX30105 was not found. Please check wiring/power. ");
  while (1);
}
Serial.println("Place your index finger on the sensor with steady pressure.");

particleSensor.setup(); //Configure sensor with default settings
particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running 
particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED 


} 
// end of setup loop...



void loop() {

  // connection stuff...
  if ( !mqtt.connected() )                                    // Ensure we are connected
    MQTT_connect( 125 );                                      // to MQTT server

  // do stuff with sensors here...

  int irValue = particleSensor.getIR();

  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
    /*Serial.print("IR=");
    Serial.print(irValue);
    Serial.print(",BPM= "); 
    Serial.print(beatsPerMinute);
    Serial.print(",Avg BPM=");
    Serial.print(beatAvg); */

    //data = irValue + beatsPerMinut + beatAvg; 
    
    Serial.printf("%d,%d,%d",irValue, beatsPerMinute, beatAvg); 
    

    if (irValue < 50000)
        Serial.print(" No finger?");
    
      Serial.println();
    }

  
  // connection stuff...
  if ( devOutput.publish( irValue) ) {                              // Make sure it publishes
    Serial.println( irValue);
  if (devOutput.publish (beatsPerMinute) ){
    Serial.println(beatsPerMinute);
  if ( devOutput.publish (beatAvg) ){
    Serial.println(beatAvg);
  }
  }
  } else {                                                          // In case it fails, disconnect from MQTT Server
    mqtt.disconnect();                                          // ...
  }
  

  delay( 10 );
}

  
