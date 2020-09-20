#include <Arduino.h>
#include <Stepper.h>


//Unsure of this value.
const unsigned int STEPS_PER_REV = 200;

const unsigned int WHEEL_DIAMETER = 95; //mm
const unsigned int WHEEL_CIRCUMFERENCE = 298.45;
double position_x;
double position_y;

void setup() {

  Stepper motorLeft(9, 9, 10, 11);
  Stepper motorRight(4, 5, 6, 7);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void drive(bool forwards, int distance) 
{
  //takes a boolean value for the direction, 1-forward / 0-backwards
  //takes a distance to be travelled in mm, first convirting to motor steps.
  int steps = getSteps(distance);
  switch (forwards)
  {
    case 1:
      while(steps > 0){
        motorLeft.step(1);
        motorRight.step(1);
        steps--;
      }
      break;
    
    case 0:
      while(steps > 0){
        motorLeft.step(-1);
        motorRight.step(-1);
        steps--;
      }
      break;
  }
  
}

void turn(bool clockwise, int angle) 
{
  //takes a boolean value for the direction, 1-clockwise / 0-counter-clockwise
  //takes an angle to be travelled in mm, first converting to motor steps.
  int steps = getSteps(distance);
  switch (forwards)
  {
    case 1:
      while(steps > 0){
        motorLeft.step(1);
        motorRight.step(1);
        steps--;
      }
      break;
    
    case 0:
      while(steps > 0){
        motorLeft.step(-1);
        motorRight.step(-1);
        steps--;
      }
      break;
  }
  
}

int getStepsAngle(int angle)
{
  //takes and angle in degrees to be rotated and returns the stepps required to rotate it
  //rotates the vehicle around the centre of the rear axle.
}

int getStepsDistance(int distance)
{
  //takes a distance in mm and returns the number of motor steps required.
  double revolutions = distance / WHEEL_CIRCUMFERENCE;

  return STEPS_PER_REV * revolutions;
}
