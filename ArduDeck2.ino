#include <LiquidCrystal.h>
#include <ezButton.h>

#include "ForwardDeclarations.h"

#define CLK_PIN A5
#define DT_PIN A6
#define SW_PIN A7
#define DIRECTION_CW 0
#define DIRECTION_CCW 1

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned long previousMillis = 0;
const unsigned long interval = 1000;

int direction = DIRECTION_CW;
int CLK_state;
int prev_CLK_state;

unsigned long lastRotationTime = 0;
const unsigned long rotationDebounceMs = 10;

ezButton button(SW_PIN);

unsigned long lastClickTime = 0;
bool waitingSecondClick = false;
const unsigned long doubleClickGapMs = 200;

// Menu variables
int currentCase = 0;
const int MAX_CASES = 3;
const char* menuItems[] = {
  "1: Info",
  "2: Blink",
  "3: Credits"
};

void setup() {
  lcd.begin(16, 2);

  pinMode(CLK_PIN, INPUT);
  pinMode(DT_PIN, INPUT);

  prev_CLK_state = digitalRead(CLK_PIN);

  lcd.clear();
  setScreen(&menuScreen);
}

void loop() {
  runScreen();
}
