#include <Arduino.h>
#include <Stepper.h>

//Unsure of this value.
const unsigned int STEPS_PER_REV = 200;

const unsigned int WHEEL_DIAMETER = 95; //mm

double position_x;
double position_y;

void setup() {

  Stepper motorLeft(9, 9, 10, 11);
  Stepper motorRight(4, 5, 6, 7);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void driveForward(int forwards, int distance) 
{
  
  
}

int getSteps(int distance)
{

}
