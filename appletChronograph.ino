#include "ForwardDeclarations.h"

// rename appletDirty to counterDirty or whatever is the name of the applet
// rename applet_singleClick() into counter_singleClick() or whatever the name of the applet is
// rename the rest of the event handler, screen enter, and display functions as such
// rename appletScreen to counterScreen
// Add extern Screen counterScreen; to ForwardDeclarations.h

// =============================================
// APPLET STATE
// =============================================

static bool chronoDirty = true;

// Add any variables your applet needs here.
// Example:
//
// int page = 0;
// int setting = 5;


// =============================================
// EVENT HANDLERS
// =============================================

void chrono_singleClick() {

  // Change state here.

  chronoDirty = true;
}

void chrono_menuClick() {

  // Return to the menu.

  setScreen(&menuScreen);
}

void chrono_clockWise() {

  // Optional

  chronoDirty = true;
}

void chrono_counterClockWise() {

  // Optional

  chronoDirty = true;
}

// =============================================
// SCREEN ENTER
// =============================================

void chrono_onEnter() {

  chronoDirty = true;
}

// =============================================
// DISPLAY
// =============================================

void chrono_update() {

  if (!chronoDirty) {
    return;
  }

  chronoDirty = false;

  lcd.clear();

  switch (0) {

    case 0:
      lcd.setCursor(0,0);
      lcd.print("My Applet");
      lcd.setCursor(0,1);
      lcd.print(millis());
      break;

  }
}

// =============================================
// SCREEN OBJECT
// =============================================

Screen chronoScreen = {
  chrono_singleClick,
  chrono_menuClick,
  chrono_clockWise,
  chrono_counterClockWise,
  chrono_onEnter,
  chrono_update
};
