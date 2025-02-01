#include <Arduino.h>
#include <colourSensor.h>

void goForward();
void turnLeft();
void turnRight();
void turn180();

void setup()
{
	// Set S0 - S3 as outputs
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);

	// Set Pulse Width scaling to 20%
	digitalWrite(S0, HIGH);
	digitalWrite(S1, LOW);

	// Set Sensor output as input
	pinMode(sensorOut, INPUT);

	// Setup Serial Monitor
	Serial.begin(9600);
}

void loop(){
    Serial.println(getColour());
}


// put function definitions here:
void goForward(){

}
void turnLeft(){

}
void turnRight(){

}
void turn180(){

}