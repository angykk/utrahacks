#include <main.h>;

unsigned long lastTime = 0;
int num = 0;

void setup();

void loop(){
    unsigned long currentTime = millis();

    turnLeft();

    if (colour == "red" || colour == "green" || colour == "blue"){
        lastTime = millis();
    }

    if (colour != "red" && colour != "green" && colour != "blue"){
        stop();
        currentTime = millis();
    }

    unsigned long turnLength = (currentTime - lastTime) / 2;

    lastTime = millis();
    currentTime = millis();

    while(currentTime - lastTime < turnLength){
        currentTime = millis();
        turnRight();
    }
    stop();

    String cur_colour = colour;

    while (colour == cur_colour){
        goForward();
    }
    stop();

    num++;

    if (num == 6) {
        lastTime = millis();
        currentTime = millis();

        String cur_colour = colour;

        while (colour == cur_colour){
            goForward();
        }
        stop();

        currentTime = millis();

        unsigned long turnLength = (currentTime - lastTime) / 2;

        lastTime = millis();
        currentTime = millis();

        while(currentTime - lastTime < turnLength){
            currentTime = millis();
            turnRight();
        }
        stop();

        

    }

}