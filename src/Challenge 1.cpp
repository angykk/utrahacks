<<<<<<< Updated upstream
// #include <Arduino.h>
// #include <main.h>;
// #include <colourSensor/colourSensor.h>

/*

#include <main.h>;
#include <colourSensor.h>
=======
#include <Arduino.h>
#include <main.h>;
#include <colourSensor/colourSensor.h>
>>>>>>> Stashed changes

unsigned long lastTime = 0;
int num = 0;

void challenge1()
{
    unsigned long currentTime = millis();
    String colour = getColour();

    turnLeft();

    if (colour == "red" || colour == "green" || colour == "blue")
    {
        lastTime = millis();
        turnLeft();
    }

    if (colour != "red" && colour != "green" && colour != "blue")
    {
        stop();
        currentTime = millis();
    }

    unsigned long turnLength = currentTime / 2;

    lastTime = millis();
    currentTime = millis();

    while (currentTime - lastTime < turnLength)
    {
        currentTime = millis();
        turnRight();
    }

    stop();

    num++;

<<<<<<< Updated upstream
    if (num == 6){
        return;
    }
}
*/
=======
    if (num == 6)
    {
        lastTime = millis();
        currentTime = millis();
        String cur_colour = colour;
        while (colour == cur_colour)
        {
            goForward();
        }
        stop();
        currentTime = millis();
        unsigned long turnLength = (currentTime - lastTime) / 2;
        lastTime = millis();
        currentTime = millis();
        while (currentTime - lastTime < turnLength)
        {
            currentTime = millis();
            turnRight();
        }
        stop();
    }
}
>>>>>>> Stashed changes
