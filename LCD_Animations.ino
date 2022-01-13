//////////////IMPORTANT!/////////////
//Only compile this code on the arduino uno. If compiled on the ESP8266 it will not work properly.

/*
  LiquidCrystal Library - Hello World

  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch display a Rain Storm Animation
  on (Row0, Col0), --- (Row1,Col1)

  More info on custom icons at:
  https://www.engineersgarage.com/arduino/making-custom-characters-on-lcd-using-arduino/
  A useful tool to generate code for your visualisation is
  https://maxpromer.github.io/LCD-Character-Creator/

  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)



  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

// include the library code:
#include <LiquidCrystal.h>

//defining rain Icon
byte rainChar1[] = {
  B01110,
  B11110,
  B11111,
  B01101,
  B00001,
  B10010,
  B10010,
  B00100
};

byte rainChar2[] = {
  B00100,
  B01001,
  B01001,
  B10010,
  B10010,
  B00100,
  B00100,
  B01001
};

byte rainChar3[] = {
  B01110,
  B01111,
  B11111,
  B11111,
  B11110,
  B11001,
  B01001,
  B10010
};

byte rainChar4[] = {
  B10010,
  B00100,
  B00100,
  B01001,
  B01001,
  B10010,
  B10010,
  B00100
};






byte rainCharA[] = {
  B01110,
  B11110,
  B11111,
  B01100,
  B10001,
  B00010,
  B10010,
  B00100
};

byte rainCharB[] = {
  B00100,
  B01000,
  B01001,
  B10010,
  B10010,
  B00100,
  B00100,
  B01001
};

byte rainCharC[] = {
  B01110,
  B01111,
  B11111,
  B11111,
  B11110,
  B11000,
  B01001,
  B10010
};

byte rainCharD[] = {
  B10010,
  B00000,
  B00100,
  B00100,
  B01001,
  B01001,
  B10010,
  B10010
};

byte wind1[] = {
  B00000,
  B00000,
  B00000,
  B00011,
  B00111,
  B00111,
  B00111,
  B00011
};

byte wind2[] = {
  B11111,
  B11111,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte wind3[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B01110,
  B11111,
  B11111
};

byte wind4[] = {
  B11000,
  B11100,
  B11100,
  B11100,
  B11000,
  B00000,
  B00000,
  B00000,
};


// Second Frame
byte wind5[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B01000,
  B11100,
  B11110,
  B01111
};

byte wind6[] = {
  B00001,
  B00011,
  B00111,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000
};

byte wind7[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00010,
  B00111,
  B01111,
  B11110
};

byte wind8[] = {
  B11110,
  B01111,
  B00111,
  B00010,
  B00000,
  B00000,
  B00000,
  B00000
};




// initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void rainInit() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //creating all the characters
  lcd.createChar(1 , rainChar1); //Numbering should start at 1, not 0
  lcd.createChar(2 , rainChar2);
  lcd.createChar(3 , rainChar3);
  lcd.createChar(4 , rainChar4);
  lcd.createChar(5 , rainCharA);
  lcd.createChar(6 , rainCharB);
  lcd.createChar(7 , rainCharC);
  lcd.createChar(8 , rainCharD);
}

void rainAnim() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.write(2);
  lcd.setCursor(1, 0);
  lcd.write(3);
  lcd.setCursor(1, 1);
  lcd.write(4);
  lcd.setCursor(3, 0);
  lcd.setCursor(3, 3);
  delay (500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(5);
  lcd.setCursor(0, 1);
  lcd.write(6);
  lcd.setCursor(1, 0);
  lcd.write(7);
  lcd.setCursor(1, 1);
  lcd.write(8);
  lcd.setCursor(3, 0);
  lcd.setCursor(3, 3);
  delay (500);
}

void windInit() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //creating all the characters
  lcd.createChar(9 , wind1); //Numbering should start at 1, not 0
  lcd.createChar(10 , wind2);
  lcd.createChar(11 , wind3);
  lcd.createChar(12 , wind4);
  lcd.createChar(13 , wind5);
  lcd.createChar(14 , wind6);
  lcd.createChar(15 , wind7);
  lcd.createChar(16 , wind8);
}

void windAnim() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(9);
  lcd.setCursor(0,1);
  lcd.write(10);
  lcd.setCursor(1,0);
  lcd.write(11);
  lcd.setCursor(1,1);
  lcd.write(12);
  lcd.setCursor(3,0);
  lcd.setCursor(3,3);
  delay (500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(13);
  lcd.setCursor(0,1);
  lcd.write(14);
  lcd.setCursor(1,0);
  lcd.write(15);
  lcd.setCursor(1,1);
  lcd.write(16);
  lcd.setCursor(3,0);
  lcd.setCursor(3,3);
  delay (500);
}