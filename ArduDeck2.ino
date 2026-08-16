// Libraries
#include <LiquidCrystal.h>

// Forward Declarations
#include "ForwardDeclarations.h"

// pins for Rotary Encoder
#define CLK_PIN A7
#define DT_PIN A5
#define SW_PIN A6
#define DIRECTION_CW 0
#define DIRECTION_CCW 1
#define HIGH_THRESH 650
#define LOW_THRESH 370

// pins for 16x2 LCD screen
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//debounce sw state pare
int CLK_state;
int prev_CLK_state;
bool SW_state;
bool debounced_SW_state;

// Variables used in functions.ino
// used to deal with rotation debounce
unsigned long lastRotationTime = 0;
const unsigned long rotationDebounceMs = 100;

// variables used in functions.ino
// used for the logic that checks double click
unsigned long lastClickTime = 0;
bool waitingSecondClick = false;
const unsigned long doubleClickGapMs = 200;

void setup() {
  //initialize LCD screen
  lcd.begin(16, 2);

  // start the program by taking a reading of CLK
  prev_CLK_state = analogRead(CLK_PIN) > HIGH_THRESH;
  debounced_SW_state = analogRead(SW_PIN) > HIGH_THRESH;

  //clear screen and display menu
  lcd.clear();
  setScreen(&menuScreen);
}

void loop() {
  // run screen can be found in funcitons.ino
  // it updates the screen when there is an update
  runScreen();
}
