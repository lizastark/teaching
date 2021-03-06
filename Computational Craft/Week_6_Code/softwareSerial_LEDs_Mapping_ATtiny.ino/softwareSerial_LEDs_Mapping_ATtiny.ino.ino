/*
 *
 * Software Serial with the ATtiny
 *
 * This sketch reads analog values coming in from the ATtiny, maps
 * them to usable values, prints the values to the serial monitor,
 * then writes the value to an LED.
 *
 * Be sure to read the full pinout when working with analog input:
 * http://highlowtech.org/wp-content/uploads/2011/10/ATtiny45-85.png
 *
 * Fall 2016
 * Computational Craft //MFADT Parsons
 *
 * CREDITS:
quitmeyer
https://github.com/quitmeyer/ATtinyBareDemos/blob/master/ATTinyAnalogInputTOSerial/ATTinyAnalogInputTOSerial.ino

Takes an input on the AtTiny85 from the VERY TRICKY analogue input pin 2 (as labeled in HLT tutorial)
and outputs these with Software serial to the arduino uno, or Duemillanove
Hookup
ATTINY85/45 pin 3 -> Arduino Uno pin 0
ATTINY85/45 pin 4 -> Arduino Uno pin 1

Basically uses the Arduino's brains to for serial communication.

 */


#include <SoftwareSerial.h>
// Definitions
#define rxPin 3
#define txPin 4

SoftwareSerial mySerial(rxPin, txPin);

int sensorPin = 7; //ACTUALLY PIN LABELED AS "2" on the HLT tutorial
int sensorVal = -1;
int newSensorValue;
int ledPin = 1;


// the setup routine runs once when you press reset:
void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  mySerial.begin(9600);
}

// the loop routine runs over and over asensorpingain forever:
void loop() {
  // read the value from the sensor:
  sensorVal = analogRead(sensorPin);

  //map the values to something usable - change these accordingly
  //map(value, fromLow, fromHigh, toLow, toHigh)
  newSensorValue = map(sensorValue, 0, 1023, 0, 255);

  //write the new value to the LED
  analogWrite(ledPin, newSensorValue);

  //print the new value to the serial monitor
  mySerial.print("newSensorValue = ");
  mySerial.println(newSensorValue);

}

