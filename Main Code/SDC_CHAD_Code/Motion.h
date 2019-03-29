/*This is the code used for the motion of the omni wheels. 
 * 
 * pinout used for Arduino mega
 * 
 * Motor numbering: Front Left = 1, Front Right = 2, Back Left = 3, Back Right = 4. 
 */

//PWM signals for the motors, controls their speed
#define PWMMotor1 5
#define PWMMotor2 6
#define PWMMotor3 7
#define PWMMotor4 8

//Direction pins for motor 1
#define DirectionMotor1 22

//Direction pins for motor 2
#define DirectionMotor2 23

//Direction pins for motor 3
#define DirectionMotor3 24

//Direction pins for motor 4
#define DirectionMotor4 25

//Movement Functions 

void MotionSetup(){

  //Setup for the speed pins
  pinMode(PWMMotor1, OUTPUT);
  pinMode(PWMMotor2, OUTPUT);
  pinMode(PWMMotor3, OUTPUT);
  pinMode(PWMMotor4, OUTPUT);

  //Setup for direction pins
  pinMode(DirectionMotor1, OUTPUT);
  pinMode(DirectionMotor2, OUTPUT);
  pinMode(DirectionMotor3, OUTPUT);
  pinMode(DirectionMotor4, OUTPUT);
  
}

//Forwards Motion (All wheels move forwards)
void ForwardsMotion(int Speed){

  //Sets the first motor to go forward
  digitalWrite(DirectionMotor1, HIGH); 

  //Sets the second motor to go forward
  digitalWrite(DirectionMotor2, HIGH);

  //Sets the third motor to go forward
  digitalWrite(DirectionMotor3, HIGH);

  //Sets the third motor to go forward  
  digitalWrite(DirectionMotor4, HIGH);

  //Sets speeds for all of the motors 
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}

//Backwards Motion (All wheels move backwards)
void BackwardsMotion(int Speed){
   //Sets the first motor to go backwards
  digitalWrite(DirectionMotor1, LOW);

  //Sets the second motor to go backwards
  digitalWrite(DirectionMotor2, LOW);

  //Sets the third motor to go backwards
  digitalWrite(DirectionMotor3, LOW);

  //Sets the third motor to go backwards
  digitalWrite(DirectionMotor4, LOW);

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}


//Left Straffle 
void StLeftMotion(int Speed){
 //Sets the first motor to go backwards
  digitalWrite(DirectionMotor1, LOW);

  //Sets the second motor to go forwards
  digitalWrite(DirectionMotor2, HIGH);
  
  //Sets the third motor to go forwards
  digitalWrite(DirectionMotor3, HIGH);
  
  //Sets the third motor to go backwards 
  digitalWrite(DirectionMotor4, LOW);

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}

//Right Straffle 
void StRightMotion(int Speed){
  //Sets the first motor to go forwards
  digitalWrite(DirectionMotor1, HIGH);
  
  //Sets the second motor to go backwards
  digitalWrite(DirectionMotor2, LOW);

  //Sets the third motor to go backwards
  digitalWrite(DirectionMotor3, LOW);

  //Sets the third motor to go forward  
  digitalWrite(DirectionMotor4, HIGH);

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}

//Diagonal Front Left
void DiagonalFLMotion(int Speed){
  //Sets the first motor disabled
  digitalWrite(DirectionMotor1, LOW);

  //Sets the second motor to go forward
  digitalWrite(DirectionMotor2, HIGH);

  //Sets the third motor to go forward
  digitalWrite(DirectionMotor3, HIGH);
  
  //Sets the third motor disabled  
  digitalWrite(DirectionMotor4, LOW);
 
  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,0);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,0);
}

//Diagonal Front Right
void DiagonalFRMotion(int Speed){
  //Sets the first motor to go forward
  digitalWrite(DirectionMotor1, HIGH);

  //Sets the second motor to disabled
  digitalWrite(DirectionMotor2, LOW);

  //Sets the third motor to disabled
  digitalWrite(DirectionMotor3, LOW);
  
  //Sets the third motor to go forward  
  digitalWrite(DirectionMotor4, HIGH);
  
  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,0);
  analogWrite(PWMMotor3,0);
  analogWrite(PWMMotor4,Speed);
}

//Diagonal Back Left
void DiagonalBLMotion(int Speed){
 //Sets the first motor to go backwards
  digitalWrite(DirectionMotor1, LOW);

  //Sets the second motor to diabled
  digitalWrite(DirectionMotor2, LOW);

  //Sets the third motor to disabled
  digitalWrite(DirectionMotor3, LOW);
  
  //Sets the third motor to go backwards
  digitalWrite(DirectionMotor4, LOW);

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,0);
  analogWrite(PWMMotor3,0);
  analogWrite(PWMMotor4,Speed); 
}

//Diagonal Back Right 
void DiagonalBRMotion(int Speed){
 //Sets the first motor to disabled
  digitalWrite(DirectionMotor1, LOW);

  //Sets the second motor to go backwards
  digitalWrite(DirectionMotor2, LOW);

  //Sets the third motor to go backwards
  digitalWrite(DirectionMotor3, LOW);

  //Sets the third motor to disabled 
  digitalWrite(DirectionMotor4, LOW);

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,0);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,0); 
}

//Rotation CW
void RotationCWMotion(int Speed){
  //Sets the first motor to go forward
  digitalWrite(DirectionMotor1, HIGH);

  //Sets the second motor to go backwards
  digitalWrite(DirectionMotor2, LOW);

  //Sets the third motor to go forward
  digitalWrite(DirectionMotor3, HIGH);

  //Sets the third motor to go backwards
  digitalWrite(DirectionMotor4, LOW);

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}

//Rotation CCW 
void RotationCCWMotion(int Speed){
  //Sets the first motor to go backwards
  digitalWrite(DirectionMotor1, LOW);

  //Sets the second motor to go forward
  digitalWrite(DirectionMotor2, HIGH);

  //Sets the third motor to go backwards
  digitalWrite(DirectionMotor3, LOW);

  //Sets the third motor to go forward  
  digitalWrite(DirectionMotor4, HIGH);

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,Speed);
  analogWrite(PWMMotor2,Speed);
  analogWrite(PWMMotor3,Speed);
  analogWrite(PWMMotor4,Speed);
}

//Wheels Stop
void StopMotion(){
  //Sets the first motor to go forward
  digitalWrite(DirectionMotor1, LOW);

  //Sets the second motor to go forward
  digitalWrite(DirectionMotor2, LOW);

  //Sets the third motor to go forward
  digitalWrite(DirectionMotor3, LOW);

  //Sets the third motor to go forward  
  digitalWrite(DirectionMotor4, LOW);

  //Sets speeds for all of the motors
  analogWrite(PWMMotor1,0);
  analogWrite(PWMMotor2,0);
  analogWrite(PWMMotor3,0);
  analogWrite(PWMMotor4,0);
}
