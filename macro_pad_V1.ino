#include "HID-Project.h"
#include <ezButton.h>

// create ezButton object that attach to pins
ezButton left(9);
ezButton center(8);
ezButton right(7);

void setup() {
  left.setDebounceTime(50);
  center.setDebounceTime(50);
  right.setDebounceTime(50);
  Keyboard.begin();
}

void loop() {
  left.loop();
  center.loop();
  right.loop();

  // ALL
  if(left.isPressed()){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_A);
  }

  // COPY
  if(center.isPressed()){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_C);
  }

  // PASTE WITHOUT FORMATTING
  if(right.isPressed()){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_V);
  }
  
  Keyboard.releaseAll();
}
