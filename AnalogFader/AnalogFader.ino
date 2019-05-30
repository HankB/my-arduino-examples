/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - RGB LED
    common ground (long leg) attached to ground
    
    anode (short legs) attached acordingly
      red - digital output 11
      green - digital output 10
      blue - 9 (unused at present)

  Modified from a sketch
  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/

int sensorPin =   A0;   // select the input pin for the potentiometer
int redPin =      11;   // select the pin for the LED
int sensorValue = 0;    // variable to store the value coming from the sensor
int greenpin =    10;

int red_pct = 15;
int green_pct = 30;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(redPin, OUTPUT);
  pinMode(greenpin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin off:
  analogWrite(greenpin, ((sensorValue/4)*red_pct)/100);
  analogWrite(redPin, (255-sensorValue/4)*green_pct/100);
  // stop the program for for <sensorValue> milliseconds:
  delay(10);
}
