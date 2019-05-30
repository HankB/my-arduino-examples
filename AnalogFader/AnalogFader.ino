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

  Further modified to use the levels intended for automotive voltage evaluation

*/

const int high = 1000;
const int good = 921;
const int marginal = 887;
const int bad = 682;
const int spread = good - bad;

int sensorPin =   A0;   // select the input pin for the potentiometer
int redPin =      11;   // select the pin for the LED
int sensorValue = 0;    // variable to store the value coming from the sensor
int greenpin =    10;

const int red_pct = 50;
int green_pct = 50;
int max_DAC   = 255;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(redPin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  //Serial.begin(9600);

}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  if(sensorValue >= good) {
    analogWrite(greenpin, (max_DAC*green_pct)/100);
    analogWrite(redPin, 0);
    //Serial.print("good ");
    //Serial.println(sensorValue);
    }
  else if(sensorValue < bad) {
    analogWrite(greenpin, 0);
    analogWrite(redPin, (max_DAC*red_pct)/100);
    //Serial.print("bad ");
    //Serial.println(sensorValue);
  }
  else {
    int blend = (sensorValue-bad)*100/spread;  // calculate blend percent
    analogWrite(greenpin, blend*max_DAC/100*green_pct/100);
    analogWrite(redPin, (100-blend)*max_DAC/100*red_pct/100);
    /*
    Serial.print("between ");
    Serial.print(sensorValue);
    Serial.print(" "); Serial.print(blend);
    Serial.print(" green "); Serial.print(blend*max_DAC/100);
    Serial.print(" red "); Serial.println((max_DAC*(100-blend))/100);
    */
  }
  delay(10);
}
