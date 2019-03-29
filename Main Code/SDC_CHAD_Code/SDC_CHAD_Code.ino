/*This is the code used for the C.H.A.D robot for SDC 2019
 * 
 * If the code does not compile for you due to some random issues
 * make sure you're using the libraries on the libraries folder
 */

//This flag enables serial output for debugging 
int DebugFlag = 1;

//Files to be included in the main code 
#include "Xbox_Control.h"          //Code used for the xbox360 controller
#include "Motion.h"           //Code used for the omni wheels movement
#include "Power_Management.h" //Code used for the battery and power management code
#include "Control_Systems.h"   //All code which performs all the controlling for the bot motion and other features
void setup(){
  
  Serial.begin(9600);
  XboxControllerSetup();
  MotionSetup();
}

void loop(){
  
  //ControlTest(); //Enable if you need to test the controller's input, but disable everything else.

 //Checks battery voltage, if battery voltage too low, it will engage safety measures
  BatteryCheck();

  //Main code, runs if the battery voltage is not too low
  if(LowVoltageFlag1 == 0){
  //Checks the inputs from the code and controls the motion of the bot with them
  ControlSystem();

  //Stops any vibration
  ControllerVibrationStop();
  }
  
}
