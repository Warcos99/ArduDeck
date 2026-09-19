#include "ForwardDeclarations.h"
#include <avr/pgmspace.h>

// declare variables
static bool rangerDirty = true;
float duration, distance, fractional;
int feet, inches, numerator, denominator;

void convertMeasure(){
    measure();
    fractional = distance - (int)distance;
    feet = (int)distance / 12;
    inches = (int)distance % 12;
    denominator = 32;
    numerator = (int)round(fractional * denominator);
    if (numerator == denominator) {
        numerator = 0;
        inches++;
        if (inches == 12) {
            inches = 0;
            feet++;
        }
    }
}

void displayMeasure(){
    convertMeasure();
    if (distance>=400 || distance <=2){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Click to Measure");
        lcd.setCursor(0,1);
        lcd.print("Out Of Range!");
    } else {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Click to Measure");
      lcd.setCursor(0,1);
      lcd.print(feet);
      lcd.print("ft ");
      lcd.print(inches);
      lcd.print("in ");
      lcd.print(numerator);
      lcd.print("/");
      lcd.print(denominator);
    }
}

void measure(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) * 0.0344 * 0.3937008;

    //returns distance in (float)inches
}

// user actions
void ranger_singleClick() {

  displayMeasure();

  rangerDirty = true;
}
void ranger_menuClick() {

  // Return to the menu.

  setScreen(&menuScreen);
}

void ranger_clockWise() {

  // Optional

  rangerDirty = true;
}

void ranger_counterClockWise() {

  // Optional

  rangerDirty = true;
}

void ranger_onEnter() {
  displayMeasure();
}

void ranger_update() {

  if (!rangerDirty) {
    return;
  }

  rangerDirty = false;
}

Screen rangerScreen = {
  ranger_singleClick,
  ranger_menuClick,
  ranger_clockWise,
  ranger_counterClockWise,
  ranger_onEnter,
  ranger_update
};
