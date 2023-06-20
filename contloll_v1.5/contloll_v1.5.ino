/*Arduino bobo
  Version 1.5
*/

//include the library code:

// use pin 3, 5, 6, 9, for output
//a b c d
//variables to store channel value:
double ch1 = 2;//throttle
double ch2 = 3;//steer

int a = 10; int b = 9;
int c = 6; int d = 5;

int motorSpeed1 = 0; //variable to store motor speed:
int motorSpeed2 = 0;

int RightMotor =230;
int LeftMotor =0;

void setup() {

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);


  pinMode(2, INPUT);
  pinMode(3, INPUT);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);


  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

}

void Forward() { //Move Forward:

  digitalWrite(a, LOW); digitalWrite(b, HIGH);
  digitalWrite(c, LOW); digitalWrite(d, HIGH);
  
  digitalWrite(13, HIGH); delay(400); digitalWrite(13, LOW);
  delay(100);
}

void Stop() { //Stop:
  digitalWrite(a, LOW); digitalWrite(b, LOW);
  digitalWrite(c, LOW); digitalWrite(d, LOW);

  digitalWrite(13, HIGH); delay(500); digitalWrite(13, LOW);
  digitalWrite(13, HIGH); delay(500); digitalWrite(13, LOW);
  digitalWrite(13, HIGH); delay(800); digitalWrite(13, LOW);

  delay(100);
}

void Backward () { //Move Backward:
  digitalWrite(a, HIGH); digitalWrite(b, LOW);
  digitalWrite(c, HIGH); digitalWrite(d, LOW);

  digitalWrite(13, HIGH); delay(500); digitalWrite(13, LOW);
  digitalWrite(13, HIGH); delay(500); digitalWrite(13, LOW);
  delay(100);
}

void MoveTopRight() { //Move Top Right:
  /*
    motor1.run(FORWARD);                      //Drive motor1 clockwise:
    motor1.setSpeed(motorSpeed1);              //Define motor1 speed"
    motor2.run(RELEASE);                      //Stop motor2:
    motor2.setSpeed(motorSpeed1);              //Define motor2 speed:
    motor3.run(FORWARD);                      //Drive motor3 clockwise:
    motor3.setSpeed(motorSpeed1);              //Define motor3 speed:
    motor4.run(RELEASE);                      //Stop motor4:
    motor4.setSpeed(motorSpeed1);              //Define motor4 speed:
  */
}

void MoveTopLeft() { //MOve Top Left:
  /*
    motor1.run(RELEASE);                      //Stop motor1:
    motor1.setSpeed(motorSpeed1);              //Define motor1 speed:
    motor2.run(FORWARD);                      //Drive motor2 clockwise:
    motor2.setSpeed(motorSpeed1);              //Define motor2 speed:
    motor3.run(RELEASE);                      //Stop motor3:
    motor3.setSpeed(motorSpeed1);              //Define motor3 speed:
    motor4.run(FORWARD);                      //Drive motor4 clockwise:
    motor4.setSpeed(motorSpeed1);              //Define motor4 speed:
  */
}

void MoveBackRight() { //Move Back Right:
  /*
    motor1.run(RELEASE);                      //Stop motor1:
    motor1.setSpeed(motorSpeed1);              //Define motor1 speed:
    motor2.run(BACKWARD);                     //Drive motor2 anti-clockwise:
    motor2.setSpeed(motorSpeed1);              //Define motor2 speed:
    motor3.run(RELEASE);                      //Stop motor3:
    motor3.setSpeed(motorSpeed1);              //Define motor3 speed:
    motor4.run(BACKWARD);                     //Drive motor4 anti-clockwise:
    motor4.setSpeed(motorSpeed1);              //Define motor4 speed:
  */
}
void MoveBackLeft() { //Move Back Left:
  /*
    motor1.run(BACKWARD);                     //Drive motor1 anti-clockwise:
    motor1.setSpeed(motorSpeed1);              //Define motor1 speed:
    motor2.run(RELEASE);                      //Stop motor2:
    motor2.setSpeed(motorSpeed1);              //Define motor2 speed:
    motor3.run(BACKWARD);                     //Drive motor3 anti-clockwise:
    motor3.setSpeed(motorSpeed1);              //Define motor3 speed:
    motor4.run(RELEASE);                      //Stop motor4:
    motor4.setSpeed(motorSpeed1);              //Define motor4 speed:
  */
}
void RightTurn() { //Turn Right:

    digitalWrite(a, HIGH); digitalWrite(b, LOW);
  digitalWrite(c, LOW); digitalWrite(d, HIGH);

  digitalWrite(13, HIGH); delay(500); digitalWrite(13, LOW);
  delay(100);
  
  /*
    motor1.run(FORWARD);                      //Drive motor1 clockwise:
    motor1.setSpeed(motorSpeed1);              //Define motor1 speed:
    motor2.run(FORWARD);                      //Drive motor2 clockwise:
    motor2.setSpeed(motorSpeed1);              //Define motor2 speed:
    motor3.run(BACKWARD);                     //Drive motor3 anti-clockwise:
    motor3.setSpeed(motorSpeed1);              //Define motor3 speed :
    motor4.run(BACKWARD);                     //Drive motor4 anti-clockwise:
    motor4.setSpeed(motorSpeed1);              //Define motor4 speed:
  */
}
void LeftTurn() { //Turn Left:

    digitalWrite(a, LOW); digitalWrite(b, HIGH);
  digitalWrite(c, HIGH); digitalWrite(d, LOW);

  digitalWrite(13, HIGH); delay(500); digitalWrite(13, LOW);
  delay(100);
  /*
    motor1.run(BACKWARD);                     //Drive motor1 anti-clockwise:
    motor1.setSpeed(motorSpeed1);              //Define motor1 speed:
    motor2.run(BACKWARD);                     //Drive motor2 anti-clockwise:
    motor2.setSpeed(motorSpeed1);              //Define motor2 speed:
    motor3.run(FORWARD);                      //Drive motor3 clockwise:
    motor3.setSpeed(motorSpeed1);              //Define motor3 speed:
    motor4.run(FORWARD);                      //Drive motor4 clockwise:
    motor4.setSpeed(motorSpeed1);              //Define motor4 speed:
  */
}

void loop()
{
  ch1 = pulseIn(2, HIGH);
  ch2 = pulseIn(3, HIGH);

  motorSpeed2 = map(ch1, 1000, 2000, -70, 70);

//for teting only
/*
  if (digitalRead(A5))
  {
    Forward();
  }
  if (digitalRead(A4))
  {
    Backward();
  }
  
  if (digitalRead(A3))
  {
    MoveTopRight();
  }
  if (digitalRead(A2))
  {
    MoveTopLeft();
  }
*/

  Stop();
  delay(500);
  
  Forward();
  delay(800);
  
  Stop();
  delay(800);
  
  LeftTurn();
  delay(700);
  
  Stop();
  delay(700);
  
  RightTurn();
  delay(700);
  
  Stop();
  delay(800);
  
  Backward();
  delay(800);
  
  Stop();

  

/*
  //RightMotor = motorSpeed1 - map(ch2, 1000, 2000, -70, 70);
  //LeftMotor = motorSpeed1 - map(ch2, 1000, 2000, +70, -70);

  if ((ch1 == 0)&&(ch2 == 0))
  {
    Stop();
  }
  else if ((ch1 > 1530) && (ch2 > 1530))
  {
    Forward();
  }
  else if ((ch1 > 1530) && (ch2 < 1460))
  {
    MoveTopRight();
  }
  else if ((ch1 < 1460) && (ch2 > 1530))
  {
    MoveTopLeft();
  }
  else if ((ch1 < 1460) && (ch2 < 1460))
  {
    Backward();
  }
  else
  {
    Stop();
  }
*/
}
