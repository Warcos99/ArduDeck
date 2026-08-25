#include "ForwardDeclarations.h"

int infoPage = 0;

const char* pages[][2] = {
  {"**Ardu-Deck V3**", "pinout on nxt pg"},
  {"3DA98760123G5RT ", "VDDDDDDAAAAGVXX "},
  {"Microcontroller ", "     arduino:avr"},
  {"Screen          ", " 16x2 LCD Screen"},
  {"Button          ", "  Rotary Encoder"},
  {"R1-200 R3-100k  ", "   C1-1U C2-0.1U"},
  {"Code: github  W-", "arcos99/ArduDeck"},
  {"Battery:        ", "3.7V 840mAh LiPo"},
  {"Volt Boost      ", "    output: 7.8V"},
  {"Battery Charger ", "          TP4056"},
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

void info_clockWise(){
    infoPage++;
    if (infoPage >= numPages) {
      infoPage = 0;
    }
    infoDirty = true;
}

void info_counterClockWise(){
    infoPage--;
    if (infoPage <0){
        infoPage = 0;
    }
    infoDirty = true;
}

void info_menuClick() {
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
  info_menuClick,
  info_clockWise,
  info_counterClockWise,
  info_enter,
  displayInfo
};
