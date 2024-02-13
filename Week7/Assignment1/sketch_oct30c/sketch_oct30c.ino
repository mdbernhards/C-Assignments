const int screenPins[] = {2, 3, 4, 5, 6, 7};
int mainPin = 0;
bool toRight = true;

void setLeds();
void manageDirection();

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(screenPins[i], OUTPUT);
  }
}

void loop() {
  int pot = analogRead(A2);
  int interval = 100;
  int speed = map(pot, 0, 1023, 0, 20);

  if (speed != 0) {
    setLeds();
    manageMainPin();
    
    interval = 1000 / speed;
  }

  delay(interval);
}

// Turns on and off led's based on the direction and the main pin
void setLeds() {
  if (toRight && mainPin >= 2){
    digitalWrite(screenPins[mainPin - 2], LOW);
    digitalWrite(screenPins[mainPin - 1], HIGH);
  } else if (!toRight && mainPin <= 3) {
    digitalWrite(screenPins[mainPin + 2], LOW);
    digitalWrite(screenPins[mainPin + 1], HIGH);
  }
  
  digitalWrite(screenPins[mainPin], HIGH);
}

// Increments the main pin location and changes direction if required
void manageMainPin() {
  if (mainPin < 0) {
    toRight = true;
  } else if (mainPin > 5) {
    toRight = false;
  }

  if (toRight) {
    mainPin++;
  } else {
    mainPin--;
  }
}
