const int screenPins[] = {2, 3, 4, 5, 6, 7, 8};

void turnOnSegment(int pins[], int index);

void setup() {
    for (int i = 0; i < 7; i++) {
    pinMode(screenPins[i], OUTPUT);
  }
}

void loop() {
    int pot = analogRead(A0);
    int index = map(pot, 0, 1024, 0, 7);
    
    digitalWrite(9, HIGH);
    digitalWrite(2, HIGH);
    turnOnSegment(screenPins, index);
    delay(100);

}

void turnOnSegment(int pins[], int index)
{
    for (int i = 0; i < 7; i++) {
      if (pins[i] == index) {
        digitalWrite(pins[i], HIGH); // Turn on the selected segment
      } else {
        digitalWrite(pins[i], LOW); // Turn off other segments
      }
  }
}
