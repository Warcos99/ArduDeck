
#include "ForwardDeclarations.h"


static bool counterDirty = true;
int count = 0;

// user actions
void counter_singleClick() {
  count++;
  counterDirty = true;
}

void counter_menuClick() {
  // Return to the menu.
  setScreen(&menuScreen);
}

void counter_clockWise() {
  count++;
  counterDirty = true;
}

void counter_counterClockWise() {
  count--;
  counterDirty = true;
}


void counter_onEnter() {
  counterDirty = true;
}

void counter_update() {
  if (!counterDirty) {
    return;
  }

  counterDirty = false;
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("     Count     ");
  lcd.setCursor(0,1);
  lcd.print("       ");
  lcd.print(count);
}

Screen counterScreen = {
  counter_singleClick,
  counter_menuClick,
  counter_clockWise,
  counter_counterClockWise,
  counter_onEnter,
  counter_update
};
