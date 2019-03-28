/* Control systems code, used to perform any of the calculations and checks for controlling the bot
 *  
 *  
 */
//Variables
const int ConstantSpeeds[5] = {50,100,150,200,255}; //Value at which the wheels will run at when constant speed buttons are pressed
int ConstantSpeed = 50;
unsigned int ConstantSpeedIndex = 0; 

void BatteryCheck(){
  
}


void ControlSystem(){

Usb.Task();
  if(Xbox.XboxReceiverConnected) {
    if(Xbox.Xbox360Connected[0]) {

      //Constant Speed Changes by increasing the index, which steps up the constant speed
      if(Xbox.getButtonClick(START) && (ConstantSpeedIndex < 4)){
        
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
        ConstantSpeedIndex--;
        ConstantSpeed = ConstantSpeeds[ConstantSpeedIndex];
        if(DebugFlag == 1){
          Serial.print("Decreasing Speed Constant");
          Serial.print(" Index:");
          Serial.println(ConstantSpeedIndex);
        }
      }
      
       /*Variable movement, changes speed based on position of stick
        * 
        */
      
       //Movement Forwards Variable
       if((Xbox.getAnalogHat(LeftHatY) > 8000) && ((Xbox.getAnalogHat(LeftHatX) < 8000) && (Xbox.getAnalogHat(LeftHatX) > -8000))){

             ForwardsMotion(map(Xbox.getAnalogHat(LeftHatY), 8000, pow(2,15), 0, 255));
             
             if(DebugFlag == 1){
             Serial.print("Moving Forwards Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getAnalogHat(LeftHatY), 8000, pow(2,15), 0, 255));
             }
       }

       //Movement Backwards Variable
       else if((Xbox.getAnalogHat(LeftHatY) < -8000) && ((Xbox.getAnalogHat(LeftHatX) < 8000) && (Xbox.getAnalogHat(LeftHatX) > -8000))){

             BackwardsMotion(map(Xbox.getAnalogHat(LeftHatY), -8000, pow(-2,15), 0, 255));
             
             if(DebugFlag == 1){
             Serial.print("Moving Backwards Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getAnalogHat(LeftHatY), -8000, pow(-2,15), 0, 255));
             }
       }

      //Movement Left Variable
      else if((Xbox.getAnalogHat(LeftHatX) < -8000) && ((Xbox.getAnalogHat(LeftHatY) < 8000) && (Xbox.getAnalogHat(LeftHatY) > -8000))){
             
             StLeftMotion(map(Xbox.getAnalogHat(LeftHatX), -8000, pow(-2,15), 0, 255));
             
             if(DebugFlag == 1){
             Serial.print("Moving Left Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getAnalogHat(LeftHatX), -8000, pow(-2,15), 0, 255));
             }
      }

      //Movement Right Variable
      else if((Xbox.getAnalogHat(LeftHatX) > 8000) && ((Xbox.getAnalogHat(LeftHatY) < 8000) && (Xbox.getAnalogHat(LeftHatY) > -8000))){

             StRightMotion(map(Xbox.getAnalogHat(LeftHatX), 8000, pow(2,15), 0, 255));
             
             if(DebugFlag == 1){
             Serial.print("Moving Right Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getAnalogHat(LeftHatX), 8000, pow(2,15), 0, 255));
             }
      }

      //Rotation CW Variable
      if(Xbox.getButtonPress(R2) > 20){

             RotationCWMotion(map(Xbox.getButtonPress(R2), 20, 255, 0, 255));
             
             if(DebugFlag == 1){
             Serial.print("Moving CW Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getButtonPress(R2), 20, 255, 0, 255));
             }
      }

      //Rotation CCW Variable
      else if(Xbox.getButtonPress(L2) > 20){

            RotationCWMotion(map(Xbox.getButtonPress(L2), 20, 255, 0, 255));
            
            if(DebugFlag == 1){
             Serial.print("Rotating CCW Variable");
             Serial.print(" Speed:");
             Serial.println(map(Xbox.getButtonPress(L2), 20, 255, 0, 255));
             }
      }
      
      
      /*Constant Movement, Keeps speed constant
       * 
       * 
       */
   
       //Movement Forwards Consant
       if(Xbox.getButtonPress(UP)){

             ForwardsMotion(ConstantSpeed);
             
             if(DebugFlag == 1){
             Serial.print("Moving forwards Constant");
             Serial.print(" Speed:");
             Serial.println(ConstantSpeed);
             }
        }

       //Movement Backwards Constant
       else if(Xbox.getButtonPress(DOWN)){

             BackwardsMotion(ConstantSpeed);
             
             if(DebugFlag == 1){
                 Serial.print("Moving backwards Constant");
                 Serial.print(" Speed:");
                 Serial.println(ConstantSpeed);
             }
       }

       //Movement Left Constant
       else if(Xbox.getButtonPress(LEFT)){

           StLeftMotion(ConstantSpeed);
           
           if(DebugFlag == 1){
               Serial.print("Moving left Constant");
               Serial.print(" Speed:");
               Serial.println(ConstantSpeed);
           }
        }

       //Movement Right Constant
       else if(Xbox.getButtonPress(RIGHT)){

          StRightMotion(ConstantSpeed);
          
          if(DebugFlag == 1){
              Serial.print("Moving right Constant");
              Serial.print(" Speed:");
              Serial.println(ConstantSpeed);
          }
       }

       //Rotation CW Static 
       else if(Xbox.getButtonPress(R1)){
            
           RotationCWMotion(ConstantSpeed);
           
           if(DebugFlag == 1){
               Serial.print("Moving CW Constant");
               Serial.print(" Speed:");
               Serial.println(ConstantSpeed);
           }
       }

       //Rotation CCW Static
       else if(Xbox.getButtonPress(L1)){

           RotationCCWMotion(ConstantSpeed);
           
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
