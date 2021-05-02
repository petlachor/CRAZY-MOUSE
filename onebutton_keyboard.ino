//-------------------------------------------------------------------
// CRAZY MOUSE CURSOR
// ※Cursor movement can be turned ON/OFF each time a key is pressed.
// https://www.one-button-key.com/
//-------------------------------------------------------------------
#include "Mouse.h"

#define PIN_KEYSW (9)

int prevKeyState;
int currKeyState;
bool mouseOn;
int mouseMoveCnt;

void setup() {
  pinMode(PIN_KEYSW, INPUT_PULLUP);
  prevKeyState = HIGH;
  currKeyState = HIGH;
  mouseOn = false;
  mouseMoveCnt = 0;

  Mouse.begin();
}

void loop() {
  currKeyState = digitalRead(PIN_KEYSW);

  // The key switch was pressed
  if ((prevKeyState == HIGH) && (currKeyState == LOW)) {
    mouseOn = !mouseOn;
  }

  // Move the mouse cursor
  if (mouseOn) {
    if (mouseMoveCnt == 0) {
      Mouse.move(10, 0);
    }
    else if (mouseMoveCnt == 1) {
      Mouse.move(0, 10);
    }
    else if (mouseMoveCnt == 2) {
      Mouse.move(-10, 0);
    }
    else {
      Mouse.move(0, -10);
    }
    mouseMoveCnt++;
    if (mouseMoveCnt >= 4) mouseMoveCnt = 0;
  }
  
  prevKeyState = currKeyState;
  delay(10);
}
