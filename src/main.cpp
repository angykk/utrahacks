#include <Arduino.h>
#include <main.h>
#include <colourSensor/colourSensor.h>

// -------- START OF MOVE FUNCTIONS -------- 
void setup() {
    // put your setup code here, to run once:

    //motor outputs
    pinMode(N3, OUTPUT);
    pinMode(N4, OUTPUT);
    pinMode(N2, OUTPUT);
    pinMode(N1, OUTPUT);

    pinMode(colorSensor, INPUT);
    Serial.begin(9600);    

}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getColour());
  goForward();
  
}

// put function definitions here:
void goForward(){
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);
  analogWrite(ENA, DEFAULT_SPEED);
  
  digitalWrite(N2, HIGH);
  digitalWrite(N1, LOW);
  analogWrite(ENB, DEFAULT_SPEED);
}

void turnLeft(){
  digitalWrite(N3, HIGH);
  digitalWrite(N4, HIGH);
  
  digitalWrite(N2, HIGH);
  digitalWrite(N1, LOW);
  analogWrite(ENB, DEFAULT_SPEED);
}

void turnRight(){
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);
  analogWrite(ENA, DEFAULT_SPEED);

  digitalWrite(N2, HIGH);
  digitalWrite(N1, HIGH);
}


void turnLeft_FAST(){
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);
  analogWrite(ENA, 255);

  digitalWrite(N2, LOW);
  digitalWrite(N1, HIGH);
  analogWrite(ENB, 255);
 
}
void turnRight_FAST(){
  digitalWrite(N3, LOW);
  digitalWrite(N4, HIGH);
  analogWrite(ENA, 255);

  digitalWrite(N2, HIGH);
  digitalWrite(N1, LOW);
  analogWrite(ENB, 255);

}

void stop(){
  digitalWrite(N3, LOW);
  digitalWrite(N4, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N1, LOW);
}

void turn180() {
  // quick turn 180 degrees
  turnLeft_FAST();
  delay(1000); //change delay value accordingly (how long it will keep on turning)
  
  digitalWrite(N3, LOW);
  digitalWrite(N4, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N1, LOW);
}


// -------- END OF MOVE FUNCTIONS --------