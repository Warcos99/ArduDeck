#include "ForwardDeclarations.h"

int infoPage = 0;
const int maxInfoPage = 3;

// Private dirty flag for this screen
static bool infoDirty = true;

void info_singleClick() {
  infoPage++;

  if (infoPage > maxInfoPage) {
    infoPage = 0;
  }

  infoDirty = true;
}

void info_doubleClick() {
  currentCase = 0;
  setScreen(&menuScreen);
}

void info_enter() {
  infoDirty = true;
}

void displayInfo() {

  // Nothing has changed, so don't redraw.
  if (!infoDirty) {
    return;
  }

  infoDirty = false;

  lcd.clear();

  switch (infoPage) {

    case 0:
      lcd.setCursor(0, 0);
      lcd.print("--**ArduDeck**--");
      lcd.setCursor(0, 1);
      lcd.print("Click 4 Next Pg");
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("3DA98760123G5RT");
      lcd.setCursor(0,1);
      lcd.print("VDDDDDDAAAAGVXX");
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("FQBN= arduino:m-");
      lcd.setCursor(0,1);
      lcd.print("egaavrx:nona4809");
      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.print("Page 4");
      break;

    default:
      lcd.setCursor(0, 0);
      lcd.print("Unknown Page");
      break;
  }
}

Screen infoScreen = {
  info_singleClick,
  info_doubleClick,
  nullptr,
  nullptr,
  info_enter,
  displayInfo
};
