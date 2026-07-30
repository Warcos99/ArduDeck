#ifndef FORWARD_DECLARATIONS_H
#define FORWARD_DECLARATIONS_H

// =============================================
// EVENT TYPES
// =============================================

enum EventType {
  EVT_NONE = 0,
  EVT_ROT_CW,
  EVT_ROT_CCW,
  EVT_SINGLE_CLICK,
  EVT_DOUBLE_CLICK
};

struct Event {
  EventType type;
  int value;
};

// =============================================
// SCREEN TYPE
// =============================================
// Each "applet" (menu, info, etc.) fills one of
// these out. Only currentScreen's handlers ever
// run, so no two files can collide on a name.

struct Screen {
  void (*onSingleClick)();
  void (*onDoubleClick)();
  void (*onClockWise)();
  void (*onCounterClockWise)();
  void (*onEnter)();   // optional, runs once when screen becomes active
  void (*update)();    // runs every loop() - polls, navigates, displays
};

extern Screen* currentScreen;
void setScreen(Screen* s);

// =============================================
// FUNCTION DECLARATIONS
// =============================================

Event pollEvent();
void navigation(Event evt);
void runScreen();

// Menu
void displayMenu();
extern Screen menuScreen;

// 1. Info
void displayInfo();
extern Screen infoScreen;

// 2. Blink
extern Screen blinkScreen;

// 3. Credits
extern Screen creditsScreen;

// Shared globals other files need (declared once, defined in ArduDeck2.ino)
extern int currentCase;
extern const int MAX_CASES;
extern const char* menuItems[];

#endif
