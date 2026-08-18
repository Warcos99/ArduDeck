#ifndef FORWARD_DECLARATIONS_H
#define FORWARD_DECLARATIONS_H

// Event Types, once event is polled, this helps determine
// what kind of event it was.
enum EventType {
  EVT_NONE = 0,
  EVT_ROT_CW,
  EVT_ROT_CCW,
  EVT_SINGLE_CLICK,
  EVT_DOUBLE_CLICK
};

// struct Event sets up the format that events show up as
struct Event {
  EventType type;
  int value;
};

// Screen Type
// Each "applet" (menu, info, etc.) fills one of
// these out. Only currentScreen's handlers ever run

struct Screen {
  void (*onSingleClick)();
  void (*onDoubleClick)();
  void (*onClockWise)();
  void (*onCounterClockWise)();
  void (*onEnter)();
  void (*update)();
};

extern Screen* currentScreen;
void setScreen(Screen* s);

// ----------------------
// Function Declarations


Event pollEvent();
void navigation(Event evt);
void runScreen();

// Menu
void displayMenu();
extern Screen menuScreen;

// Info
void displayInfo();
extern Screen infoScreen;

// MTG Life counter
extern Screen mtgScreen;
void drawArrows();
void drawMTGscreen();

// Dice Roller
extern Screen diceScreen;

// Counter
extern Screen counterScreen;

// Blink
extern Screen blinkScreen;

// Credits
extern Screen creditsScreen;

// BTN Test
extern Screen btnTestScreen;


// Shared globals other files need (declared once, defined in ArduDeck2.ino)
extern int currentCase;
extern const int MAX_CASES;
extern const char* menuItems[];

#endif
