const int ON_BUTTON_PIN = A0;
const int OFF_BUTTON_PIN = A1;
const int LED_PIN = 7;
const int DEBOUNCE_TIME = 50;

bool on_button_pressed();
bool off_button_pressed();
bool button_pressed();

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(ON_BUTTON_PIN, INPUT_PULLUP);
    pinMode(OFF_BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if(on_button_pressed()) {
    digitalWrite(LED_PIN, HIGH);
  }

  if(off_button_pressed()) {
    digitalWrite(LED_PIN, LOW);
  }
}

/// Stateful function to detect whether the ON button was pressed.
/// Returns true once for each time the button was pressed, false otherwise.
/// @return true if a new button press was detected since the last call to this function, false otherwise
bool on_button_pressed() {
  return button_pressed(ON_BUTTON_PIN);
}

/// Stateful function to detect whether the OFF button was pressed.
/// Returns true once for each time the button was pressed, false otherwise.
/// @return true if a new button press was detected since the last call to this function, false otherwise
bool off_button_pressed() {
  return button_pressed(OFF_BUTTON_PIN);
}

// Detects whether a button has been pressed
bool button_pressed(int pin) {
  static unsigned long time_of_last_change = 0;
  static int button_state = HIGH;
  const unsigned long current_time = millis();
  const int new_state = digitalRead(pin);

  if (button_state != new_state && (current_time - time_of_last_change > DEBOUNCE_TIME)) {
    time_of_last_change = current_time;
    button_state = new_state;
    if (button_state == LOW) {
      return true;
    }
  }

  return false;
}
