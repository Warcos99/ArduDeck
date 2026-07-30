#include "ForwardDeclarations.h"

// =============================================
// APPLET STATE
// =============================================

unsigned long lastUpdate = 0;
const unsigned long updateInterval = 250;

// Variables for the animation.


// =============================================
// EVENT HANDLERS
// =============================================

void applet_singleClick() {

}

void applet_doubleClick() {

  setScreen(&menuScreen);
}

void applet_clockWise() {

}

void applet_counterClockWise() {

}


// =============================================
// SCREEN ENTER
// =============================================

void applet_onEnter() {

  lastUpdate = millis();

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Animated");
}


// =============================================
// UPDATE
// =============================================

void applet_update() {

  unsigned long now = millis();

  if (now - lastUpdate < updateInterval) {
    return;
  }

  lastUpdate += updateInterval;

  // Update the animation here.

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
