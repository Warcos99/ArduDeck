#include "ForwardDeclarations.h"
#include <avr/pgmspace.h>

int infoPage = 0;
const int numPages = 24; //hardcoded for now
static bool infoDirty = true;

const char page0[] PROGMEM = "  Ardu-Deck V3  ";
const char page1[] PROGMEM = "----------------";
const char page2[] PROGMEM = "pinout on below ";
const char page3[] PROGMEM = "3DA98760123G5RT ";
const char page4[] PROGMEM = "VDDDDDDAAAAGVXX ";
const char page5[] PROGMEM = "- - - - - - - - ";
const char page6[] PROGMEM = "Microcontroller ";
const char page7[] PROGMEM = "arduino nano avr";
const char page8[] PROGMEM = "16x2 LCD Screen ";
const char page9[] PROGMEM = "Rotary Encoder  ";
const char page10[] PROGMEM = " debounced w/556";
const char page11[] PROGMEM = "LiPo Battery    ";
const char page12[] PROGMEM = " 3.7v 840mAh    ";
const char page13[] PROGMEM = "Battery Charger ";
const char page14[] PROGMEM = " TP4056         ";
const char page15[] PROGMEM = "- - - - - - - - ";
const char page16[] PROGMEM = "Code found @ git";
const char page17[] PROGMEM = " github/warcos99";
const char page18[] PROGMEM = "Documentation on";
const char page19[] PROGMEM = " warcos.net     ";
const char page20[] PROGMEM = "Developed during";
const char page21[] PROGMEM = " Summer 2026    ";
const char page22[] PROGMEM = "- - - - - - - - ";
const char page23[] PROGMEM = "                ";
const char page24[] PROGMEM = "           (T.T)";

const char *const pages[] PROGMEM = {
    page0, page1, page2, page3, page4, page5, page6 , page7, page8, page9,
    page10,page11,page12,page13,page14,page15,page16,page17,page18,page19,
    page20,page21,page22,page23,page24
};



String getPageLine(uint8_t index) {
    char buf[17];
    strncpy_P(buf,(const char*)pgm_read_ptr(&pages[index]), sizeof(buf) -1);
    buf[sizeof(buf) - 1] = '\0';
    return String(buf);
}

void info_singleClick() {
  infoPage = 0;
  infoDirty = true;
}
void info_clockWise(){
    infoPage++;
    if (infoPage >= numPages-1) {
      infoPage = numPages-1;
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
    String line0 = getPageLine(infoPage);
    String line1 = getPageLine(infoPage+1);

    lcd.setCursor(0, 0);
    lcd.print(line0);
    lcd.setCursor(0, 1);
    lcd.print(line1);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("how r u here?");
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
