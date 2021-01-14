/**
 *
 *  File: morse_sensor_reader.h
 *  Desc: 
 *
 */

#ifndef MORSE_SENSOR_READER_H_
#define MORSE_SENSOR_READER_H_

#include "config.h"
#include "sensor_reader.h"


class MorseSensorReader : public SensorReader {
 public:
  MorseSensorReader(const uint8_t led_pin);
  char WaitAndGetSymbol(const uint32_t wait_time);
};


MorseSensorReader::MorseSensorReader(const uint8_t led_pin) : SensorReader(led_pin) {

}

char MorseSensorReader::WaitAndGetSymbol(const uint32_t wait_time) {
  uint32_t time_start = millis();

  while(1) {
    uint16_t sensor_read = analogRead(kSensorPin);
    ProcessValue(sensor_read);

    if (GetReadOver()) {
      return GetReadSymbol();
    }
    else if (wait_time && millis() - time_start > wait_time) {
      return 0;
    }
  }
}


#endif  // MORSE_SENSOR_READER_H_