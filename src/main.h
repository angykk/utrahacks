#include <Arduino.h>
// Define pins
#define ENA 11
#define N1 9 //right motor (negative) (r_n)
#define N2 8 //right motor (positive)
#define N3 7 // left motor (positive)
#define N4 6 //left motor (negative)
#define ENB 10

// ------- PIN OUT (can change later if needed) ---------

/*
extern const int l_p = 0; //positive pin for left motor
extern const int l_n = 1; //negative pin for right motor
//extern const int ENA = A2; //enable pin for left motor (analog control on motor driver)

extern const int r_p = 3; //positive pin for left motor
extern const int r_n = 24; //negative pin for right motor 
//extern const int ENB = A3; //enable pin for right motor (analog control on motor driver)

*/

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

