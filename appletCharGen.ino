#include "ForwardDeclarations.h"
#include <avr/pgmspace.h>

static bool charDirty = true;
static String printName;
static String printAdjective;
int* randomNums;
int nameSize = 60;
int adjSize = 60;

// names
const char name00[] PROGMEM = "Adran";
const char name01[] PROGMEM = "Fivin";
const char name02[] PROGMEM = "Ivellios";
const char name03[] PROGMEM = "Naal";
const char name04[] PROGMEM = "Theren";
const char name05[] PROGMEM = "Orsik";
const char name06[] PROGMEM = "Gimurt";
const char name07[] PROGMEM = "Aldrik";
const char name08[] PROGMEM = "Eddie";
const char name09[] PROGMEM = "Lindal";
const char name10[] PROGMEM = "Oswalt";
const char name11[] PROGMEM = "Sam";
const char name12[] PROGMEM = "Ulmo";
const char name13[] PROGMEM = "Fahim";
const char name14[] PROGMEM = "Bryant";
const char name15[] PROGMEM = "Everard";
const char name16[] PROGMEM = "Miles";
const char name17[] PROGMEM = "Hugo";
const char name18[] PROGMEM = "Vincent";
const char name19[] PROGMEM = "Moritz";
const char name20[] PROGMEM = "Neva";
const char name21[] PROGMEM = "Isabel";
const char name22[] PROGMEM = "Ynes";
const char name23[] PROGMEM = "Elena";
const char name24[] PROGMEM = "Tatyana";
const char name25[] PROGMEM = "Sofiya";
const char name26[] PROGMEM = "Alfhild";
const char name27[] PROGMEM = "Helga";
const char name28[] PROGMEM = "Fumio";
const char name29[] PROGMEM = "Jun";
const char name30[] PROGMEM = "Elsbeth";
const char name31[] PROGMEM = "Lucia";
const char name32[] PROGMEM = "Anna";
const char name33[] PROGMEM = "Agatha";
const char name34[] PROGMEM = "Cecilia";
const char name35[] PROGMEM = "Margot";
const char name36[] PROGMEM = "Adelaide";
const char name37[] PROGMEM = "Emma";
const char name38[] PROGMEM = "Millicent";
const char name39[] PROGMEM = "Jacoba";
const char name40[] PROGMEM = "Copperkettle";
const char name41[] PROGMEM = "Tenpenny";
const char name42[] PROGMEM = "Goodbarrel";
const char name43[] PROGMEM = "Galanodel";
const char name44[] PROGMEM = "Firahel";
const char name45[] PROGMEM = "Caphaxath";
const char name46[] PROGMEM = "Aranore";
const char name47[] PROGMEM = "Glanhig";
const char name48[] PROGMEM = "Helcral";
const char name49[] PROGMEM = "Strakeln";
const char name50[] PROGMEM = "Delmirev";
const char name51[] PROGMEM = "Kimbatuul";
const char name52[] PROGMEM = "Norixius";
const char name53[] PROGMEM = "Qyxpahrgh";
const char name54[] PROGMEM = "Cordelia";
const char name55[] PROGMEM = "Darcy";
const char name56[] PROGMEM = "Akhom";
const char name57[] PROGMEM = "Amenemhet";
const char name58[] PROGMEM = "Hugh";
const char name59[] PROGMEM = "Geoffrey";

const char* const name[] PROGMEM = {
    name00, name01, name02, name03, name04, name05, name06, name07, name08, name09,
    name10, name11, name12, name13, name14, name15, name16, name17, name18, name19,
    name20, name21, name22, name23, name24, name25, name26, name27, name28, name29,
    name30, name31, name32, name33, name34, name35, name36, name37, name38, name39,
    name40, name41, name42, name43, name44, name45, name46, name47, name48, name49,
    name50, name51, name52, name53, name54, name55, name56, name57, name58, name59
};

// adjectives
const char adjective00[] PROGMEM = "adj01";
const char adjective01[] PROGMEM = "adj02";
const char adjective02[] PROGMEM = "adj03";
const char adjective03[] PROGMEM = "adj04";
const char adjective04[] PROGMEM = "adj05";
const char adjective05[] PROGMEM = "adj06";
const char adjective06[] PROGMEM = "adj07";
const char adjective07[] PROGMEM = "adj08";
const char adjective08[] PROGMEM = "adj09";
const char adjective09[] PROGMEM = "adj10";
const char adjective10[] PROGMEM = "adj11";
const char adjective11[] PROGMEM = "adj12";
const char adjective12[] PROGMEM = "adj13";
const char adjective13[] PROGMEM = "adj14";
const char adjective14[] PROGMEM = "adj15";
const char adjective15[] PROGMEM = "adj16";
const char adjective16[] PROGMEM = "adj17";
const char adjective17[] PROGMEM = "adj18";
const char adjective18[] PROGMEM = "adj19";
const char adjective19[] PROGMEM = "adj20";
const char adjective20[] PROGMEM = "adj21";
const char adjective21[] PROGMEM = "adj22";
const char adjective22[] PROGMEM = "adj23";
const char adjective23[] PROGMEM = "adj24";
const char adjective24[] PROGMEM = "adj25";
const char adjective25[] PROGMEM = "adj26";
const char adjective26[] PROGMEM = "adj27";
const char adjective27[] PROGMEM = "adj28";
const char adjective28[] PROGMEM = "adj29";
const char adjective29[] PROGMEM = "adj30";
const char adjective30[] PROGMEM = "adj31";
const char adjective31[] PROGMEM = "adj32";
const char adjective32[] PROGMEM = "adj33";
const char adjective33[] PROGMEM = "adj34";
const char adjective34[] PROGMEM = "adj35";
const char adjective35[] PROGMEM = "adj36";
const char adjective36[] PROGMEM = "adj37";
const char adjective37[] PROGMEM = "adj38";
const char adjective38[] PROGMEM = "adj39";
const char adjective39[] PROGMEM = "adj40";
const char adjective40[] PROGMEM = "adj41";
const char adjective41[] PROGMEM = "adj42";
const char adjective42[] PROGMEM = "adj43";
const char adjective43[] PROGMEM = "adj44";
const char adjective44[] PROGMEM = "adj45";
const char adjective45[] PROGMEM = "adj46";
const char adjective46[] PROGMEM = "adj47";
const char adjective47[] PROGMEM = "adj48";
const char adjective48[] PROGMEM = "adj49";
const char adjective49[] PROGMEM = "adj50";
const char adjective50[] PROGMEM = "adj51";
const char adjective51[] PROGMEM = "adj52";
const char adjective52[] PROGMEM = "adj53";
const char adjective53[] PROGMEM = "adj54";
const char adjective54[] PROGMEM = "adj55";
const char adjective55[] PROGMEM = "adj56";
const char adjective56[] PROGMEM = "adj57";
const char adjective57[] PROGMEM = "adj58";
const char adjective58[] PROGMEM = "adj59";
const char adjective59[] PROGMEM = "adj60";

const char* const adjective[] PROGMEM = {
  adjective00, adjective01, adjective02, adjective03, adjective04,
  adjective05, adjective06, adjective07, adjective08, adjective09,
  adjective10, adjective11, adjective12, adjective13, adjective14,
  adjective15, adjective16, adjective17, adjective18, adjective19,
  adjective20, adjective21, adjective22, adjective23, adjective24,
  adjective25, adjective26, adjective27, adjective28, adjective29,
  adjective30, adjective31, adjective32, adjective33, adjective34,
  adjective35, adjective36, adjective37, adjective38, adjective39,
  adjective40, adjective41, adjective42, adjective43, adjective44,
  adjective45, adjective46, adjective47, adjective48, adjective49,
  adjective50, adjective51, adjective52, adjective53, adjective54,
  adjective55, adjective56, adjective57, adjective58, adjective59
};

String getWord(const char* const table[], uint8_t index) {
  char buf[16];
  strncpy_P(buf, (const char*)pgm_read_ptr(&table[index]), sizeof(buf) - 1);
  buf[sizeof(buf) - 1] = '\0';
  return String(buf);
}

String getWordString(uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4) {
  //n4 is a signifier for the type of word string we need. 1=names 2=adjectives
  String word1, word2, word3, allWords;
  if (n4 == 1){
    word1 = getWord(name, n1);
    word2 = getWord(name, n2);
    word3 = getWord(name, n3);
  } else if (n4 == 2){
    word1 = getWord(adjective, n1);
    word2 = getWord(adjective, n2);
    word3 = getWord(adjective, n3);
  }
allWords = word1 + " | " + word2 + " | " + word3;
return allWords;
}

int* generate6Random() {
  static int nums[6];
  nums[0] = random(0, nameSize);
  nums[1] = random(0, nameSize);
  nums[2] = random(0, nameSize);
  nums[3] = random(0, adjSize);
  nums[4] = random(0, adjSize);
  nums[5] = random(0, adjSize);
  return nums;
}

// user actions

void char_singleClick() {
  randomNums = generate6Random();
  printName = getWordString(randomNums[0], randomNums[1], randomNums[2], 1);
  printAdjective = getWordString(randomNums[3], randomNums[4], randomNums[5], 2);
  charDirty = true;
}

void char_menuClick() {
  setScreen(&menuScreen);
}

void char_clockWise() {
  lcd.scrollDisplayLeft();
}

void char_counterClockWise() {
  lcd.scrollDisplayRight();
}

// on enter
void char_onEnter() {
  randomNums = generate6Random();
  printName = getWordString(randomNums[0], randomNums[1], randomNums[2], 1);
  printAdjective = getWordString(randomNums[3], randomNums[4], randomNums[5], 2);
  charDirty = true;
}

// display
void char_update() {
  if (!charDirty) {
    return;
  }
  charDirty = false;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(printName);
  lcd.setCursor(0,1);
  lcd.print(printAdjective);
}

// screen object
Screen charScreen = {
  char_singleClick,
  char_menuClick,
  char_clockWise,
  char_counterClockWise,
  char_onEnter,
  char_update
};
