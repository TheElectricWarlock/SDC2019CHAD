/*Code for the xbox controller, gathers the values from the controller, as well as checking if it is connected. 
 * Pins used Uno: D11, D12, D13. 
 * Pins used Mega: D20, D21, D22 ??????
 */

#include <XBOXOLD.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
USBHub  Hub1(&Usb); // The controller has a built in hub, so this instance is needed
XBOXOLD Xbox(&Usb);


//to be determined how useful these would be
/*
//Storage Variables
int LeftStick[3];      //Stores the values for the Left stick, X-Axis = 0, Y-Axis = 1, Button State = 2
int RightStick[3];     //Stores the values for the right stick, X-Axis = 0, Y-Axis = 1, Button State = 2
int Triggers[2];       //Stores the values for the analog triggers, Left = 0, Right = 1. 
int Buttons[13];       //Stores Button Values, A = 0, B = 1, X = 2, Y = 3, LB = 4, RB = 5, Pad UP = 6, Pad Down = 7, Pad Left = 8, Pad Right = 9, Start = 10, Back = 11, Xbox = 12
*/

//Sets up the controller, checks if the controller is connect and so on. 
void XboxControllerSetup() {
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.println(F("\r\nOSC did not start"));
    while (1); // halt
  }
  Serial.println(F("\r\nXBOX Library Started"));
}

//need to sort through this stuff and see what is useful and what is not. 
/*
void loop() {
  Usb.Task();
  if (Xbox.XboxConnected) {
    if (Xbox.getButtonPress(BLACK) || Xbox.getButtonPress(WHITE)) {
      Serial.print("BLACK: ");
      Serial.print(Xbox.getButtonPress(BLACK));
      Serial.print("\tWHITE: ");
      Serial.println(Xbox.getButtonPress(WHITE));
      Xbox.setRumbleOn(Xbox.getButtonPress(BLACK), Xbox.getButtonPress(WHITE));
    } else
      Xbox.setRumbleOn(0, 0);

    if (Xbox.getAnalogHat(LeftHatX) > 7500 || Xbox.getAnalogHat(LeftHatX) < -7500 || Xbox.getAnalogHat(LeftHatY) > 7500 || Xbox.getAnalogHat(LeftHatY) < -7500 || Xbox.getAnalogHat(RightHatX) > 7500 || Xbox.getAnalogHat(RightHatX) < -7500 || Xbox.getAnalogHat(RightHatY) > 7500 || Xbox.getAnalogHat(RightHatY) < -7500) {
      if (Xbox.getAnalogHat(LeftHatX) > 7500 || Xbox.getAnalogHat(LeftHatX) < -7500) {
        Serial.print(F("LeftHatX: "));
        Serial.print(Xbox.getAnalogHat(LeftHatX));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(LeftHatY) > 7500 || Xbox.getAnalogHat(LeftHatY) < -7500) {
        Serial.print(F("LeftHatY: "));
        Serial.print(Xbox.getAnalogHat(LeftHatY));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(RightHatX) > 7500 || Xbox.getAnalogHat(RightHatX) < -7500) {
        Serial.print(F("RightHatX: "));
        Serial.print(Xbox.getAnalogHat(RightHatX));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(RightHatY) > 7500 || Xbox.getAnalogHat(RightHatY) < -7500) {
        Serial.print(F("RightHatY: "));
        Serial.print(Xbox.getAnalogHat(RightHatY));
      }
      Serial.println();
    }

    if (Xbox.getButtonClick(UP))
      Serial.println(F("Up"));
    if (Xbox.getButtonClick(DOWN))
      Serial.println(F("Down"));
    if (Xbox.getButtonClick(LEFT))
      Serial.println(F("Left"));
    if (Xbox.getButtonClick(RIGHT))
      Serial.println(F("Right"));

    if (Xbox.getButtonClick(START))
      Serial.println(F("Start"));
    if (Xbox.getButtonClick(BACK))
      Serial.println(F("Back"));
    if (Xbox.getButtonClick(L3))
      Serial.println(F("L3"));
    if (Xbox.getButtonClick(R3))
      Serial.println(F("R3"));

    if (Xbox.getButtonPress(A)) {
      Serial.print(F("A: "));
      Serial.println(Xbox.getButtonPress(A));
    }
    if (Xbox.getButtonPress(B)) {
      Serial.print(F("B: "));
      Serial.println(Xbox.getButtonPress(B));
    }
    if (Xbox.getButtonPress(X)) {
      Serial.print(F("X: "));
      Serial.println(Xbox.getButtonPress(X));
    }
    if (Xbox.getButtonPress(Y)) {
      Serial.print(F("Y: "));
      Serial.println(Xbox.getButtonPress(Y));
    }
    if (Xbox.getButtonPress(L1)) {
      Serial.print(F("L1: "));
      Serial.println(Xbox.getButtonPress(L1));
    }
    if (Xbox.getButtonPress(R1)) {
      Serial.print(F("R1: "));
      Serial.println(Xbox.getButtonPress(R1));
    }
  }
  delay(1);
} 

*/
