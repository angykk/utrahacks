#include <Arduino.h>
#include <colourSensor/colourSensor.h>
#include <superSonic.h>
#include <NewPing.h>

void goForward();
void turnLeft();
void turnRight();
void turn180();

// PIN OUT (can change later if needed)

// digital pins
const int leftMotor = 0; // digital pin
const int rightMotor = 1;

// analog pins
const int colorSensor = A0; // analog pin

// other
const int speed = 127; // range is 0-255 (255 is max speed, 0 is off)

void setup()
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(led, OUTPUT);
	pinMode(led2, OUTPUT);
	// Set S0 - S3 as outputs
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);

	pinMode(leftMotor, OUTPUT);
	pinMode(rightMotor, OUTPUT);

	// Set Pulse Width scaling to 20%
	digitalWrite(S0, HIGH);
	digitalWrite(S1, LOW);

	// Set Sensor output as input
	pinMode(sensorOut, INPUT);

	// Setup Serial Monitor
	Serial.begin(9600);
}

void loop()
{
	Serial.println(getDistance());
	Serial.println(getColour());
	delay(500);
}
