const int screenPins[] = {2, 3, 4, 5, 6, 7, 8};
const int Interval = 500;
const int buttonOnePin = A0;
const int buttonTwoPin = A1;
const int DEBOUNCE_TIME = 100;

void blink_segment(int segment, int duration);
void set_segments(bool segments[]);
bool toggle_button_pressed();
bool select_button_pressed();
bool button_pressed(int pin);

void setup() {
  pinMode(buttonOnePin, INPUT_PULLUP);
  pinMode(buttonTwoPin, INPUT_PULLUP);

  for (int i = 0; i < 7; i++) {
    pinMode(screenPins[i], OUTPUT);
  }
}

void loop() {
  static int index = 0;
  static bool segments[7] = {0};

  if (select_button_pressed()) {
    index++;

    if (index > 6) {
      index = 0;
    }
  }

  if (toggle_button_pressed()) {
    if (segments[index] == 0) {
      segments[index] = true;
    } else {
      segments[index] = false;
    }
  }
  
  set_segments(segments);
  blink_segment(index, Interval);
}

/// Stateful function that blinks the selected segment by toggling it on/off.
/// Keeps track of the time that has elapsed since the last toggle, and of the current state of the segment.
/// Does nothing when called in the time between the last toggle and the next toggle.
/// @param segment The segment (0..6) to toggle on/off
/// @param duration The duration of the blink in milliseconds
void blink_segment(int segment, int duration) {
  static bool LED_is_on = false;
  static unsigned long time_of_last_change = 0;
  const unsigned long current_time = millis();

  if (current_time - time_of_last_change > Interval) {
    time_of_last_change = current_time;
    LED_is_on = !LED_is_on;

    if (LED_is_on) {
      digitalWrite(screenPins[segment], HIGH);
    }
    else { 
      digitalWrite(screenPins[segment], LOW);
    }
  }
}

// Turns on leds based on segments array 
void set_segments(bool segments[]) {
  static unsigned long time_of_last_change = 0;
  const unsigned long current_time = millis();

  if (current_time - time_of_last_change > Interval) {
    time_of_last_change = current_time;

    for (int i = 0; i < 7; i++) {
      digitalWrite(screenPins[i], segments[i] == true ? HIGH : LOW);
    }
  }
}

/// Stateful function to detect whether the TOGGLE button was pressed.
/// Returns true once for each time the button was pressed, false otherwise.
/// @return true if a new button press was detected since the last call to this function, false otherwise
bool toggle_button_pressed() {
  return button_pressed(buttonTwoPin);
}

/// Stateful function to detect whether the SELECT button was pressed.
/// Returns true once for each time the button was pressed, false otherwise.
/// @return true if a new button press was detected since the last call to this function, false otherwise
bool select_button_pressed() {
  return button_pressed(buttonOnePin);
}

// Detects whetether a button has been pressed
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