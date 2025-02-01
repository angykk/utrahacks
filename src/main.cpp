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
const int colorSensor = 0; //analog pin


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
  digitalWrite(leftMotor, speed);
  digitalWrite(rightMotor, speed);
  
}

// put function definitions here:
void goForward(){
  
  

}
void turnLeft(){

}
void turnRight(){

}
void turn180(){

}