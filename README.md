# ArduDeck

---

## 1. What is this project?

ArduDeck is an arduino based platform for running a 16x2lcd screen and rotary encoder, and easily add your own applications to a menu system.  The bulk of the work here is simply a menu system that you can use to house an applets you build.  As I develop more apps for the device, they will be added here.  

The project assumes you are running a 5pin rotary encoder and 1602 LCD screen.  The wiring diagrams and PCB files can be found below:


---

## 2. Hardware

Follow the wiring diagram to make your own, or get a PCB printed.

- The microcontroller is an arduino nano

- the screen is a 1602 LCD display (14 pins)

- user interface is a 5 pin rotary encoder and 1 push button

- The PCB requires one 200ohm and one 100kohm resister.  One 1uF and one 0.1uF Capacitor. A pushdown resistor for  the home button, and an NE556 Timer for debouncing the switch. (you only really need a 555 timer, but I only have 556, so the PCB design uses that.)
- The battery is a 3.7V 840mAh LiPo batter on a battery charger (TP4056) breakout board.  
	+ Do not turn on device while battery is charging
- That battery gets fed into a voltage regulator breakout board set to 7.8V.

---

## 3. Software

The program is divided into 3 sections:  
 
- main.ino
- forward declarations
- functions.ino
- menu.ino
- sketch.yaml
- applets

### main.ino

*ArduDeck2.ino* is the main arduino file at the top of the chain. This hosts some variable declarations, the setup and the loop. 

### forward declaration

*ForwardDeclarations.h* is here because the code compiles with ArduDeck.ino at the very top. At this point there are tons of functions and variables that will be called later in the code when an applet is run that Arduino does not know about yet.  It throws an error saying something along the lines of "you are writing *function* in your code, but I do not see *function* anywhere!".  So with *ForwardDeclarations.h* we are only putting in those functions here at the top. we are not defining anything, just leaving a space so the program does not freak out.

### functions.ino

There are some functions we want to define and declare for the whole program, not just for individual applets.  Those global functions live here.  Primarily the functions defining button inputs live here now.

### menu.ino

In *menu.ino* we are creating the menu that the applets can live in and be called from.

### yaml.sketch

you do not need this at all, unless you are using arduino-cli. If you are using arduino-cli, make sure you update this file with the correct port and board.

### applets

Here is the bread and potatoes of the program.  This is set up so you can make the applet you need into it's own file, keeping organization simple.

---

## 4. Making a new applet

you can use staticAppletTemplate.md to start your applet.  Just make sure it is in a .ino file. the template is in markdown to avoid arduino confusing it as an actual program file.
you will need to do the following:  

- rename variables
	+ throughout the template you will see prenamed variables that will need to be renamed based on your applet. Let's say you are making a counter applet that increases count everytime you press the button.
	+ Every instance of appletDirty -> counterDirty
	+ applet_singleClick() -> counter_singleClick()
	+ applet_clockWise() -> counter_clockWise()
		* and every other instance like this
	+ appletScreen -> counterScreen
	+ You can use a shortcut in vim to replace all instances of "applet" to "counter" for simplicity.
- In *ForwardDeclarations.h* add the following code
	+ extern Screen counterScreen
- On *menu.ino*, add case for new menu item under "void menu_singleClick()"

With all that done, you can now begin to program your applet. There are different functions for the different actions you can make (click, clockwise, counterclockwise, menu_click) and different functions for different parts of the program (on_enter, update).  To only update the screen when a change is made, a "dirty" variable is used.  whenever you want the screen to update, set dirty=true, and whenever you don't need to update set dirty=false.  

The 1602 LCD display has limitations on how fast it can refresh, and if you update the screen too often, the screen will appear like it's not very bright.  We want to update the screen as little as possible.

If you need to create any custom characters, you will need to do so in ArduDeck2.ino



**That's basically it!**
