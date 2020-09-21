#include <Arduino.h>
#include <Stepper.h>
#include <math.h>


//Unsure of this value.
const unsigned int STEPS_PER_REV = 200;

const unsigned int WHEEL_DIAMETER = 95; //mm
const double WHEEL_CIRCUMFERENCE = 298.45; //mm
const unsigned int CHASSIS_WIDTH = 320; //mm
const double CHASSIS_CIRCUMFERENCE = CHASSIS_WIDTH * M_PI;



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

void turnCentre(bool clockwise, int angle) 
{
  //takes a boolean value for the direction, 1-clockwise / 0-counter-clockwise
  //takes an angle to be travelled in mm, first converting to motor steps.

  //Rotates the vehicle the angle desired, rotating about a point halfway between the wheels.
  int steps = getSteps(distance);
  switch (clockwise)
  {
    case 1:
      while(steps > 0){
        motorLeft.step(1);
        motorRight.step(-1);
        steps--;
      }
      break;
    
    case 0:
      while(steps > 0){
        motorLeft.step(-1);
        motorRight.step(1);
        steps--;
      }
      break;
  }
  
}

void turnWheel(bool clockwise, bool wheel, int angle)
{
  //takes a boolean value for the direction, 1-clockwise / 0-counter-clockwise
  //takes a boolean value for the wheel to pivot on, 1-left / 0-right
  //takes an angle to be travelled in mm, first converting to motor steps.

  //Rotates the vehicle the angle desired, rotating about a point halfway between the wheels.
  int steps = getSteps(distance);
  switch (clockwise)
  {
    case 1:

      switch(wheel)
      {
        case 1:
          while(steps > 0){
            motorLeft.step(1);
            motorRight.step(-10);
            steps--;
          }
          break;

        case 0:
          while(steps > 0){
            motorLeft.step(10);
            motorRight.step(-1);
            steps--;
          }
          break;

      }

    case 0:
      switch(wheel)
      {
        case 1:
          while(steps > 0){
            motorLeft.step(-1);
            motorRight.step(10);
            steps--;
          }
          break;

        case 0:
          while(steps > 0){
            motorLeft.step(-10);
            motorRight.step(1);
            steps--;
          }
          break;
      }
      break;
  }
}

int getStepsAngle(int angle)
{
  //takes and angle in degrees to be rotated and returns the stepps required to rotate it
  //rotates the vehicle around the centre of the rear axle. 
  
  //gets fraction of a full rotation needing to be turned, multiplied by the circumference of a full rotation.
  double distance = CHASSIS_CIRCUMFERENCE *  ( angle / 360 );

  return getStepsDistance(distance);

}

int getStepsDistance(int distance)
{
  //takes a distance in mm and returns the number of motor steps required.
  double revolutions = distance / WHEEL_CIRCUMFERENCE;

  return (int)(STEPS_PER_REV * revolutions);
}
