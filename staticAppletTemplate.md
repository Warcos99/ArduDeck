#include "ForwardDeclarations.h"
#include <avr/pgmspace.h>

// rename appletDirty to counterDirty or whatever is the name of the applet
// rename applet_singleClick() into counter_singleClick() or whatever the name of the applet is
// rename the rest of the event handler, screen enter, and display functions as such
// rename appletScreen to counterScreen

// Add extern Screen counterScreen; to ForwardDeclarations.h
// on menu.ino, add case for new menu item under "void menu_singleClick()"

// on VIM to replace all instances of "applet" to "counter" use:
//:%s/applet/counter/g  -> % - Apply to whole File | s - substitute | /g-apply all at once

// declare variables 
static bool appletDirty = true;

// user actions
void applet_singleClick() {

  // Change state here.

  appletDirty = true;
}

void applet_menuClick() {

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

void applet_onEnter() {

  appletDirty = true;
}

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

Screen appletScreen = {
  applet_singleClick,
  applet_menuClick,
  applet_clockWise,
  applet_counterClockWise,
  applet_onEnter,
  applet_update
};
