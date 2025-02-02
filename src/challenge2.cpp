
#include "main.h"
#include "colourSensor/colourSensor.h"
#include "superSonic.h"
#include <Servo.h>

unsigned long distanceFrom = 50.0; 
String colourOf;
bool isMoving = false;
const long length = 14;

void challenge2()
{
    colourOf = getColour();
    distanceFrom = getDistance();
    goForward();
    isMoving = true;

    if (distanceFrom < length)
    {
        stop();
        if (colourOf == "blue")
        {
            turnLeft_FAST();
        }
        else if (colourOf == "green")
        {
            turnRight_FAST();
        }
        else if (colourOf == "black")
        {
            stop();
        }
        else if (colourOf == "red")
        {
            turn180();
        }
    }
}