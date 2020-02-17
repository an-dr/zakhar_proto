#include <Arduino.h>
#define BUILTIN_LED 13
int sensorPin = A0; // select the input pin
int sensorValue = 0; // variable to store the value coming from the sensor


// class ActientEye{

// }

void setup ()
{
 pinMode(BUILTIN_LED, OUTPUT); // Initialize the BUILTIN_LED pin as an output
 Serial.begin (9600);
}

void loop ()
{
 sensorValue = analogRead (sensorPin);
 Serial.println (sensorValue, DEC); //debug
 if(sensorValue <= 120)
 {
 digitalWrite (BUILTIN_LED, HIGH); //led off
 delay(1000);
 }
 digitalWrite (BUILTIN_LED, LOW); //led on - default
}