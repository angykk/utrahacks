// #include <Arduino.h>
// #include <main.h>;
// #include <colourSensor/colourSensor.h>

/*

#include <main.h>;
#include <colourSensor.h>

// unsigned long lastTime = 0;
// int num = 0;


// void challenge1(){
//     unsigned long currentTime = millis();
//     String colour = getColour();

//     turnLeft();

//     if (colour == "red" || colour == "green" || colour == "blue"){
//         lastTime = millis();
//     }

//     if (colour != "red" && colour != "green" && colour != "blue"){
//         stop();
//         currentTime = millis();
//     }

<<<<<<< HEAD
    unsigned long turnLength = (currentTime - lastTime) / 2;
=======
//     unsigned long turnLength = currentTime/2;
>>>>>>> master

//     lastTime = millis();
//     currentTime = millis();

<<<<<<< HEAD
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
=======
//     while(currentTime - lastTime < turnLength){
//         currentTime = millis();
//         turnRight();
//     }

//     stop();
>>>>>>> master

//     num++;

<<<<<<< HEAD
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

        

=======
    if (num == 6){
        return;
>>>>>>> master
    }
}
*/