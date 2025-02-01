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

    unsigned long turnLength = currentTime/2;

    lastTime = millis();
    currentTime = millis();

    while(currentTime - lastTime < turnLength){
        currentTime = millis();
        turnRight();
    }

    stop();

    num++;

    if (num == 6){
        break;
    }

}