#include "ForwardDeclarations.h"

int infoPage = 0;

const char* pages[][2] = {
  {"**Ardu-Deck V2**", "Click 4 Next Pg "},
  {"3DA98760123G5RT ", "VDDDDDDAAAAGVXX "},
  {"Microcontroller ", "     arduino:avr"},
  {"Screen          ", " 16x2 LCD Screen"},
  {"Button          ", "  Rotary Encoder"},
  {"R1-200 R3-100k  ", "   C1-1U C2-0.1U"},
  {"code: github  W-", "arcos99/ArduDeck"},
  {"End             ", "         (T u T)"}
};
const int numPages = sizeof(pages) / sizeof(pages[0]);

// Private dirty flag for this screen
static bool infoDirty = true;

void info_singleClick() {
  infoPage++;

  if (infoPage >= numPages) {
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
  if (!infoDirty) return;
  infoDirty = false;

  lcd.clear();

  if (infoPage < numPages) {
    lcd.setCursor(0, 0);
    lcd.print(pages[infoPage][0]);
    lcd.setCursor(0, 1);
    lcd.print(pages[infoPage][1]);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Unknown Page");
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
