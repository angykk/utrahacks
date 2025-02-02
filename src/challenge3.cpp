#include <Arduino.h>
#include "motors.h"
#include "sensors.h"
#include <unordered_map>
#include <vector>

#define LED_PIN 13        // clarify
#define WALL_THRESHOLD 15 // cm

std::vector<String> color_sequence = {"red", "green", "blue", "green", "blue"};
std::unordered_map<String, std::vector<unsigned long>> color_map;
int current_index = 0;

bool onTile = false;
unsigned long x1, x2, y1, y2;
// xymarked bools?

void blinkLED();
bool isNewTile(String color, unsigned long x1, unsigned long x2, unsigned long y1, unsigned long y2);

void setup()
{
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    moveForward();

    if (readDistance() < WALL_THRESHOLD)
    {
        stopMotors();
        delay(200);
        turnLeft();
        return;
    }

    String detected_color = detectColor();
    if (detected_color == color_sequence[current_index])
    {
        stopMotors();

        // get the bounds of the colour tile
        int x = random(1, 10);
        int y = random(1, 10);

        if (isNewTile(detected_color, x, y))
        {
            blinkLED();
            color_map[detected_color].push_back({x, y});
            Serial.print("Detected: ");
            Serial.println(detected_color);
            Serial.print("Tile: ");
            Serial.print(x);
            Serial.print(", ");
            Serial.println(y);
            current_index++;
        }
        else
        {
            Serial.println("Duplicate Tile, Searching...");
        }
    }

    if (current_index >= color_sequence.size())
    {
        stopMotors();
        Serial.println("Sequence Complete!");
        while (true)
            blinkLED();
    }
}

void blinkLED()
{
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
}

bool isNewTile(String color, int x, int y)
{
    for (auto &coord : color_map[color])
    {
        if (coord[0] == x && coord[1] == y)
        {
            return false;
        }
    }
    return true;
}
