#include "ForwardDeclarations.h"

// =============================================
// APPLET STATE
// =============================================

static bool appletDirty = true;

int creditsPage = 0;

const char* cPages[][2] = {
  {"**Ardu-Deck V2**", "##---Credits--##"},
  {"J. Marcos Avina ", "     Summer 2026"},
  {"Website:        ", "      warcos.net"},
  {"github:         ", "       /Warcos99"},
  {"End             ", "          (@u@^)"}
};
const int creditsNumPages = sizeof(cPages) / sizeof(cPages[0]);


// =============================================
// EVENT HANDLERS
// =============================================

void credits_singleClick() {
  creditsPage++;

  if (creditsPage >= creditsNumPages) {
    creditsPage = 0;
  }

  appletDirty = true;
}

void credits_doubleClick() {

  // Return to the menu.

  setScreen(&menuScreen);
}

void credits_clockWise() {

  // Optional

  appletDirty = true;
}

void credits_counterClockWise() {

  // Optional

  appletDirty = true;
}


// =============================================
// SCREEN ENTER
// =============================================

void credits_onEnter() {

  appletDirty = true;
}


// =============================================
// DISPLAY
// =============================================

void credits_update() {
    if (!appletDirty) return;
    appletDirty = false;

    lcd.clear();

    if (creditsPage <= cPages) {
        lcd.setCursor(0, 0);
        lcd.print(cPages[creditsPage][0]);
        lcd.setCursor(0, 1);
        lcd.print(cPages[creditsPage][1]);
      } else {
        lcd.setCursor(0, 0);
        lcd.print("Unknown Page");
      }
}


// =============================================
// SCREEN OBJECT
// =============================================

Screen creditsScreen = {
  credits_singleClick,
  credits_doubleClick,
  credits_clockWise,
  credits_counterClockWise,
  credits_onEnter,
  credits_update
};
