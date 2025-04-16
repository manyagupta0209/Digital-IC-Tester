#include <LiquidCrystal.h>
#include  "keypad.h"
#include "ictests.h"
#define ZIF_PIN(pin) zifPinMap[pin]

const int zifPinMap[] = {
  -1,   // dummy 0th index to align array with 1-based pin numbers
	34,   // ZIF Pin 1 -> Arduino Pin 22
	36,   // ZIF Pin 2 -> Arduino Pin 23
	38,   // ZIF Pin 3
	40,   // ZIF Pin 4
	42,   // ZIF Pin 5
	44,   // ZIF Pin 6
	46,   // ZIF Pin 7
	48,   // ZIF Pin 8
	50,   // ZIF Pin 9
	52,   // ZIF Pin 10
	53,   // ZIF Pin 11
	51,   // ZIF Pin 12
	49,   // ZIF Pin 13
	47,   // ZIF Pin 14
	45,   // ZIF Pin 15
	43,   // ZIF Pin 16
	41,   // ZIF Pin 17
	39,   // ZIF Pin 18
	37,   // ZIF Pin 19
	35,   // ZIF Pin 20
};

// Initialize the JHD162A LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Initialize custom keypad class
matrix_keypad keypad(28, 26, 24, 22, 23, 29, 27, 25); // Adjust according to your setup


void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);         // 16 columns, 2 rows
  keypad.init();            // Initialize custom keypad
  lcd.print("Enter: ");
}

String buffer = "";

void loop() {
 char key = keypad.key_in();
 if (key != 0) {
    if (key == 'e') {
      lcd.setCursor(0, 1);
      lcd.print("Entered: ");
      lcd.print(buffer);
      delay(2000);

      lcd.clear();
      bool result = false;
      bool knownIC = true;

      if (buffer == "7400") {
        result = test7400();
      } else if (buffer == "7402") {
        Serial.print(test7402());
        result = test7402();
      } else if (buffer == "7404") {
        result = test7404();
      } else if (buffer == "7408") {
        result = test7408();  // AND Gate
      } else if (buffer == "7432") {
        result = test7432();  // OR Gate
      } else if (buffer == "7486") {
        result = test7486();  // XOR Gate
      } else if (buffer == "74266") {
        result = test74266(); // XNOR Gate
      } else {
        knownIC = false;
      }

      if (knownIC) {
        lcd.clear();
        lcd.print(result ? "IC is GOOD :)" : "IC is BAD :(");
      } else {
        lcd.print("Unknown IC");
      }

      delay(3000);
      lcd.clear();
      lcd.print("Enter IC No:");
      buffer = "";

    } else if (key == 'c') {
      buffer = "";
      lcd.setCursor(0, 1);
      lcd.print("                ");
    } else {
      buffer += key;
      lcd.setCursor(0, 1);
      lcd.print(buffer);
    }
  }
}