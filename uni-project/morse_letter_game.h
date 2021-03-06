/**
 *
 *  File: morse_letter_game.h
 *  Desc: 
 *
 */

#ifndef MORSE_LETTER_GAME_H_
#define MORSE_LETTER_GAME_H_

#include "game.h"
#include "config.h"
#include "sensor_reader.h"
#include "led_utils.h"


class MorseLetterGame : public Game {
 public:
  MorseLetterGame(const SensorReader& reader);

  void Exec() override;

 private:
  void Start();
  void ReadLoop();
  void OutputResult();


  SensorReader m_sensor_reader;

  uint32_t m_input_start = 0;
  bool m_input_active = false;

  char m_ch_to_encode = 0;
  char m_player_dot_dash_input[10] = { 0 };

  bool m_input_over = false;
};


MorseLetterGame::MorseLetterGame(const SensorReader& reader) : m_sensor_reader(reader) {
  Serial.println("Welcome to the Morse code letter encoding game!");
  Serial.println("This game features you trying to correctly encode the letter you see on screen.");
  Serial.println("Good luck!");
  Serial.println(); 
}

void MorseLetterGame::Exec() {
  Start();
  
  while (!m_input_over) {
    ReadLoop();
  }

  OutputResult();
}

void MorseLetterGame::Start() {
  m_input_start = millis();
  m_input_active = false;

  m_ch_to_encode = random('a', 'z');

  for (uint8_t i = 0; i <= 10; ++i) {
    m_player_dot_dash_input[i] = 0;
  }

  Serial.print("Letter to encode: ");
  Serial.println(m_ch_to_encode);
}

void MorseLetterGame::ReadLoop() {
  uint16_t sensor_read = analogRead(kSensorPin);
  m_sensor_reader.ProcessValue(sensor_read);

  if (m_sensor_reader.GetReadOver()) {
    char read_symbol = m_sensor_reader.GetReadSymbol();

    Serial.print(read_symbol);
    strncat(m_player_dot_dash_input, &read_symbol, 1); 

    m_input_active = true;
    m_input_start = millis();
  }

  delay(kLoopDelay);
  m_input_over = (millis() - m_input_start > kNewWordThreshhold && m_input_active);
}

void MorseLetterGame::OutputResult() {
  Serial.println();

  if (strcmp(m_player_dot_dash_input, CharToMorse(m_ch_to_encode)) == 0) {
    Serial.println("Nice! :D\n");
    LED_DoubleBlink_Parallel(kRedLedPin_1, kRedLedPin_2, 200, 1000);
  }
  else {
    Serial.println("Try again! :(\n");
    LED_DoubleBlink_Split(kRedLedPin_1, kRedLedPin_2, 200, 1000);
  }
}


#endif  // MORSE_LETTER_GAME_H_
