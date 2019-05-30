/*
   Play a tone and bump it up on button press. Repeat 
*/

static const int  lowTone = 31;
static const int  highTone = 4978;
static const int  tonePin = 8;
static const int  stepTime = 10;
static const int  stepSize = 15;
static const int  interNoteDelay = 3;

void setup() {
  // no setup needed
}

void loop() {
  for (int i = lowTone; i < highTone; i+=stepSize) {
    tone(tonePin, i);
    delay(stepTime);file:///home/hbarta/Documents/Arduino/MyCode/my-arduino-examples/ToneButton/pitches.h

    noTone(tonePin);
    delay(interNoteDelay);
  }
  delay(1000);
}
