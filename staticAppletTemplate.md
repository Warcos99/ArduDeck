#include "ForwardDeclarations.h"

// =============================================
// APPLET STATE
// =============================================

static bool appletDirty = true;

// Add any variables your applet needs here.
// Example:
//
// int page = 0;
// int setting = 5;


// =============================================
// EVENT HANDLERS
// =============================================

void applet_singleClick() {

  // Change state here.

  appletDirty = true;
}

void applet_doubleClick() {

  // Return to the menu.

  setScreen(&menuScreen);
}

void applet_clockWise() {

  // Optional

  appletDirty = true;
}

void applet_counterClockWise() {

  // Optional

  appletDirty = true;
}


// =============================================
// SCREEN ENTER
// =============================================

void applet_onEnter() {

  appletDirty = true;
}


// =============================================
// DISPLAY
// =============================================

void applet_update() {

  if (!appletDirty) {
    return;
  }

  appletDirty = false;

  lcd.clear();

  switch (0) {

    case 0:
      lcd.setCursor(0,0);
      lcd.print("My Applet");
      lcd.setCursor(0,1);
      lcd.print("Hello!");
      break;

  }
}


// =============================================
// SCREEN OBJECT
// =============================================

Screen appletScreen = {
  applet_singleClick,
  applet_doubleClick,
  applet_clockWise,
  applet_counterClockWise,
  applet_onEnter,
  applet_update
};
