#include <Arduino.h>
#include <NewPing.h> //for ultrasonic sensor 
void goForward();
void turnLeft();
void turnRight();
void turn180();

//PIN OUT (can change later if needed)

//digital pins
const int l_p = 0; //positive pin for left motor
const int l_n = 1; //negative pin for right motor
const int en_l = 2; //enable pin for left motor (analog control on motor driver)

const int r_p = 3; //positive pin for left motor
const int r_n = 24; //negative pin for right motor 
const int en_r = 5; //enable pin for right motor (analog control on motor driver)

//analog pins
const int colorSensor = A0; //analog pin

//other
const int DEFAULT_SPEED = 127; //range is 0-255 (255 is max DEFAULT_SPEED, 0 is off)


//Move functions 
void setup() {
    // put your setup code here, to run once:

    //motor outputs
    pinMode(l_p, OUTPUT);
    pinMode(l_n, OUTPUT);
    pinMode(r_p, OUTPUT);
    pinMode(r_n, OUTPUT);

    pinMode(colorSensor, INPUT);
    Serial.begin(9600);    
    
}


void loop() {
  // put your main code here, to run repeatedly:
    goForward();
  
}

// put function definitions here:
void goForward(){

  digitalWrite(l_p, HIGH);
  digitalWrite(l_n, LOW);
  analogWrite(en_l, DEFAULT_SPEED);
  
  digitalWrite(r_p, HIGH);
  digitalWrite(r_n, LOW);
  analogWrite(en_r, DEFAULT_SPEED);
}

void turnLeft(){
  digitalWrite(l_p, HIGH);
  digitalWrite(l_n, HIGH);
  
  digitalWrite(r_p, HIGH);
  digitalWrite(r_n, LOW);
  analogWrite(en_r, DEFAULT_SPEED);
}

void turnRight(){
  digitalWrite(l_p, HIGH);
  digitalWrite(l_n, LOW);
  analogWrite(en_l, DEFAULT_SPEED);

  digitalWrite(r_p, HIGH);
  digitalWrite(r_n, HIGH);
}


void turnLeft_FAST(){
  digitalWrite(l_p, HIGH);
  digitalWrite(l_n, LOW);
  analogWrite(en_l, 255);

  digitalWrite(r_p, LOW);
  digitalWrite(r_n, HIGH);
  analogWrite(en_r, 255);
 
}
void turnRight_fast(){
  digitalWrite(l_p, LOW);
  digitalWrite(l_n, HIGH);
  analogWrite(en_l, 255);

  digitalWrite(r_p, HIGH);
  digitalWrite(r_n, LOW);
  analogWrite(en_r, 255);

}

void turn180() {
  // quick turn 180 degrees
  turnLeft_FAST();
  delay(1000); //change delay value accordingly (how long it will keep on turning)
  
  //stop motors after delay
  digitalWrite(l_p, LOW);
  digitalWrite(l_n, LOW);

  digitalWrite(r_p, LOW);
  digitalWrite(r_n, LOW);
}

void stop(){
  digitalWrite(leftMotor, 0);
  digitalWrite(rightMotor, 0);
}
