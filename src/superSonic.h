#pragma once

#include <Arduino.h>

#define trigPin 13
#define echoPin 12


extern long duration, distance;

long getDistance();