/**
 *
 *	File: config.h
 *	Desc: File containing configurable values of important variables for the app
 *
 */

#ifndef CONFIG_H_
#define CONFIG_H_


const int kLedPin    = 3;
const int kSensorPin = 0;

const int kLightSensorThreshold = 18;	// percent
const int kWaitForPressInterval = 50;	// milliseconds
const int kDotDashBorder		= 250;	// milliseconds of press
const int kSerialDataRate		= 9600; // baud
const int kLoopDelay			= 40;	// milliseconds


#endif  // CONFIG_H_
