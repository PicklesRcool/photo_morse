/**
 *
 *  File: config.h
 *  Desc: File containing configurable values of important variables for the app
 *
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "morse_symbols.h"


const int kLedPin    = 3;
const int kSensorPin = 0;

const int kLightSensorThreshold = 10;   // percent. Higher = more sensitive.
const int kWaitForPressInterval = 50;   // milliseconds
const int kDotDashBorder        = 225;  // milliseconds of press
const int kSerialDataRate       = 9600; // baud
const int kLoopDelay            = 40;   // milliseconds
const int kNewWordThreshhold    = 2000; // milliseconds


#endif  // CONFIG_H_
