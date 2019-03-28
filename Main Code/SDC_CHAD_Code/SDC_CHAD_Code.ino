/*This is the code used for the C.H.A.D robot for SDC 2019
 * 
 * If the code does not compile for you due to some random issues
 * make sure you're using the libraries on the libraries folder
 */
int DebugFlag = 1;

//Files to be included in the main code 
#include "Control.h"          //Code used for the xbox360 controller
#include "Motion.h"           //Code used for the omni wheels movement
#include "Power_Management.h" //Code used for the battery and power management code
#include "ControlSystems.h"   //All code which performs all the controlling for the bot motion and other features
void setup(){
  // put your setup code here, to run once:
  Serial.begin(9600);
  XboxControllerSetup();
  MotionSetup();
}

void loop(){
  // put your main code here, to run repeatedly:
  //ControlTest();
  ControlSystem();
}
