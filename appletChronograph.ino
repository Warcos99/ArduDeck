#include "ForwardDeclarations.h"

static bool chronoDirty = true;   // controls when we redraw the LCD
bool running = false;             // is the timer currently counting?
unsigned long segmentStart = 0;   // millis() value when current run segment began
unsigned long bankedMs = 0;       // total elapsed ms from all completed segments
long displayTenths = -1;          // last tenth-of-a-second value shown; -1 forces first draw
bool showSecondsMode = false;     // false = hh:mm:ss:t, true = plain seconds (e.g. 3847.2 sec)

unsigned long getElapsedMs() {
  if (running) {
    return bankedMs + (millis() - segmentStart);
  }
  return bankedMs;
}

void printTwoDigits(int value) {
  if (value < 10) {
    lcd.print('0');
  }
  lcd.print(value);
}

// user actions
void chrono_singleClick() {
  if (!running) {
    // start or resume
    running = true;
    segmentStart = millis();
  } else {
    // stop / pause -> bank the time from this segment
    bankedMs += millis() - segmentStart;
    running = false;
  }
  chronoDirty = true; // force a redraw immediately on state change
}
void chrono_menuClick() {
  setScreen(&menuScreen);
}
void chrono_clockWise() {
  // toggle bottom-line display mode: hh:mm:ss:t <-> plain seconds
  showSecondsMode = !showSecondsMode;
  chronoDirty = true; // force immediate redraw so the toggle feels responsive
}
void chrono_counterClockWise() {
  // "reset" - only makes sense while stopped, but that's a judgment call for you
  if (!running) {
    bankedMs = 0;
    displayTenths = -1;
    chronoDirty = true;
  }
}

void chrono_onEnter() {
  running = false;
  bankedMs = 0;
  displayTenths = -1;
  chronoDirty = true;
}

void chrono_update() {
  unsigned long elapsed = getElapsedMs();
  long currentTenths = elapsed / 100; // total tenths of a second elapsed
  // only mark dirty if the visible tenths value actually changed
  if (currentTenths != displayTenths) {
    displayTenths = currentTenths;
    chronoDirty = true;
  }
  if (!chronoDirty) {
    return;
  }
  // break total tenths down into h / m / s / tenths
  int tenths  = displayTenths % 10;
  long totalSeconds = displayTenths / 10;
  int seconds = totalSeconds % 60;
  long totalMinutes = totalSeconds / 60;
  int minutes = totalMinutes % 60;
  int hours   = totalMinutes / 60;
  lcd.clear();
  // ---- top line ----
  lcd.setCursor(0,0);
  lcd.write(byte(1));//right arrow
  lcd.print(":");
  lcd.write(byte(4));//reset symbol
  lcd.setCursor(13,0);
  lcd.write(byte(5));//viewchange symbol
  lcd.print(":");
  lcd.write(byte(0));//left arrow
  lcd.setCursor(5, 0);
  lcd.print("CHRONO");
  // ---- bottom line: hh:mm:ss:t, or plain seconds, depending on mode ----
  if (showSecondsMode) {
    lcd.setCursor(5, 1);
    lcd.print(totalSeconds);
    lcd.print('.');
    lcd.print(tenths);
    lcd.print(" sec");
  } else {
    lcd.setCursor(2, 1);
    printTwoDigits(hours);
    lcd.print(':');
    printTwoDigits(minutes);
    lcd.print(':');
    printTwoDigits(seconds);
    lcd.print(':');
    lcd.print(tenths); // single digit, 0-9
  }
  lcd.setCursor(13,1);
  lcd.write(running ? byte(2) : byte(3)); // running arrow or paused icon
  chronoDirty = false;
}

Screen chronoScreen = {
  chrono_singleClick,
  chrono_menuClick,
  chrono_clockWise,
  chrono_counterClockWise,
  chrono_onEnter,
  chrono_update
};
