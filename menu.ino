#include "ForwardDeclarations.h"

// menuSetting -> what to display on the menu screen
// currentCase -> what applet or menu to run
int menuSetting = 0;
int currentCase = 0;

// edit MAX_CASES and menuItems to add to the men
const int MAX_CASES = 9;
const char* menuItems[] = {
  "1: Info       ",
  "2: EDH Life   ",
  "3: TTRPG Dice ",
  "4: Counter    ",
  "5: Chronograph",
  "6: Char Gen   ",
  "7: Blink      ",
  "8: BTN Test   ",
  "9: Credits    "
};

// Dirty flag - tells the screen when it needs to be redrawn.
static bool menuDirty = true;

void menu_singleClick() {
  switch (menuSetting) {
    case 0:
      setScreen(&infoScreen);
      break;

    case 1:
      setScreen(&mtgScreen);
      break;

    case 2:
      setScreen(&diceScreen);
      break;

    case 3:
      setScreen(&counterScreen);
      break;

    case 4:
      setScreen(&chronoScreen);
      break;

    case 5:
      setScreen(&charScreen);
      break;

    case 6:
      setScreen(&blinkScreen);
      break;

    case 7:
      setScreen(&btnTestScreen);
      break;

    case 8:
        setScreen(&creditsScreen);
        break;
  }
}

void menu_menuClick() {
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
  menu_menuClick,
  menu_clockWise,
  menu_counterClockWise,
  menu_enter,
  displayMenu
};
