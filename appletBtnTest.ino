#include "ForwardDeclarations.h"

// =============================================
// APPLET STATE
// =============================================

static bool btnTestDirty = true;

int rot = 0;
int click = 0;

// =============================================
// EVENT HANDLERS
// =============================================

void btnTest_singleClick() {
  click++;
  btnTestDirty = true;
}

void btnTest_menuClick() {
  setScreen(&menuScreen);
}

void btnTest_clockWise() {
  rot++;
  btnTestDirty = true;
}

void btnTest_counterClockWise() {
  rot--;
  btnTestDirty = true;
}

// =============================================
// SCREEN ENTER
// =============================================

void btnTest_onEnter() {
  rot = 0;
  click = 0;
  btnTestDirty = true;
}

// =============================================
// DISPLAY
// =============================================

void btnTest_update() {
  if (!btnTestDirty) {
    return;
  }

  btnTestDirty = false;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("rot:");
  lcd.print(rot);

  lcd.setCursor(0, 1);
  lcd.print("click:");
  lcd.print(click);
}

// =============================================
// SCREEN OBJECT
// =============================================

Screen btnTestScreen = {
  btnTest_singleClick,
  btnTest_menuClick,
  btnTest_clockWise,
  btnTest_counterClockWise,
  btnTest_onEnter,
  btnTest_update
};
