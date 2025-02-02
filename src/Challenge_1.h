#pragma once

#include <Arduino.h>
#include <Servo.h>


extern unsigned long lastTime;
extern unsigned long currentTime;
extern unsigned long turnLength;
extern unsigned long turnBackTime;
extern String colour;
extern String cur_colour;
extern int num;
extern Servo myServo;

void challenge1();