
#include "ForwardDeclarations.h"

static bool mtgDirty = true;

int life = 40;
int comTax = 0;
int counter1 = 0;
int counter2 = 0;
int counterMarker = 0; //0:Life 1:ComTax 2:c1 3:c2

// user actions
void mtg_singleClick() {
  counterMarker ++;

  if (counterMarker > 3){
      counterMarker = 0;
  }

  mtgDirty = true;
}

void mtg_menuClick() {
    // return to home menu
  setScreen(&menuScreen);
}

void mtg_clockWise() {
    // increase counters
    switch (counterMarker) {
        case 0:
            life++;
            break;
        case 1:
            comTax = comTax + 2;
            break;
        case 2:
            counter1++;
            break;
        case 3:
            counter2++;
            break;
    }

  mtgDirty = true;
}

void mtg_counterClockWise() {
    // decrease counters
    switch (counterMarker) {
        case 0:
            life--;
            break;
        case 1:
            comTax = comTax - 2;
            break;
        case 2:
            counter1--;
            break;
        case 3:
            counter2--;
            break;
    }

  mtgDirty = true;
}



void mtg_onEnter() {
  drawArrows();
  drawMTGscreen();
  mtgDirty = true;
}

void mtg_update() {

  if (!mtgDirty) {
    return;
  }
lcd.clear();
drawMTGscreen();
drawArrows();

mtgDirty = false;
}

void drawArrows(){
 switch (counterMarker){
    case 0:
      lcd.setCursor(0,0);
      lcd.write(byte(0));
      lcd.setCursor(7,0);
      lcd.write(byte(1));
      break;
    case 1:
      lcd.setCursor(8,0);
      lcd.write(byte(0));
      lcd.setCursor(15,0);
      lcd.write(byte(1));
      break;
    case 2:
      lcd.setCursor(0,1);
      lcd.write(byte(0));
      lcd.setCursor(7,1);
      lcd.write(byte(1));
      break;
    case 3:
      lcd.setCursor(8,1);
      lcd.write(byte(0));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      break;
    }
}

void drawMTGscreen(){
  lcd.setCursor(1,0);
  lcd.print("Lf: ");
  lcd.print(life);
  lcd.setCursor(9,0);
  lcd.print("Tx: ");
  lcd.print(comTax);
  lcd.setCursor(1,1);
  lcd.print("C1: ");
  lcd.print(counter1);
  lcd.setCursor(9,1);
  lcd.print("C2: ");
  lcd.print(counter2);
}

Screen mtgScreen = {
  mtg_singleClick,
  mtg_menuClick,
  mtg_clockWise,
  mtg_counterClockWise,
  mtg_onEnter,
  mtg_update
};
