#pragma once

#include <Arduino.h>

// Define color sensor pins
#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define sensorOut 4

int getRedPW();
int getGreenPW();
int getBluePW();
String getColour();

// Variables for Color Pulse Width Measurements
extern int redPW;
extern int greenPW;
extern int bluePW;

extern int redMin;
extern int redMax;
extern int greenMin;
extern int greenMax;
extern int blueMin;
extern int blueMax;

extern int red;
extern int green;
extern int blue;

extern const int black;
