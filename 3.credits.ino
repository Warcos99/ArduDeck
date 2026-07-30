#include "ForwardDeclarations.h"

const char* creditsWords[] = {
  "code", "circuits", "arduino", "lcd", "encoder", "button", "pixels", "volts",
  "resistor", "capacitor", "diode", "transistor", "solder", "wire", "signal", "pulse",
  "binary", "logic", "loop", "function", "pointer", "struct", "screen", "menu",
  "blink", "credits", "display", "cursor", "scroll", "debounce", "interrupt", "clock",
  "data", "bus", "register", "memory", "flash", "sketch", "compile", "upload",
  "serial", "baud", "voltage", "current", "ground", "power", "battery", "switch",
  "sensor", "output"
};
const int NUM_CREDITS_WORDS = 50;

String creditsText;
int creditsScrollPos = 0;
unsigned long lastCreditsScroll = 0;
const unsigned long creditsScrollIntervalMs = 300;

void credits_onEnter() {
  creditsText = "";
  for (int i = 0; i < NUM_CREDITS_WORDS; i++) {
    creditsText += creditsWords[i];
    creditsText += "   ";
  }
  creditsScrollPos = 0;
  lastCreditsScroll = millis();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("credits");
}

void credits_doubleClick() {
  setScreen(&menuScreen);
}

void credits_update() {
  unsigned long now = millis();
  if (now - lastCreditsScroll >= creditsScrollIntervalMs) {
    lastCreditsScroll = now;

    lcd.setCursor(0, 1);
    int len = creditsText.length();
    for (int i = 0; i < 16; i++) {
      lcd.print(creditsText[(creditsScrollPos + i) % len]);
    }

    creditsScrollPos = (creditsScrollPos + 1) % len;
  }
}

Screen creditsScreen = {
  nullptr,   // single click does nothing
  credits_doubleClick,
  nullptr,   // clockwise does nothing
  nullptr,   // counterclockwise does nothing
  credits_onEnter,
  credits_update
};
