#include <Arduino.h>
#include <main.h>

// -------- START OF MOVE FUNCTIONS -------- 
void setup() {
    // put your setup code here, to run once:

    //motor outputs
    pinMode(l_p, OUTPUT);
    pinMode(l_n, OUTPUT);
    pinMode(r_p, OUTPUT);
    pinMode(r_n, OUTPUT);

    pinMode(colorSensor, INPUT);
    Serial.begin(9600);    
    
}


void loop() {
  // put your main code here, to run repeatedly:
    goForward();
  
}

// put function definitions here:
void goForward(){
  digitalWrite(l_p, HIGH);
  digitalWrite(l_n, LOW);
  analogWrite(en_l, DEFAULT_SPEED);
  
  digitalWrite(r_p, HIGH);
  digitalWrite(r_n, LOW);
  analogWrite(en_r, DEFAULT_SPEED);
}

void turnLeft(){
  digitalWrite(l_p, HIGH);
  digitalWrite(l_n, HIGH);
  
  digitalWrite(r_p, HIGH);
  digitalWrite(r_n, LOW);
  analogWrite(en_r, DEFAULT_SPEED);
}

void turnRight(){
  digitalWrite(l_p, HIGH);
  digitalWrite(l_n, LOW);
  analogWrite(en_l, DEFAULT_SPEED);

  digitalWrite(r_p, HIGH);
  digitalWrite(r_n, HIGH);
}


void turnLeft_FAST(){
  digitalWrite(l_p, HIGH);
  digitalWrite(l_n, LOW);
  analogWrite(en_l, 255);

  digitalWrite(r_p, LOW);
  digitalWrite(r_n, HIGH);
  analogWrite(en_r, 255);
 
}
void turnRight_FAST(){
  digitalWrite(l_p, LOW);
  digitalWrite(l_n, HIGH);
  analogWrite(en_l, 255);

  digitalWrite(r_p, HIGH);
  digitalWrite(r_n, LOW);
  analogWrite(en_r, 255);

}

void stop(){
  digitalWrite(l_p, LOW);
  digitalWrite(l_n, LOW);
  digitalWrite(r_p, LOW);
  digitalWrite(r_n, LOW);
}

void turn180() {
  // quick turn 180 degrees
  turnLeft_FAST();
  delay(1000); //change delay value accordingly (how long it will keep on turning)
  
  digitalWrite(l_p, LOW);
  digitalWrite(l_n, LOW);
  digitalWrite(r_p, LOW);
  digitalWrite(r_n, LOW);
}


// -------- END OF MOVE FUNCTIONS --------