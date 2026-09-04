#include "ForwardDeclarations.h"

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

static char diceResultStr[100];
static int diceResultLen = 0;
static int diceScrollOffset = 0;   // for scrolling row 1 when it's longer than 16 chars

void dice_singleClick() {
  if (diceShowingResults) {
    diceShowingResults = false;
    diceMarker = 0;
    diceDirty = true;
    return;
  }

  if (diceMarker == 3) {
    for (int i = 0; i < diceQty; i++) {
      diceRolls[i] = random(1, diceSidesOptions[diceSidesIndex] + 1);
    }

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
  setScreen(&menuScreen);
}

void dice_clockWise() {
  if (diceShowingResults) {
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

void dice_onEnter() {
  diceMarker = 0;
  diceShowingResults = false;
  diceDirty = true;
}

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

Screen diceScreen = {
  dice_singleClick,
  dice_menuClick,
  dice_clockWise,
  dice_counterClockWise,
  dice_onEnter,
  dice_update
};
