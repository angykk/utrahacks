#include <Arduino.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

const int black = 800;
// Function to read Red Pulse Widths
int getRedPW()
{
    // Set sensor to read Red only
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    // Define integer to represent Pulse Width
    int PW;
    // Read the output Pulse Width
    PW = pulseIn(sensorOut, LOW);
    // Return the value
    return PW;
}

// Function to read Green Pulse Widths
int getGreenPW()
{
    // Set sensor to read Green only
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    // Define integer to represent Pulse Width
    int PW;
    // Read the output Pulse Width
    PW = pulseIn(sensorOut, LOW);
    // Return the value
    return PW;
}

// Function to read Blue Pulse Widths
int getBluePW()
{
    // Set sensor to read Blue only
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    // Define integer to represent Pulse Width
    int PW;
    // Read the output Pulse Width
    PW = pulseIn(sensorOut, LOW);
    // Return the value
    return PW;
}

void setup()
{
    // put your setup code here, to run once:

    // Set S0 - S3 as outputs
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);

    // Set Sensor output as input
    pinMode(sensorOut, INPUT);

    // Setup Serial Monitor
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    int red = getRedPW();
    int blue = getBluePW();
    int green = getGreenPW();

    int colour = min(min(red, blue),green);

    if(colour > black){
        //go straight
    }

    else if(colour == red){
        //uturn
    }

    else if (colour == blue){
        //turn left
    }

    else{//green
        //turn right
    }
    
}
