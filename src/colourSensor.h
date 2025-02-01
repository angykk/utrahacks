#include <Arduino.h>

// Define color sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int getRedPW();
int getGreenPW();
int getBluePW();
<<<<<<< HEAD
String getColour();
=======
void getColour();
>>>>>>> 2d5723b08b9894d531e43ae3d02f13dc30745541

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
