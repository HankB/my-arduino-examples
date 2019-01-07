/*
   Play a tone that ascends in frequency. Repeat
*/

static const int  lowTone = 31;
static const int  highTone = 4978;
static const int  tonePin = 8;
static const int  stepTime = 10;
static const int  stepSize = 5;
static const int  interNoteDelay = 3;

void setup() {
  // no setup needed
}

void loop() {
  for (int i = lowTone; i < highTone; i+=stepSize) {
    tone(tonePin, i);
    delay(stepTime);
    noTone(tonePin);
    delay(interNoteDelay);
  }
  delay(1000);
}
