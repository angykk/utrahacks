#include <Arduino.h>
#include "colourSensor/colourSensor.h"
#include "superSonic.h"
#include "main.cpp"
#include <unordered_map>
#include <vector>

// distance from wall that we stop
#define WALL_THRESHOLD 15 // cm value

std::vector<String> color_sequence = {"Red", "Green", "Blue", "Green", "Blue"};
std::unordered_map<String, std::vector<unsigned long>> colour_map;
int current_index = 0; // current colour we are looking for

//bool onTile = false;
unsigned long x1, x2, y1, y2;
bool inYAxis = true;
bool posDir = true;
unsigned long startTime;
unsigned long distance;
unsigned long x = 0;
unsigned long y = 0;

void blinkLED();
bool isNewTile(String color, unsigned long x1, unsigned long x2, unsigned long y1, unsigned long y2);
bool firstGreen = true;
bool firstBlue = true;
void updateDirection();       // NEED TO DO
void updateCurrentPosition(); // NEED TO DO

/*
boolean true or false to see if +/- direction
boolean x or y to track axis

need to track current location
need to store range of 1st green and blue

when getting to new colour check if its new
if yes: flash, if 1st green or blue, get measurements
if no: ignore and keep going
*/

void setup()
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    startTime = millis();
}

void loop()
{
    goForward();
    startTime = millis();

    // if a wall is detected stop and turn 
    if (getDistance() < WALL_THRESHOLD)
    {
        stop();
        delay(200);
        turnRight();

        // need to update our current position in current axis and start counting again in new axis
        updateCurrentPosition();
        updateDirection();
        return;
    }

    String detected_color = getColour();

    // when we detect the colour we're looking for:
    if (detected_color == color_sequence[current_index])
    {
        
        updateCurrentPosition();

        x1 = x;
        y1 = y;
        if (isNewTile(detected_color, x, y))
        {
            //unsigned long enterTime = millis() - startTime;

            blinkLED();
            

            // print for debugging
            Serial.print("Detected: ");
            Serial.println(detected_color);
            Serial.print("Tile: ");
            Serial.print(x);
            Serial.print(", ");
            Serial.println(y);
            current_index++;

            // if first green or blue get colour dimensions
            if (detected_color == "Green" && firstGreen || detected_color == "Blue" && firstBlue)
            {
                // CODE HERE TO GET X1,X2,Y1,Y2 DIMS, ADD TO HASHMAP
                
                // colour_map[detected_color].push_back({x, y});
            colour_map[detected_color].push_back(x);
            colour_map[detected_color].push_back(y);
                
            }
        }
        else
        {
            Serial.println("Duplicate Tile, Keep Searching...");
        }

    }
    updateCurrentPosition();
    x2 = x;
    y2 = y;
    colour_map[detected_color].push_back(x);
    colour_map[detected_color].push_back(y);
    turn180();
    goForward();
    turnRight();
    turn180();
    turn180();
    turnRight();

    if (current_index >= color_sequence.size())
    {
        stop();
        Serial.println("Sequence Complete!");
        while (true)
            blinkLED();
    }
}

void blinkLED()
{
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
}

bool isNewTile(String colour, int x, int y)
{
    for (auto &coord : colour_map[colour])
    {
        // if the x and y coordinates are between the ones we have saved for this colour, 
        //we have already visited this tile
        //coord.first;
        if (x >= colour_map[colour][0] && x <= colour_map[colour][1] && y >= colour_map[colour][2] && y <= colour_map[colour][3]) {
                return false;  // Point is inside the rectangle
            }

    }

    return true;
}

// Update the direction of movement after a turn (X or Y axis)
void updateDirection(bool isRight)
{
    if (isRight && inYAxis && posDir)
    {
        posDir = true;
        inYAxis = false;
    } 
    else if (isRight && !inYAxis && posDir){
        posDir = false;
        inYAxis = true;
    }
    else if (!isRight && inYAxis && posDir)
    {
        posDir = false;
        inYAxis = false;
    }
    else if (!isRight && !inYAxis && posDir)
    {
        posDir = true;
        inYAxis = true;
    }
    else if(isRight && inYAxis && !posDir){
        posDir = false;
        inYAxis = false;
    }
    else if(isRight && !inYAxis && !posDir){
        posDir = true;
        inYAxis = true;
    }
    else if(!isRight && inYAxis && !posDir){
        posDir = true;
        inYAxis = false;
    }
    else if(!isRight && !inYAxis && !posDir){
        posDir = false;
        inYAxis = true;
    }
    
}

// Update current position based on movement direction (time elapsed)
void updateCurrentPosition()
{
    distance = millis() - startTime;
    if (inYAxis)
    {
        // If moving in the Y-axis, update Y position
        if (posDir)
        {
            y = y + distance; // Positive direction (forward)
        }
        else
        {
            y = y - distance; // Negative direction (backward)
        }
    }
    else
    {
        // If moving in the X-axis, update X position
        if (posDir)
        {
            x = x + distance; // Positive direction (forward)
        }
        else
        {
            x = x - distance; // Negative direction (backward)
        }
    }
}
