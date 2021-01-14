/**
 *
 *  File: sensor_reader.h
 *  Desc: 
 *
 */

#ifndef SENSOR_READER_H_
#define SENSOR_READER_H_

#include "config.h"
#include "led_utils.h"


class SensorReader {
 public:
  SensorReader(const uint8_t led_pin);

  void ProcessValue(const uint16_t sensor_value);

  bool GetReadOver() const;
  char GetReadSymbol() const;
  uint32_t GetDuration() const;

 private:
  void Read(const uint16_t sensor_value);
  void SetLED();
  void FinishRead();
  bool IsGetReadOver() const;


  uint8_t m_led_pin = -1;

  bool m_key_pressed  = false;
  bool m_clicking     = false;
  bool m_read_over    = false;

  uint32_t m_click_start   = 0;
  uint32_t m_last_pressed  = 0;

  uint32_t m_click_dur = 0;
  char m_last_read_symbol   = 0;
};


SensorReader::SensorReader(const uint8_t led_pin) : m_led_pin(led_pin) {

}

void SensorReader::ProcessValue(const uint16_t sensor_value) {
  Read(sensor_value);
  SetLED();

  if (GetReadOver()) {
    FinishRead();
  }
}

void SensorReader::Read(const uint16_t sensor_value) {
  uint8_t light_perc = round(sensor_value / 1023.0 * 100);

  m_key_pressed = light_perc <= kLightSensorThreshold;

  if (m_key_pressed) {
    m_last_pressed = millis();

    if (!m_clicking) {
      m_clicking = true;
      m_click_start = millis();
    }
  }

  m_read_over = ((millis() - m_last_pressed) > kWaitForPressInterval) && m_clicking;
}

void SensorReader::SetLED() {
  if (m_key_pressed) {
    LED_Flash(m_led_pin, 50);
  }
  else {
    LED_TurnOff(m_led_pin);
  }
}

bool SensorReader::GetReadOver() const {
  return m_read_over;
}

void SensorReader::FinishRead() {
  m_clicking = false;

  m_click_dur = millis() - m_click_start;
  if (m_click_dur < kDotDashBorder) {
    m_last_read_symbol = '.';
  }
  else {
    m_last_read_symbol = '-';
  }
}

char SensorReader::GetReadSymbol() const {
  return m_last_read_symbol;
};

uint32_t SensorReader::GetDuration() const {
  return m_click_dur;
}


#endif  // SENSOR_READER_H_
