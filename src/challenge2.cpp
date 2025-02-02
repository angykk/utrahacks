#include <main.h>
#include <colourSensor/colourSensor.h>
#include <superSonic.h>
#include <Servo.h>

unsigned long distance = 50;
String colour;
bool isMoving = false;
const long length = 14;

void challenge2()
{
    colour = getColour();
    distance = getDistance();
    goForward();
    isMoving = true;

    if (distance < length)
    {
        stop();
        if (colour == "blue")
        {
            turnLeft_FAST();
        }
        else if (colour == "green")
        {
            turnRight_fast();
        }
        else if (colour == "black")
        {
            stop();
        }
        else if (colour == "red")
        {
            turn180();
        }
    }
}