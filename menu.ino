#include "ForwardDeclarations.h"

// menuSetting is the currently highlighted item - 0-based,
// matches the indices in menuItems[] directly.
int menuSetting = 0;

// Dirty flag - tells the screen when it needs to be redrawn.
static bool menuDirty = true;

void menu_singleClick() {
  switch (menuSetting) {
    case 0:
      setScreen(&infoScreen);
      break;

    case 1:
      setScreen(&blinkScreen);
      break;

    case 2:
      setScreen(&creditsScreen);
      break;
  }
}

void menu_doubleClick() {
  menuSetting = 0;
  menuDirty = true;
}

void menu_clockWise() {
  menuSetting++;

  if (menuSetting >= MAX_CASES) {
    menuSetting = 0;
  }

  menuDirty = true;
}

void menu_counterClockWise() {
  menuSetting--;

  if (menuSetting < 0) {
    menuSetting = MAX_CASES - 1;
  }

  menuDirty = true;
}

void menu_enter() {
  menuDirty = true;
}

void displayMenu() {

  // Nothing changed, so don't touch the LCD.
  if (!menuDirty) {
    return;
  }

  menuDirty = false;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("----**MENU**----");
  lcd.setCursor(0, 1);
  lcd.print("> ");
  lcd.print(menuItems[menuSetting]);
  lcd.print("   ");
}

Screen menuScreen = {
  menu_singleClick,
  menu_doubleClick,
  menu_clockWise,
  menu_counterClockWise,
  menu_enter,
  displayMenu
};
