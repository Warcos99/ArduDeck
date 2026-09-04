#include "ForwardDeclarations.h"
#include <avr/pgmspace.h>

static bool appletDirty = true;

void credits_singleClick() {
  appletDirty = true;
}
void credits_menuClick() {
  // Return to the menu.
  setScreen(&menuScreen);
}
void credits_clockWise() {
  appletDirty = true;
}
void credits_counterClockWise() {
  appletDirty = true;
}

void credits_onEnter() {
  appletDirty = true;
}

void credits_update() {
    if (!appletDirty) return;
    appletDirty = false;
    lcd.setCursor(0,0);
    lcd.print("  Thanks 4 All  ");
    lcd.setCursor(0,1);
    lcd.print("       <3       ");
}

Screen creditsScreen = {
  credits_singleClick,
  credits_menuClick,
  credits_clockWise,
  credits_counterClockWise,
  credits_onEnter,
  credits_update
};
