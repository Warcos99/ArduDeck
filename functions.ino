#include "ForwardDeclarations.h"

Screen* currentScreen = nullptr;

void setScreen(Screen* s) {
  currentScreen = s;
  if (currentScreen && currentScreen->onEnter) {
    currentScreen->onEnter();
  }
}

// POLL EVENT (unchanged)
Event pollEvent() {
  button.loop();
  CLK_state = digitalRead(CLK_PIN);

  if (CLK_state != prev_CLK_state && CLK_state == HIGH) {
    unsigned long now = millis();
    if (now - lastRotationTime > rotationDebounceMs) {
      prev_CLK_state = CLK_state;
      lastRotationTime = now;
      if (digitalRead(DT_PIN) == HIGH) {
        return {EVT_ROT_CCW, 0};
      } else {
        return {EVT_ROT_CW, 0};
      }
    } else {
      prev_CLK_state = CLK_state;
      return {EVT_NONE, 0};
    }
  }

  prev_CLK_state = CLK_state;

  if (button.isReleased()) {
    unsigned long now = millis();
    if (waitingSecondClick && (now - lastClickTime) <= doubleClickGapMs) {
      waitingSecondClick = false;
      return {EVT_DOUBLE_CLICK, 0};
    } else {
      lastClickTime = now;
      waitingSecondClick = true;
    }
  }

  if (waitingSecondClick && (millis() - lastClickTime) > doubleClickGapMs) {
    waitingSecondClick = false;
    return {EVT_SINGLE_CLICK, 0};
  }

  return {EVT_NONE, 0};
}

// Dispatch to whichever screen is active - no applet-specific
// logic lives here anymore.
void navigation(Event evt) {
  if (!currentScreen) return;

  switch (evt.type) {
    case EVT_ROT_CW:
      if (currentScreen->onClockWise) currentScreen->onClockWise();
      break;
    case EVT_ROT_CCW:
      if (currentScreen->onCounterClockWise) currentScreen->onCounterClockWise();
      break;
    case EVT_SINGLE_CLICK:
      if (currentScreen->onSingleClick) currentScreen->onSingleClick();
      break;
    case EVT_DOUBLE_CLICK:
      if (currentScreen->onDoubleClick) currentScreen->onDoubleClick();
      break;
    default:
      break;
  }
}

// One loop body for every screen - replaces the separate
// processMenu()/appletInfo() poll+navigate+display duplication.
void runScreen() {
  Event evt = pollEvent();
  if (evt.type != EVT_NONE) {
    navigation(evt);
  }
  if (currentScreen && currentScreen->update) {
    currentScreen->update();
  }
}
