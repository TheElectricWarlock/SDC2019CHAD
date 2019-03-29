/* Control systems code, used to perform any of the calculations and checks for controlling the bot
 *  
 *  
 */
 
//Variables
const int ConstantSpeeds[5] = {50,100,150,200,255}; //Value at which the wheels will run at when constant speed buttons are pressed
int ConstantSpeed = 50;                             //Variable that holds the current speed value, initialized so the first value after bootup is 50. 
unsigned int ConstantSpeedIndex = 0;                //Keeps track of the current constant speed value
unsigned long TempVar;                              //Temporal variable for some values

void BatteryCheck(){
  //Reads the voltage of both batteries
  BatteryVoltageRead();

  //Sets the low voltage flag on if the voltage of the first battery is too low
  if((BatteryVoltage1 < DischargeVoltage) && (BatteryVoltage1 > 1)){
    LowVoltageFlag1 = 1;

    if(DebugFlag = 1){
     Serial.println("Warning Low Voltage on First Battery");
    }
  }

  //Sets the low voltage flag on if the voltage of the second battery is too low
  if((BatteryVoltage2 < DischargeVoltage) && (BatteryVoltage2 > 1)){
    LowVoltageFlag2 = 1;

    if(DebugFlag = 1){
    Serial.println("Warning Low Voltage on Second Battery");
    }
  }
}



//Controls the movement of the bot, amonst other features. 
void ControlSystem(){
Usb.Task();
  if(Xbox.XboxReceiverConnected) {
    if(Xbox.Xbox360Connected[0]) {

      //Constant Speed Changes by increasing the index, which steps up the constant speed
      if(Xbox.getButtonClick(START) && (ConstantSpeedIndex < 4)){
        ControllerVibrationStart(500);  //vibration to accentuate the steps
        
        ConstantSpeedIndex++; 
        ConstantSpeed = ConstantSpeeds[ConstantSpeedIndex];
        if(DebugFlag == 1){
          Serial.print("Increasing Speed Constant");
          Serial.print(" Index:");
          Serial.println(ConstantSpeedIndex);
        }
      }
      //Constant Speed Changes by decreasing the index, which down up the constant speed
      else if(Xbox.getButtonClick(BACK) && (ConstantSpeedIndex > 0)){
        ControllerVibrationStart(500);  //vibration to accentuate the steps
        
        ConstantSpeedIndex--;
        ConstantSpeed = ConstantSpeeds[ConstantSpeedIndex];
        if(DebugFlag == 1){
          Serial.print("Decreasing Speed Constant");
          Serial.print(" Index:");
          Serial.println(ConstantSpeedIndex);
        }
      }
      
       /*Variable movement, changes speed based on position of stick
        * Uses the left stick, L2 and R2 in order to control the movement with variable speed.
        */
      
       //Movement Forwards Variable
       if((Xbox.getAnalogHat(LeftHatY) > 8000) && ((Xbox.getAnalogHat(LeftHatX) < 8000) && (Xbox.getAnalogHat(LeftHatX) > -8000))){

             //Moves the bot forward at a variable speed set by the stick position and mapped by the mapping function to the pwm value
             ForwardsMotion(map(Xbox.getAnalogHat(LeftHatY), 8000, pow(2,15), 0, 255));

             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
             Serial.print("Moving Forwards Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getAnalogHat(LeftHatY), 8000, pow(2,15), 0, 255));
             }
       }

       //Movement Backwards Variable
       else if((Xbox.getAnalogHat(LeftHatY) < -8000) && ((Xbox.getAnalogHat(LeftHatX) < 8000) && (Xbox.getAnalogHat(LeftHatX) > -8000))){

             //Moves the bot backwards at a variable speed set by the stick position and mapped by the mapping function to the pwm value
             BackwardsMotion(map(Xbox.getAnalogHat(LeftHatY), -8000, pow(-2,15), 0, 255));

             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
             Serial.print("Moving Backwards Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getAnalogHat(LeftHatY), -8000, pow(-2,15), 0, 255));
             }
       }

      //Movement Left Variable
      else if((Xbox.getAnalogHat(LeftHatX) < -8000) && ((Xbox.getAnalogHat(LeftHatY) < 8000) && (Xbox.getAnalogHat(LeftHatY) > -8000))){
             
             //Moves the bot left at a variable speed set by the stick position and mapped by the mapping function to the pwm value
             StLeftMotion(map(Xbox.getAnalogHat(LeftHatX), -8000, pow(-2,15), 0, 255));

             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
             Serial.print("Moving Left Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getAnalogHat(LeftHatX), -8000, pow(-2,15), 0, 255));
             }
      }

      //Movement Right Variable
      else if((Xbox.getAnalogHat(LeftHatX) > 8000) && ((Xbox.getAnalogHat(LeftHatY) < 8000) && (Xbox.getAnalogHat(LeftHatY) > -8000))){

             //Moves the bot right at a variable speed set by the stick position and mapped by the mapping function to the pwm value
             StRightMotion(map(Xbox.getAnalogHat(LeftHatX), 8000, pow(2,15), 0, 255));

             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
             Serial.print("Moving Right Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getAnalogHat(LeftHatX), 8000, pow(2,15), 0, 255));
             }
      }

      //Rotation CW Variable
      if(Xbox.getButtonPress(R2) > 20){

             //Moves the bot clockwise at a variable speed set by the stick position and mapped by the mapping function to the pwm value
             RotationCWMotion(map(Xbox.getButtonPress(R2), 20, 255, 0, 255));

             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
             Serial.print("Moving CW Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getButtonPress(R2), 20, 255, 0, 255));
             }
      }

      //Rotation CCW Variable
      else if(Xbox.getButtonPress(L2) > 20){

             //Moves the bot counterclockwise at a variable speed set by the stick position and mapped by the mapping function to the pwm value
            RotationCWMotion(map(Xbox.getButtonPress(L2), 20, 255, 0, 255));

            //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
            if(DebugFlag == 1){
             Serial.print("Rotating CCW Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getButtonPress(L2), 20, 255, 0, 255));
             }
      }

      //to finish
      //Diagonal Front-Left Variable
      else if((Xbox.getAnalogHat(LeftHatX) < -8000) && (Xbox.getAnalogHat(LeftHatY) > 8000)){
             TempVar = sqrt(pow(Xbox.getAnalogHat(LeftHatX),2) + pow(Xbox.getAnalogHat(LeftHatY),2));
             
             //Moves the bot diagonally towards front left at a variable speed set by the stick position and mapped by the mapping function to the pwm value
             DiagonalFLMotion(map(TempVar, 0, 40000, 0, 255));

             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
             Serial.print("Moving Diagonal Front-Left Variable");
             Serial.print(" Speed:");
             Serial.println(map(TempVar, 0, 40000, 0, 255));//map(TempVar, 0, 46340, 0, 255)
             }
      }

      //Diagonal Front-Right Variable 
      else if((Xbox.getAnalogHat(LeftHatX) > 8000) && (Xbox.getAnalogHat(LeftHatY) > 8000)){
             TempVar = sqrt(pow(Xbox.getAnalogHat(LeftHatX),2) + pow(Xbox.getAnalogHat(LeftHatY),2));
             
             //Moves the bot diagonally towards front right at a variable speed set by the stick position and mapped by the mapping function to the pwm value
             DiagonalFRMotion(map(TempVar, 0, 40000, 0, 255));

             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
             Serial.print("Moving Diagonal Front-Right Variable");
             Serial.print(" Speed:");
             Serial.println(map(TempVar, 0, 40000, 0, 255));
             }
      }

      //Diagonal Back-Left Variable
      else if((Xbox.getAnalogHat(LeftHatX) < -8000) && (Xbox.getAnalogHat(LeftHatY) < -8000)){
             TempVar = sqrt(pow(Xbox.getAnalogHat(LeftHatX),2) + pow(Xbox.getAnalogHat(LeftHatY),2));
             
             //Moves the bot diagonally towards the back left at a variable speed set by the stick position and mapped by the mapping function to the pwm value
             DiagonalBLMotion(map(TempVar, 0, 40000, 0, 255));

             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
             Serial.print("Moving Diagonal Back-Left Variable");
             Serial.print(" Speed:");
             Serial.println(map(TempVar, 0, 40000, 0, 255));
             }
      }

      //Diagonal Back-Right Variable
      else if((Xbox.getAnalogHat(LeftHatX) > 8000) && (Xbox.getAnalogHat(LeftHatY) < -8000)){
             TempVar = sqrt(pow(Xbox.getAnalogHat(LeftHatX),2) + pow(Xbox.getAnalogHat(LeftHatY),2));
             
             //Moves the bot diagonally towards the back right at a variable speed set by the stick position and mapped by the mapping function to the pwm value
             DiagonalBRMotion(map(TempVar, 0, 40000, 0, 255));

             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
             Serial.print("Moving Diagonal Back-Right Variable");
             Serial.print(" Speed:");
             Serial.println(map(TempVar, 0, 40000, 0, 255));
             }
      }

      
      /*Constant Movement, Keeps speed constant
       * The constant speed drive uses Up, Down, Left, Right, L1 and R1 in order to move the bot at a steady constant speed. 
       * Using the "Back" and "Start" buttons increase the speed of constant speeds in 5 different steps. 
       */
   
       //Movement Forwards Consant
       if(Xbox.getButtonPress(UP)){

             //Moves the bot forward at a constant speed
             ForwardsMotion(ConstantSpeed);

             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
             Serial.print("Moving forwards Constant");
             Serial.print(" Speed:");
             Serial.println(ConstantSpeed);
             }
        }

       //Movement Backwards Constant
       else if(Xbox.getButtonPress(DOWN)){

             //Moves the bot backwards at a constant speed
             BackwardsMotion(ConstantSpeed);
             
             //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
             if(DebugFlag == 1){
                 Serial.print("Moving backwards Constant");
                 Serial.print(" Speed:");
                 Serial.println(ConstantSpeed);
             }
       }

       //Movement Left Constant
       else if(Xbox.getButtonPress(LEFT)){

           //Moves the bot left at a constant speed
           StLeftMotion(ConstantSpeed);

           //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm           
           if(DebugFlag == 1){
               Serial.print("Moving left Constant");
               Serial.print(" Speed:");
               Serial.println(ConstantSpeed);
           }
        }

       //Movement Right Constant
       else if(Xbox.getButtonPress(RIGHT)){

          //Moves the bot right at a constant speed
          StRightMotion(ConstantSpeed);

          //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
          if(DebugFlag == 1){
              Serial.print("Moving right Constant");
              Serial.print(" Speed:");
              Serial.println(ConstantSpeed);
          }
       }

       //Rotation CW Static 
       else if(Xbox.getButtonPress(R1)){

           //Moves the bot clockwise at a constant speed
           RotationCWMotion(ConstantSpeed);

           //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
           if(DebugFlag == 1){
               Serial.print("Moving CW Constant");
               Serial.print(" Speed:");
               Serial.println(ConstantSpeed);
           }
       }

       //Rotation CCW Static
       else if(Xbox.getButtonPress(L1)){

           //Moves the bot counterclockwise at a constant speed
           RotationCCWMotion(ConstantSpeed);

           //if debugging is enabled, it shows the direction and speed at which the bot is moving on serial comm
           if(DebugFlag == 1){
               Serial.print("Moving CCW Constant");
               Serial.print(" Speed:");
               Serial.println(ConstantSpeed);
           }
       }
       
       //Stop motion when nothing is being pressed
       else{
           StopMotion();
       }
     
    }
  }
}
