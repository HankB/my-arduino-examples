/* from https://www.electronicshub.org/arduino-pir-sensor-tutorial/
 *  PIR Demo with speaker and LED output.
 *  Now drives a speaker and both speaker and LED reflect PIR input state
 *  
  */
int speaker = 11;
int sensor = 8;
int led = 13;

void setup() 
{
  pinMode(speaker, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(speaker,LOW);
  digitalWrite(sensor,LOW); // disable pullup
  
  digitalWrite(led,LOW);

  // delay while PIR calibrates
  while(millis()<13000) {
    digitalWrite(led,HIGH);
    delay(50);
    digitalWrite(led,LOW);
    delay(50);
  }
}

void loop() 
{
  static bool prevSpeaker = false;
  static bool prevPIR = false;

  delay(1); // delay one ms
  if(prevPIR) { // was previously high?
    if(digitalRead(sensor)==HIGH) { // still high?
     digitalWrite(speaker,prevSpeaker?HIGH:LOW);  // toggle speaker output
     prevSpeaker = !prevSpeaker;
    } else {
      prevPIR = false;
      digitalWrite(led,LOW);  // speaker and LED off
      digitalWrite(speaker,LOW);
    }
  } else {
    if(digitalRead(sensor)==HIGH) {
      prevPIR = true;
      digitalWrite(led,HIGH);  // LED on
    }
  }
}
