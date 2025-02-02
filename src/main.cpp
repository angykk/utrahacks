#include <Arduino.h>
#include <Servo.h>
#include "Challenge_1.h"
#include "main.h"
#include "colourSensor/colourSensor.h"
#include "superSonic.h"

// -------- START OF MOVE FUNCTIONS --------
const int defaultsped = 127; // range is 0-255 (255 is max DEFAULT_SPEED, 0 is off)
Servo myServo;

void setup()
{
  // put your setup code here, to run once:

  // motor outputs
  pinMode(N3, OUTPUT);
  pinMode(N4, OUTPUT);
  pinMode(N2, OUTPUT);
  pinMode(N1, OUTPUT);

  // colour outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // supersonic outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

  myServo.attach(5);

  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  challenge1();
}

// put function definitions here:
void goForward()
{
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);
  digitalWrite(ENB, defaultsped); // LEFT SIDE

  digitalWrite(N2, HIGH);
  digitalWrite(N1, LOW);
  digitalWrite(ENA, defaultsped); // RIGHT SIDE
}

void goBackward()
{
  digitalWrite(N3, LOW);
  digitalWrite(N4, HIGH);
  digitalWrite(ENB, defaultsped); // LEFT SIDE

  digitalWrite(N2, LOW);
  digitalWrite(N1, HIGH);
  digitalWrite(ENA, defaultsped); // RIGHT SIDE
}

void turnLeft()
{
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);
  digitalWrite(ENB, 0);

  digitalWrite(N2, HIGH);
  digitalWrite(N1, LOW);
  digitalWrite(ENA, defaultsped);
}

void turnRight()
{
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);
  digitalWrite(ENB, defaultsped);

  digitalWrite(N2, HIGH);
  digitalWrite(N1, LOW);
  digitalWrite(ENA, 0);
}

void turnLeft_FAST()
{
  digitalWrite(N3, LOW);
  digitalWrite(N4, HIGH);
  digitalWrite(ENB, defaultsped);

  digitalWrite(N2, HIGH);
  digitalWrite(N1, LOW);
  digitalWrite(ENA, defaultsped);
}
void turnRight_FAST()
{
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);
  digitalWrite(ENB, defaultsped);

  digitalWrite(N2, LOW);
  digitalWrite(N1, HIGH);
  digitalWrite(ENA, defaultsped);
}

void stop()
{
  digitalWrite(N3, LOW);
  digitalWrite(N4, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N1, LOW);
}

void turn180()
{
  // quick turn 180 degrees
  turnLeft_FAST();
  delay(1000); // change delay value accordingly (how long it will keep on turning)

  digitalWrite(N3, LOW);
  digitalWrite(N4, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N1, LOW);
}

// -------- END OF MOVE FUNCTIONS --------