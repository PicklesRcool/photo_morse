/**
 *
 *  File: config.h
 *  Desc: File containing configurable values of important variables for the app
 *
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <stdint.h>
#include "morse_symbols.h"


const uint8_t kLedPin       = 3;
const uint8_t kRedLedPin_1  = 5;
const uint8_t kRedLedPin_2  = 7;
const uint8_t kSensorPin    = 0;

const uint8_t kLightSensorThreshold = 60;   // percent. Higher = more sensitive.
const uint16_t kWaitForPressInterval = 50;   // milliseconds
const uint16_t kDotDashBorder        = 225;  // milliseconds of press
const uint32_t kSerialDataRate       = 9600; // baud
const uint16_t kLoopDelay            = 40;   // milliseconds
const uint16_t kNewWordThreshhold    = 2000; // milliseconds

const uint16_t kEndOfSentenceTimer   = 4000; // milliseconds


#endif  // CONFIG_H_
