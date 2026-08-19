#include "ForwardDeclarations.h"

// =============================================
// APPLET STATE
// =============================================
static bool diceDirty = true;

// setup fields
int diceQty = 1;              // 1-20
int diceSidesIndex = 5;       // index into diceSidesOptions[], default d20
int diceModifier = 0;         // -20 to +20
int diceMarker = 0;           // 0:Qty 1:Sides 2:Mod 3:ROLL

const int diceSidesOptions[] = {4, 6, 8, 10, 12, 20, 100};
const int diceSidesCount = 7;

// results
static int diceRolls[20];
static bool diceShowingResults = false;

// "6+6+12+3+(2)" style breakdown string, built once per roll.
// 20 dice x up to 3 digits + separators + a "+(-20)" modifier suffix
// fits comfortably in 100 chars.
static char diceResultStr[100];
static int diceResultLen = 0;
static int diceScrollOffset = 0;   // for scrolling row 1 when it's longer than 16 chars

// =============================================
// EVENT HANDLERS
// =============================================
void dice_singleClick() {
  if (diceShowingResults) {
    // single click backs out of results to the setup screen.
    // Land back on the first field (Quantity), not wherever ROLL left us.
    diceShowingResults = false;
    diceMarker = 0;
    diceDirty = true;
    return;
  }

  if (diceMarker == 3) {
    // marker is on ROLL - actually roll the dice
    for (int i = 0; i < diceQty; i++) {
      diceRolls[i] = random(1, diceSidesOptions[diceSidesIndex] + 1);
    }

    // build the "6+6+12+3" breakdown string once, up front
    int pos = 0;
    for (int i = 0; i < diceQty; i++) {
      if (i > 0) {
        diceResultStr[pos++] = '+';
      }
      pos += sprintf(diceResultStr + pos, "%d", diceRolls[i]);
    }
    if (diceModifier != 0) {
      diceResultStr[pos++] = '+';
      diceResultStr[pos++] = '(';
      pos += sprintf(diceResultStr + pos, "%d", diceModifier);
      diceResultStr[pos++] = ')';
    }
    diceResultStr[pos] = '\0';
    diceResultLen = pos;
    diceScrollOffset = 0;

    diceShowingResults = true;
    diceDirty = true;
    return;
  }

  diceMarker++;
  diceDirty = true;
}

void dice_menuClick() {
  // return to home menu
  setScreen(&menuScreen);
}

void dice_clockWise() {
  if (diceShowingResults) {
    // scroll the results line to the right (reveal later dice)
    int maxOffset = diceResultLen - 16;
    if (maxOffset < 0) {
      maxOffset = 0;
    }
    if (diceScrollOffset < maxOffset) {
      diceScrollOffset++;
      diceDirty = true;
    }
    return;
  }

  switch (diceMarker) {
    case 0: // quantity
      diceQty++;
      if (diceQty > 20) {
        diceQty = 20;
      }
      break;
    case 1: // sides
      diceSidesIndex++;
      if (diceSidesIndex >= diceSidesCount) {
        diceSidesIndex = 0;
      }
      break;
    case 2: // modifier
      diceModifier++;
      if (diceModifier > 20) {
        diceModifier = 20;
      }
      break;
  }
  diceDirty = true;
}

void dice_counterClockWise() {
  if (diceShowingResults) {
    // scroll the results line to the left
    if (diceScrollOffset > 0) {
      diceScrollOffset--;
      diceDirty = true;
    }
    return;
  }

  switch (diceMarker) {
    case 0: // quantity
      diceQty--;
      if (diceQty < 1) {
        diceQty = 1;
      }
      break;
    case 1: // sides
      diceSidesIndex--;
      if (diceSidesIndex < 0) {
        diceSidesIndex = diceSidesCount - 1;
      }
      break;
    case 2: // modifier
      diceModifier--;
      if (diceModifier < -20) {
        diceModifier = -20;
      }
      break;
  }
  diceDirty = true;
}

// =============================================
// SCREEN ENTER
// =============================================
void dice_onEnter() {
  diceMarker = 0;
  diceShowingResults = false;
  diceDirty = true;
}

// =============================================
// DISPLAY
// =============================================
void dice_update() {
  if (!diceDirty) {
    return;
  }
  lcd.clear();

  if (diceShowingResults) {
    long total = diceModifier;
    for (int i = 0; i < diceQty; i++) {
      total += diceRolls[i];
    }

    lcd.setCursor(0, 0);
    lcd.print("Total: ");
    lcd.print(total);

    lcd.setCursor(0, 1);
    int charsToShow = diceResultLen - diceScrollOffset;
    if (charsToShow > 16) {
      charsToShow = 16;
    }
    for (int i = 0; i < charsToShow; i++) {
      lcd.print(diceResultStr[diceScrollOffset + i]);
    }
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Dice: ");
    lcd.print(diceQty);
    lcd.print("d");
    lcd.print(diceSidesOptions[diceSidesIndex]);
    if (diceModifier >= 0) {
      lcd.print("+");
    }
    lcd.print(diceModifier);

    lcd.setCursor(0, 1);
    switch (diceMarker) {
      case 0:
        lcd.print("Edit: Quantity");
        break;
      case 1:
        lcd.print("Edit: Sides");
        break;
      case 2:
        lcd.print("Edit: Modifier");
        break;
      case 3:
        lcd.print(">>>  ROLL  <<<");
        break;
    }
  }

  diceDirty = false;
}

// =============================================
// SCREEN OBJECT
// =============================================
Screen diceScreen = {
  dice_singleClick,
  dice_menuClick,
  dice_clockWise,
  dice_counterClockWise,
  dice_onEnter,
  dice_update
};
