#include "ForwardDeclarations.h"

Screen* currentScreen = nullptr;

void setScreen(Screen* s) {
  currentScreen = s;
  if (currentScreen && currentScreen->onEnter) {
    currentScreen->onEnter();
  }
}

// POLL EVENT
Event pollEvent() {
  CLK_state = analogRead(CLK_PIN)>(prev_CLK_state ? LOW_THRESH : HIGH_THRESH);

  if (CLK_state != prev_CLK_state && CLK_state == HIGH) {
    unsigned long now = millis();
    if (now - lastRotationTime > rotationDebounceMs) {
      prev_CLK_state = CLK_state;
      lastRotationTime = now;
      if (analogRead(DT_PIN) > 512) {
        return {EVT_ROT_CW, 0};
      } else {
        return {EVT_ROT_CCW, 0};
      }
    } else {
      prev_CLK_state = CLK_state;
      return {EVT_NONE, 0};
    }
  }

  prev_CLK_state = CLK_state;

  SW_state = analogRead(SW_PIN) > (debounced_SW_state ? LOW_THRESH : HIGH_THRESH);
    if (SW_state != debounced_SW_state) {
      bool wasReleased = (debounced_SW_state == false && SW_state == true);
      debounced_SW_state = SW_state;
      if (wasReleased) {
        unsigned long now = millis();
        if (waitingSecondClick && (now - lastClickTime) <= doubleClickGapMs) {
          waitingSecondClick = false;
          return {EVT_DOUBLE_CLICK, 0};
        } else {
          lastClickTime = now;
          waitingSecondClick = true;
        }
      }
    }

  if (waitingSecondClick && (millis() - lastClickTime) > doubleClickGapMs) {
    waitingSecondClick = false;
    return {EVT_SINGLE_CLICK, 0};
  }

  return {EVT_NONE, 0};
}

// Dispatch to whichever screen is active - no applet-specific logic lives here
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

// One loop body for every screen
void runScreen() {
  Event evt = pollEvent();
  if (evt.type != EVT_NONE) {
    navigation(evt);
  }
  if (currentScreen && currentScreen->update) {
    currentScreen->update();
  }
}
