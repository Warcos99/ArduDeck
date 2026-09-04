#include "ForwardDeclarations.h"
#include <avr/pgmspace.h>

static bool charDirty = true;
static String printName;
static String printAdjective;
int* randomNums;
int nameSize = 100;
int adjSize = 100;

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
const char name60[] PROGMEM = "Avery";
const char name61[] PROGMEM = "Benjamin";
const char name62[] PROGMEM = "Scarlett";
const char name63[] PROGMEM = "Levi";
const char name64[] PROGMEM = "Harper";
const char name65[] PROGMEM = "Elias";
const char name66[] PROGMEM = "Nora";
const char name67[] PROGMEM = "Jack";
const char name68[] PROGMEM = "Isla";
const char name69[] PROGMEM = "Sebastian";
const char name70[] PROGMEM = "Luna";
const char name71[] PROGMEM = "Hudson";
const char name72[] PROGMEM = "Lucy";
const char name73[] PROGMEM = "Leo";
const char name74[] PROGMEM = "Chloe";
const char name75[] PROGMEM = "Ethan";
const char name76[] PROGMEM = "Hazel";
const char name77[] PROGMEM = "Lucas";
const char name78[] PROGMEM = "Eliana";
const char name79[] PROGMEM = "William";
const char name80[] PROGMEM = "Evelyn";
const char name81[] PROGMEM = "Mateo";
const char name82[] PROGMEM = "Isabella";
const char name83[] PROGMEM = "Elijah";
const char name84[] PROGMEM = "Mia";
const char name85[] PROGMEM = "James";
const char name86[] PROGMEM = "Sophia";
const char name87[] PROGMEM = "Henry";
const char name88[] PROGMEM = "Amelia";
const char name89[] PROGMEM = "Theodore";
const char name90[] PROGMEM = "Charlotte";
const char name91[] PROGMEM = "Oliver";
const char name92[] PROGMEM = "Olivia";
const char name93[] PROGMEM = "Noah";
const char name94[] PROGMEM = "Aurora";
const char name95[] PROGMEM = "Liam";
const char name96[] PROGMEM = "Linda";
const char name97[] PROGMEM = "George";
const char name98[] PROGMEM = "Lydia";
const char name99[] PROGMEM = "Robert";

const char* const name[] PROGMEM = {
    name00, name01, name02, name03, name04, name05, name06, name07, name08, name09,
    name10, name11, name12, name13, name14, name15, name16, name17, name18, name19,
    name20, name21, name22, name23, name24, name25, name26, name27, name28, name29,
    name30, name31, name32, name33, name34, name35, name36, name37, name38, name39,
    name40, name41, name42, name43, name44, name45, name46, name47, name48, name49,
    name50, name51, name52, name53, name54, name55, name56, name57, name58, name59,
    name60, name61, name62, name63, name64, name65, name66, name67, name68, name69,
    name70, name71, name72, name73, name74, name75, name76, name77, name78, name79,
    name80, name81, name82, name83, name84, name85, name86, name87, name88, name89,
    name90, name91, name92, name93, name94, name95, name96, name97, name98, name99
};

// adjectives
const char adjective00[] PROGMEM = "Nice";
const char adjective01[] PROGMEM = "Gross";
const char adjective02[] PROGMEM = "Pointed";
const char adjective03[] PROGMEM = "Dark";
const char adjective04[] PROGMEM = "Energetic";
const char adjective05[] PROGMEM = "Curious";
const char adjective06[] PROGMEM = "Sunny";
const char adjective07[] PROGMEM = "Ingenieous";
const char adjective08[] PROGMEM = "Easy";
const char adjective09[] PROGMEM = "Difficult";
const char adjective10[] PROGMEM = "Mousey";
const char adjective11[] PROGMEM = "Cordial";
const char adjective12[] PROGMEM = "Humble";
const char adjective13[] PROGMEM = "Pugnacious";
const char adjective14[] PROGMEM = "Aloof";
const char adjective15[] PROGMEM = "Opaque";
const char adjective16[] PROGMEM = "Cunning";
const char adjective17[] PROGMEM = "Slow";
const char adjective18[] PROGMEM = "Godly";
const char adjective19[] PROGMEM = "Devilish";
const char adjective20[] PROGMEM = "Adamant";
const char adjective21[] PROGMEM = "Animistic";
const char adjective22[] PROGMEM = "Antic";
const char adjective23[] PROGMEM = "Boorish";
const char adjective24[] PROGMEM = "Caustic";
const char adjective25[] PROGMEM = "Comely";
const char adjective26[] PROGMEM = "Naive";
const char adjective27[] PROGMEM = "Tardy";
const char adjective28[] PROGMEM = "Furtive";
const char adjective29[] PROGMEM = "Proud";
const char adjective30[] PROGMEM = "Greedy";
const char adjective31[] PROGMEM = "Tricky";
const char adjective32[] PROGMEM = "Fluttering";
const char adjective33[] PROGMEM = "Beautiful";
const char adjective34[] PROGMEM = "Adorable";
const char adjective35[] PROGMEM = "Shining";
const char adjective36[] PROGMEM = "Rude";
const char adjective37[] PROGMEM = "Polite";
const char adjective38[] PROGMEM = "Selfish";
const char adjective39[] PROGMEM = "Careless";
const char adjective40[] PROGMEM = "Careful";
const char adjective41[] PROGMEM = "Cowardly";
const char adjective42[] PROGMEM = "Still";
const char adjective43[] PROGMEM = "Odd";
const char adjective44[] PROGMEM = "Sturdy";
const char adjective45[] PROGMEM = "Simple";
const char adjective46[] PROGMEM = "Complex";
const char adjective47[] PROGMEM = "Calm";
const char adjective48[] PROGMEM = "Bored";
const char adjective49[] PROGMEM = "Fussy";
const char adjective50[] PROGMEM = "Horrid";
const char adjective51[] PROGMEM = "Dreadful";
const char adjective52[] PROGMEM = "Nasty";
const char adjective53[] PROGMEM = "Creepy";
const char adjective54[] PROGMEM = "Gloomy";
const char adjective55[] PROGMEM = "Crabby";
const char adjective56[] PROGMEM = "Angry";
const char adjective57[] PROGMEM = "Excited";
const char adjective58[] PROGMEM = "Friendly";
const char adjective59[] PROGMEM = "Moody";
const char adjective60[] PROGMEM = "Challenging";
const char adjective61[] PROGMEM = "Hard";
const char adjective62[] PROGMEM = "Snug";
const char adjective63[] PROGMEM = "Glassy";
const char adjective64[] PROGMEM = "Smooth";
const char adjective65[] PROGMEM = "Wrinkly";
const char adjective66[] PROGMEM = "Chilly";
const char adjective67[] PROGMEM = "Steaming";
const char adjective68[] PROGMEM = "Sloppy";
const char adjective69[] PROGMEM = "Slimy";
const char adjective70[] PROGMEM = "Bashful";
const char adjective71[] PROGMEM = "Scared";
const char adjective72[] PROGMEM = "Afraid";
const char adjective73[] PROGMEM = "Dull";
const char adjective74[] PROGMEM = "Meek";
const char adjective75[] PROGMEM = "Gentle";
const char adjective76[] PROGMEM = "Caring";
const char adjective77[] PROGMEM = "Hopeful";
const char adjective78[] PROGMEM = "Soaring";
const char adjective79[] PROGMEM = "Crawling";
const char adjective80[] PROGMEM = "Thrifty";
const char adjective81[] PROGMEM = "Piercing";
const char adjective82[] PROGMEM = "Creaky";
const char adjective83[] PROGMEM = "Famished";
const char adjective84[] PROGMEM = "Startled";
const char adjective85[] PROGMEM = "Ecstatic";
const char adjective86[] PROGMEM = "Cheerful";
const char adjective87[] PROGMEM = "Blithe";
const char adjective88[] PROGMEM = "Content";
const char adjective89[] PROGMEM = "Demanding";
const char adjective90[] PROGMEM = "Effortless";
const char adjective91[] PROGMEM = "Slick";
const char adjective92[] PROGMEM = "Obtuse";
const char adjective93[] PROGMEM = "Acute";
const char adjective94[] PROGMEM = "Striking";
const char adjective95[] PROGMEM = "Stunning";
const char adjective96[] PROGMEM = "Charming";
const char adjective97[] PROGMEM = "Vigilant";
const char adjective98[] PROGMEM = "Live";
const char adjective99[] PROGMEM = "Dead";

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
  adjective55, adjective56, adjective57, adjective58, adjective59,
  adjective60, adjective61, adjective62, adjective63, adjective64,
  adjective65, adjective66, adjective67, adjective68, adjective69,
  adjective70, adjective71, adjective72, adjective73, adjective74,
  adjective75, adjective76, adjective77, adjective78, adjective79,
  adjective80, adjective81, adjective82, adjective83, adjective84,
  adjective85, adjective86, adjective87, adjective88, adjective89,
  adjective90, adjective91, adjective92, adjective93, adjective94,
  adjective95, adjective96, adjective97, adjective98, adjective99
};

String getWord(const char* const table[], uint8_t index) {
  char buf[16];
  strncpy_P(buf, (const char*)pgm_read_ptr(&table[index]), sizeof(buf) - 1);
  buf[sizeof(buf) - 1] = '\0';
  return String(buf);
}

String getWordString(uint8_t n1, uint8_t n2, uint8_t n3) {
  //n3 is a signifier for the type of word string we need. 1=names 2=adjectives
  String word1, word2, word3, allWords;
  if (n3 == 1){
    word1 = getWord(name, n1);
    word2 = getWord(name, n2);
  } else if (n3 == 2){
    word1 = getWord(adjective, n1);
    word2 = getWord(adjective, n2);
  }
allWords = word1 + " " + word2;
return allWords;
}

int* generate6Random() {
    //previous version had me generating 6 numbers.  now i only need 4
    // can't be bothered to change the name, deal with it
  static int nums[4];
  nums[0] = random(0, nameSize);
  nums[1] = random(0, nameSize);
  nums[2] = random(0, adjSize);
  nums[3] = random(0, adjSize);
  return nums;
}

// user actions

void char_singleClick() {
  randomNums = generate6Random();
  printName = getWordString(randomNums[0], randomNums[1], 1);
  printAdjective = getWordString(randomNums[2], randomNums[3], 2);
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
  printName = getWordString(randomNums[0], randomNums[1], 1);
  printAdjective = getWordString(randomNums[2], randomNums[3], 2);
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
