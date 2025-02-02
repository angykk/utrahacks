
#include "main.h"
#include "colourSensor/colourSensor.h"
#include "superSonic.h"

unsigned long distanceFrom = 50.0; 
String colourOf;
bool isMoving = false;
const long length = 28/2;

void challenge2()
{
    colourOf = getColour();
    distanceFrom = getDistance();
    goForward();
    isMoving = true;

    if (distanceFrom < length)
    {
        stop();
        if (colourOf == "Blue")
        {
            turnLeft_FAST();
        }
        else if (colourOf == "Green")
        {
            turnRight_FAST();
        }
        else if (colourOf == "Black")
        {
            stop();
        }
        else if (colourOf == "Red")
        {
            turn180();
        }
    }
}