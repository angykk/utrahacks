#include <Arduino.h>
#include <NewPing.h> //for ultrasonic sensor 

// ------- PIN OUT (can change later if needed) ---------

//digital pins
extern const int l_p = 0; //positive pin for left motor
extern const int l_n = 1; //negative pin for right motor
extern const int en_l = A2; //enable pin for left motor (analog control on motor driver)

extern const int r_p = 3; //positive pin for left motor
extern const int r_n = 24; //negative pin for right motor 
extern const int en_r = A3; //enable pin for right motor (analog control on motor driver)

//analog pins
extern const int colorSensor = A0; //analog pin

//other
extern const int DEFAULT_SPEED = 127; //range is 0-255 (255 is max DEFAULT_SPEED, 0 is off)

// ------- PIN OUT END ---------


// -------- START OF MOVE FUNCTIONS -------- 
void loop();
void setup();
void goForward();
void turnLeft();
void turnLeft_FAST();
void turnRight();
void turnRight_FAST();
void turn180();
void stop();
// -------- END OF MOVE FUNCTIONS --------