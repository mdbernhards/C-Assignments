const int BUTTON_PIN = A0;
const int LED_PIN = 7;
const int DEBOUNCE_TIME = 50;
const int LONG_PRESS = 1000;

long button_pressed_time();

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (button_pressed_time() < LONG_PRESS) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
}

/// Stateful function that returns the number of milliseconds the button was kept pressed
/// before it was released.
/// Returns a value once each time the button was released.
/// @return The time the button was kept pressed before it was released, in milliseconds, or -1 if no button release was detected since the last call to this function.
long button_pressed_time() {
  static int lastButtonState = HIGH;
  static unsigned long buttonPressStartTime = 0;
  static unsigned long timeOfLastChange = 0;
  static unsigned long buttonPressTime = 1001;

  bool buttonState = digitalRead(BUTTON_PIN);
  unsigned long currentTime = millis();

  if (buttonState != lastButtonState && (currentTime - timeOfLastChange > DEBOUNCE_TIME)) {
    if (buttonState == LOW) {
      buttonPressStartTime = currentTime;
    } else {
      buttonPressTime = currentTime - buttonPressStartTime;
    }

    timeOfLastChange = currentTime;
    lastButtonState = buttonState;
  }

  return buttonPressTime;
}