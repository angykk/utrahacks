#include <Arduino.h>

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

extern long duration, distance;

long getDistance();