#pragma once

#include <Arduino.h>
#include <Servo.h>


extern unsigned long lastTime= 0;
extern unsigned long currentTime= 0;
extern unsigned long turnLength= 0;
extern String colour;
extern String cur_colour;
extern int num = 0;
extern Servo myServo;
extern int servPos;

void challenge1();