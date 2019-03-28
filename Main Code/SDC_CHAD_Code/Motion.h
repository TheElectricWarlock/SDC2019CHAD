/*This is the code used for the motion of the omni wheels. 
 * 
 * pinout used for Arduino mega
 * 
 * Motor numbering: Front Left = 1, Front Right = 2, Back Left = 3, Back Right = 4. 
 */

//PWM signals for the motors, controls their speed
#define PWMMotor1 4
#define PWMMotor2 5
#define PWMMotor3 6
#define PWMMotor4 7

//Direction pins for motor 1
#define CWMotor1 22
#define CCWMotor1 23

//Direction pins for motor 2
#define CWMotor2 24
#define CCWMotor2 25

//Direction pins for motor 3
#define CWMotor3 26
#define CCWMotor3 27

//Direction pins for motor 4
#define CWMotor4 28
#define CCWMotor4 29

//Variables
const int AnalogMaximum = 1000; //Maximum axis value for analog sticks



//Movement Functions 

void MotionSetup(){

  //Setup for the speed pins
  pinMode(PWMMotor1, OUTPUT);
  pinMode(PWMMotor2, OUTPUT);
  pinMode(PWMMotor3, OUTPUT);
  pinMode(PWMMotor4, OUTPUT);

  //Setup for direction pins
  pinMode(CWMotor1, OUTPUT);
  pinMode(CCWMotor1, OUTPUT);

  pinMode(CWMotor2, OUTPUT);
  pinMode(CCWMotor2, OUTPUT);
  
  pinMode(CWMotor3, OUTPUT);
  pinMode(CCWMotor3, OUTPUT);
  
  pinMode(CWMotor4, OUTPUT);
  pinMode(CCWMotor4, OUTPUT);
  
}

//Forwards Motion (All wheels move forwards)
void ForwardsMotion(int Speed){

  //Sets the first motor to go forward
  digitalWrite(CWMotor1, HIGH);
  digitalWrite(CCWMotor1, LOW); 

  //Sets the second motor to go forward
  digitalWrite(CWMotor2, HIGH);
  digitalWrite(CCWMotor2, LOW); 

  //Sets the third motor to go forward
  digitalWrite(CWMotor3, HIGH);
  digitalWrite(CCWMotor3, LOW); 

  //Sets the third motor to go forward  
  digitalWrite(CWMotor4, HIGH);
  digitalWrite(CCWMotor4, LOW); 

  //Sets speeds for all of the motors 
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}

//Backwards Motion (All wheels move backwards)
void BackwardsMotion(int Speed){
   //Sets the first motor to go backwards
  digitalWrite(CWMotor1, LOW);
  digitalWrite(CCWMotor1, HIGH); 

  //Sets the second motor to go backwards
  digitalWrite(CWMotor2, LOW);
  digitalWrite(CCWMotor2, HIGH); 

  //Sets the third motor to go backwards
  digitalWrite(CWMotor3, LOW);
  digitalWrite(CCWMotor3, HIGH); 

  //Sets the third motor to go backwards
  digitalWrite(CWMotor4, LOW);
  digitalWrite(CCWMotor4, HIGH); 

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}


//Left Straffle 
void StLeftMotion(int Speed){
 //Sets the first motor to go backwards
  digitalWrite(CWMotor1, LOW);
  digitalWrite(CCWMotor1, HIGH); 

  //Sets the second motor to go forwards
  digitalWrite(CWMotor2, HIGH);
  digitalWrite(CCWMotor2, LOW); 

  //Sets the third motor to go forwards
  digitalWrite(CWMotor3, HIGH);
  digitalWrite(CCWMotor3, LOW); 

  //Sets the third motor to go backwards 
  digitalWrite(CWMotor4, LOW);
  digitalWrite(CCWMotor4, HIGH); 

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}

//Right Straffle 
void StRightMotion(int Speed){
  //Sets the first motor to go forwards
  digitalWrite(CWMotor1, HIGH);
  digitalWrite(CCWMotor1, LOW); 

  //Sets the second motor to go backwards
  digitalWrite(CWMotor2, LOW);
  digitalWrite(CCWMotor2, HIGH); 

  //Sets the third motor to go backwards
  digitalWrite(CWMotor3, LOW);
  digitalWrite(CCWMotor3, HIGH); 

  //Sets the third motor to go forward  
  digitalWrite(CWMotor4, HIGH);
  digitalWrite(CCWMotor4, LOW); 

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}

//Diagonal Front Left
void DiagonalFLMotion(int Speed){
  //Sets the first motor disabled
  digitalWrite(CWMotor1, LOW);
  digitalWrite(CCWMotor1, LOW); 

  //Sets the second motor to go forward
  digitalWrite(CWMotor2, HIGH);
  digitalWrite(CCWMotor2, LOW); 

  //Sets the third motor to go forward
  digitalWrite(CWMotor3, HIGH);
  digitalWrite(CCWMotor3, LOW); 

  //Sets the third motor disabled  
  digitalWrite(CWMotor4, LOW);
  digitalWrite(CCWMotor4, LOW); 

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,0);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,0);
}

//Diagonal Front Right
void DiagonalFRMotion(int Speed){
  //Sets the first motor to go forward
  digitalWrite(CWMotor1, HIGH);
  digitalWrite(CCWMotor1, LOW); 

  //Sets the second motor to disabled
  digitalWrite(CWMotor2, LOW);
  digitalWrite(CCWMotor2, LOW); 

  //Sets the third motor to disabled
  digitalWrite(CWMotor3, LOW);
  digitalWrite(CCWMotor3, LOW); 

  //Sets the third motor to go forward  
  digitalWrite(CWMotor4, HIGH);
  digitalWrite(CCWMotor4, LOW); 

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,0);
  analogWrite(PWMMotor3,0);
  analogWrite(PWMMotor4,Speed);
}

//Diagonal Back Left
void DiagonalBLMotion(int Speed){
 //Sets the first motor to go backwards
  digitalWrite(CWMotor1, LOW);
  digitalWrite(CCWMotor1, HIGH); 

  //Sets the second motor to diabled
  digitalWrite(CWMotor2, LOW);
  digitalWrite(CCWMotor2, LOW); 

  //Sets the third motor to disabled
  digitalWrite(CWMotor3, LOW);
  digitalWrite(CCWMotor3, LOW); 

  //Sets the third motor to go backwards
  digitalWrite(CWMotor4, LOW);
  digitalWrite(CCWMotor4, HIGH); 

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,0);
  analogWrite(PWMMotor3,0);
  analogWrite(PWMMotor4,Speed); 
}

//Diagonal Back Right 
void DiagonalBRMotion(int Speed){
 //Sets the first motor to disabled
  digitalWrite(CWMotor1, LOW);
  digitalWrite(CCWMotor1, LOW); 

  //Sets the second motor to go backwards
  digitalWrite(CWMotor2, LOW);
  digitalWrite(CCWMotor2, HIGH); 

  //Sets the third motor to go backwards
  digitalWrite(CWMotor3, LOW);
  digitalWrite(CCWMotor3, HIGH); 

  //Sets the third motor to disabled 
  digitalWrite(CWMotor4, LOW);
  digitalWrite(CCWMotor4, LOW); 

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,0);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,0); 
}

//Rotation CW
void RotationCWMotion(int Speed){
  //Sets the first motor to go forward
  digitalWrite(CWMotor1, HIGH);
  digitalWrite(CCWMotor1, LOW); 

  //Sets the second motor to go backwards
  digitalWrite(CWMotor2, LOW);
  digitalWrite(CCWMotor2, HIGH); 

  //Sets the third motor to go forward
  digitalWrite(CWMotor3, HIGH);
  digitalWrite(CCWMotor3, LOW); 

  //Sets the third motor to go backwards
  digitalWrite(CWMotor4, LOW);
  digitalWrite(CCWMotor4, HIGH); 

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}

//Rotation CCW 
void RotationCCWMotion(int Speed){
  //Sets the first motor to go backwards
  digitalWrite(CWMotor1, LOW);
  digitalWrite(CCWMotor1, HIGH); 

  //Sets the second motor to go forward
  digitalWrite(CWMotor2, HIGH);
  digitalWrite(CCWMotor2, LOW); 

  //Sets the third motor to go backwards
  digitalWrite(CWMotor3, LOW);
  digitalWrite(CCWMotor3, HIGH); 

  //Sets the third motor to go forward  
  digitalWrite(CWMotor4, HIGH);
  digitalWrite(CCWMotor4, LOW); 

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}

//Wheels Stop
void StopMotion(){
  //Sets the first motor to go forward
  digitalWrite(CWMotor1, LOW);
  digitalWrite(CCWMotor1, LOW); 

  //Sets the second motor to go forward
  digitalWrite(CWMotor2, LOW);
  digitalWrite(CCWMotor2, LOW); 

  //Sets the third motor to go forward
  digitalWrite(CWMotor3, LOW);
  digitalWrite(CCWMotor3, LOW); 

  //Sets the third motor to go forward  
  digitalWrite(CWMotor4, LOW);
  digitalWrite(CCWMotor4, LOW); 

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,0);
  analogWrite(PWMMotor2,0);
  analogWrite(PWMMotor3,0);
  analogWrite(PWMMotor4,0);
}
