#include <Arduino.h>

void goForward();
void turnLeft();
void turnRight();
void turn180();

//PIN OUT (can change later if needed)

//digital pins
const int leftMotor = 0; //digital pin
const int rightMotor = 1; 

//analog pins
const int colorSensor = A0; //analog pin


//other
const int speed = 127; //range is 0-255 (255 is max speed, 0 is off)


//Move functions
void setup() {
    // put your setup code here, to run once:
    pinMode(leftMotor, OUTPUT);
    pinMode(rightMotor, OUTPUT);
    pinMode(colorSensor, INPUT);
    Serial.begin(9600);    
    
}


void loop() {
  // put your main code here, to run repeatedly:
  
}

// put function definitions here:
void goForward(){
  
  digitalWrite(leftMotor, speed);
  digitalWrite(rightMotor, speed);

}
void turnLeft(){
   digitalWrite(leftMotor, 0);
   digitalWrite(rightMotor, speed);
}
void turnRight(){
  digitalWrite(leftMotor, speed);
  digitalWrite(rightMotor, 0);
}

void turnLeft_FAST(){
   digitalWrite(leftMotor, -speed);
   digitalWrite(rightMotor, speed);
}
void turnRight_fast(){
  digitalWrite(leftMotor, speed);
  digitalWrite(rightMotor, -speed);
}

void stop(){
  digitalWrite(leftMotor, 0);
  digitalWrite(rightMotor, 0);
}
