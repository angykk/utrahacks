#pragma once

#include <Arduino.h>
#include <iostream>
#include <colourSensor/colourSensor.h>

int redPW;
int greenPW;
int bluePW;

int redMin = 900;		 // Red minimum value
int redMax = 16500;	 // Red maximum value
int greenMin = 900;	 // Green minimum value
int greenMax = 15000; // Green maximum value
int blueMin = 900;	 // Blue minimum value
int blueMax = 14500;	 // Blue maximum value

int red;
int green;
int blue;

const int black = 7000; // Constant (can stay here)

String getColour()
{
	// Read Red Pulse Width
	redPW = getRedPW(); // 2000

	red = map(redPW, redMin, redMax, 255, 0);
	// Delay to stabilize sensor
	delay(200);

	// Read Green Pulse Width
	greenPW = getGreenPW(); //
	green = map(greenPW, greenMin, greenMax, 255, 0);

	delay(200);

	// Read Blue Pulse Width
	bluePW = getBluePW(); //
	blue = map(bluePW, blueMin, blueMax, 255, 0);

	delay(200);

	// // Print output to Serial Monitor
	// Serial.print("Red PW = ");
	// Serial.print(redPW);
	// Serial.print(" - Green PW = ");
	// Serial.print(greenPW);
	// Serial.print(" - Blue PW = ");
	// Serial.println(bluePW);
	// // Print output to Serial Monitor
	// Serial.print("Red = ");
	// Serial.print(red);
	// Serial.print(" - Green = ");
	// Serial.print(green);
	// Serial.print(" - Blue = ");
	// Serial.println(blue);

	if (red < 100 && green < 100 && blue < 100) {
        return "Black";
    }
    // Check dominant colors with a threshold to avoid close values
    else if (red > green && red > blue) {
        return "Red";
    }
    else if (green > red && green > blue) {
        return "Green";
    }
    else if (blue > red && blue > green) {
        return "Blue";
    }
	else{
		return "Unknown";
	}

	// Print output to Serial Monitor
	Serial.print("Red PW = ");
	Serial.print(redPW);
	Serial.print(" - Green PW = ");
	Serial.print(greenPW);
	Serial.print(" - Blue PW = ");
	Serial.println(bluePW);
	// Print output to Serial Monitor
	Serial.print("Red = ");
	Serial.print(red);
	Serial.print(" - Green = ");
	Serial.print(green);
	Serial.print(" - Blue = ");
	Serial.println(blue);

	if (red > green && red > blue) {
		return "Red";
	}
	else if (green > red && green > blue) {
		return "Green";
	}
	else if (blue > red && blue > green) {
		return "Blue";
	}
	else if (red < 100 && green < 100 && blue < 100) {
		return "Black";
	}


}

// Function to read Red Pulse Widths
int getRedPW()
{
	// Set sensor to read Red only
	digitalWrite(S2, LOW);
	digitalWrite(S3, LOW);
	// Define integer to represent Pulse Width
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	// Return the value
	return PW;
}

// Function to read Green Pulse Widths
int getGreenPW()
{
	// Set sensor to read Green only
	digitalWrite(S2, HIGH);
	digitalWrite(S3, HIGH);
	// Define integer to represent Pulse Width
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	// Return the value
	return PW;
}

// Function to read Blue Pulse Widths
int getBluePW()
{
	// Set sensor to read Blue only
	digitalWrite(S2, LOW);
	digitalWrite(S3, HIGH);
	// Define integer to represent Pulse Width
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	// Return the value
	return PW;
}