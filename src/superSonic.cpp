#pragma once

#include <Arduino.h>
#include <iostream>
#include <superSonic.h>

long duration, distance;

long getDistance()

{
    digitalWrite(trigPin, LOW); // Added this line
    delayMicroseconds(2);       // Added this line
    digitalWrite(trigPin, HIGH);
    //  delayMicroseconds(1000); - Removed this line
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1;
 
    if (distance >= 200 || distance <= 0)
    {
        return -1;
    }
    else
    {
        return distance;
    }
}