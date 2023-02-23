#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 1);

bool moving = false;

//professor hawkss

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  while (!Serial);
  Serial.println("Stepper test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(2000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  myMotor->setSpeed(10);  // 10 rpm
}

void loop() {
  if(moving)
  {
    Serial.println("Single coil steps");
    myMotor->step(200, BACKWARD, SINGLE);
  }
  if(Serial.available())
  {
    char input = Serial.read();
    //Serial.print("You typed: " );
    Serial.println(input);
    if(input == 's')
    {
      Serial.println("Should be moving/stopped now");
      moving = !moving;
    }
    
    else if(input == '1')
    {
      Serial.println("Speed set to 5rpm");
      myMotor->setSpeed(5);  
    }
    else if(input == '2')
    {
      Serial.println("Speed set to 20rpm");
      myMotor->setSpeed(20);  
    }
    else if(input == '3')
    {
      Serial.println("Speed set to 80rpm");
      myMotor->setSpeed(80);  
    }
    else if(input == '4')
    {
      Serial.println("Speed set to 140rpm");
      myMotor->setSpeed(140);  
    }
    else if(input == '5')
    {
      Serial.println("Speed set to 200rpm");
      myMotor->setSpeed(200);  
    }

    
  }
}
