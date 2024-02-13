const int screenPins[] = {2, 3, 4, 5, 6, 7, 8};

void turnOnSegment(int pins[], int index);

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(screenPins[i], OUTPUT);
  }
}

void loop() {
  int pot = analogRead(A0);
  int index = map(pot, 0, 1023, 0, 6);

  turnOnSegment(screenPins, index);
  delay(100);
}

// Turns on a specific segment and turns off other segments
void turnOnSegment(int pins[], int index) {
  for (int i = 0; i < 7; i++) {
    if (i == index) {
      digitalWrite(pins[i], HIGH);
    } else {
      digitalWrite(pins[i], LOW);
    }
  }
}
