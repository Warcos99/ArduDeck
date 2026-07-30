#include "ForwardDeclarations.h"

unsigned long blinkIntervalMs = 500;
const unsigned long minBlinkIntervalMs = 100;
const unsigned long maxBlinkIntervalMs = 2000;
const unsigned long blinkStepMs = 100;

bool blinkOn = false;
unsigned long lastBlinkToggle = 0;

void blink_onEnter() {
  lcd.clear();
  blinkOn = false;
  lastBlinkToggle = millis();
}

void blink_doubleClick() {
  setScreen(&menuScreen);
}

void blink_clockWise() {
  if (blinkIntervalMs > minBlinkIntervalMs) {
    blinkIntervalMs -= blinkStepMs;
  }
}

void blink_counterClockWise() {
  if (blinkIntervalMs < maxBlinkIntervalMs) {
    blinkIntervalMs += blinkStepMs;
  }
}

void blink_update() {
  unsigned long now = millis();
  if (now - lastBlinkToggle >= blinkIntervalMs) {
    lastBlinkToggle = now;
    blinkOn = !blinkOn;

    lcd.setCursor(0, 0);
    lcd.print(blinkOn ? "blink" : "     ");
  }
}

Screen blinkScreen = {
  nullptr,             // single click does nothing
  blink_doubleClick,
  blink_clockWise,
  blink_counterClockWise,
  blink_onEnter,
  blink_update
};
