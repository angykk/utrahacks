#include <main.h>

unsigned long distance = 0;
bool isMoving = false;
const long length = 28;
String colour = getColour();

void challenge2(){
    goForward();
    isMoving = true;

    if (distance <= length){
        stop();
        if (colour == "blue"){
            turnLeft_FAST();
        }
        else if (colour == "green"){
            turnRight_fast();
        }
        else if (colour == "black"){
            stop();
        }
        else if (colour == "red"){
            turn180();
        }
    }



}