#include <Arduino.h>
#include <main.h>;
#include <colourSensor/colourSensor.h>
#include <Servo.h>

unsigned long lastTime = 0;
unsigned long currentTime = 0;
unsigned long turnLength;
String colour;
String cur_colour;
int num = 0;
Servo myServo;
int servPos = 0;

void challenge1(){

    turnLeft();
    colour = getColour();

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

    cur_colour = colour;

    while (colour == cur_colour){
        goForward();
    }
    stop();

    num++;

    if (num == 6) {
        lastTime = millis();
        currentTime = millis();

        cur_colour = colour;

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
            myServo.write(servPos);              // tell servo to go to position in variable 'servPos'
            delay(15);                       // waits 15ms for the servo to reach the position
        }


    }

}
