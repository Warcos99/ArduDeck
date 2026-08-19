
#include "ForwardDeclarations.h"


// =============================================
// APPLET STATE
// =============================================

static bool counterDirty = true;
int count = 0;

// =============================================
// EVENT HANDLERS
// =============================================

void counter_singleClick() {
  count++;
  counterDirty = true;
}

void counter_menuClick() {
  // Return to the menu.
  setScreen(&menuScreen);
}

void counter_clockWise() {
  count++;
  counterDirty = true;
}

void counter_counterClockWise() {
  count--;
  counterDirty = true;
}

// =============================================
// SCREEN ENTER
// =============================================

void counter_onEnter() {
  counterDirty = true;
}

// =============================================
// DISPLAY
// =============================================

void counter_update() {
  if (!counterDirty) {
    return;
  }

  counterDirty = false;
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("     Count     ");
  lcd.setCursor(0,1);
  lcd.print("       ");
  lcd.print(count);
}

// =============================================
// SCREEN OBJECT
// =============================================

Screen counterScreen = {
  counter_singleClick,
  counter_menuClick,
  counter_clockWise,
  counter_counterClockWise,
  counter_onEnter,
  counter_update
};
