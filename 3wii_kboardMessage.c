/*
   Keyboard Message test For the Arduino Leonardo and Micro,
      Sends a text string when a button is pressed.
   The circuit:
   * pushbutton attached from pin 4 to +5V
   * 10-kilohm resistor attached from pin 4 to ground
*/

#include "Keyboard.h"
const int buttonPin = 4; // input pin for pushbutton
int previousButtonState = HIGH; // for checking the state of a pushButton
int counter = 0; // button push counter

void setup() {
   pinMode(buttonPin, INPUT); // make the pushButton pin an input:
   Keyboard.begin(); // initialize control over the keyboard:
}

void loop() {
   int buttonState = digitalRead(buttonPin); // read the pushbutton:
   if ((buttonState != previousButtonState)&& (buttonState == HIGH)) // and it's currently pressed: {
      // increment the button counter
      counter++;
      // type out a message
      Keyboard.print("You pressed the button ");
      Keyboard.print(counter);
      Keyboard.println(" times.");
   }
   // save the current button state for comparison next time:
   previousButtonState = buttonState;
}
