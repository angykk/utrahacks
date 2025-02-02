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

        for (servPos = 0; servPos <= 180; servPos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
            myservo.write(servPos);              // tell servo to go to position in variable 'servPos'
            delay(15);                       // waits 15ms for the servo to reach the position
        }


    }

}