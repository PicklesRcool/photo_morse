/**
 *
 *  File: morse_decoder_game.h
 *  Desc: 
 *
 */

#ifndef MORSE_DECODER_GAME_H_
#define MORSE_DECODER_GAME_H_


#include "game.h"
#include "config.h"
#include "morse_sensor_reader.h"
#include "morse_symbols.h"


class MorseDecoderGame : public Game {
 public:
  MorseDecoderGame(const MorseSensorReader& reader);

  void Exec() override;

 private:
  void Start();
  void ReadSentenceLoop();
  void ReadWordLoop();
  void OutputSentence();


  MorseSensorReader m_morse_reader;

  uint32_t m_last_input_time = 0;
  char m_decoded_str[100] = { 0 };

  bool m_sentence_input_started = false;
};


MorseDecoderGame::MorseDecoderGame(const MorseSensorReader& reader) : m_morse_reader(reader) {
  Serial.println("Welcome to the Morse decoder game!");
  Serial.println("This game allows you to translate any morse code you input into text!");
  Serial.println("Have fun!");
  Serial.println(); 
}

void MorseDecoderGame::Exec() {
  Start();

  ReadSentenceLoop();
  OutputSentence();
}

void MorseDecoderGame::Start() {
  m_sentence_input_started = false;
  m_decoded_str[0] = 0;
}

void MorseDecoderGame::ReadSentenceLoop() {
  while (1) {
    ReadWordLoop();

    if (millis() - m_last_input_time > kEndOfSentenceTimer) {
      break;
    }

    strncat(m_decoded_str, " ", 1);
    Serial.print("|");
  }

  Serial.println();
}

void MorseDecoderGame::ReadWordLoop() {
  bool input_started = false;
  char received_symbol;

  char morse_word[20] = { 0 };

  while (1) {
    if (!m_sentence_input_started) {
      received_symbol = m_morse_reader.WaitAndGetSymbol(0);
      m_sentence_input_started = true;
    }
    else if (!input_started) {
      received_symbol = m_morse_reader.WaitAndGetSymbol(kEndOfSentenceTimer);
      input_started = true;
    }
    else {
      received_symbol = m_morse_reader.WaitAndGetSymbol(kNewWordThreshhold);
    }

    if (received_symbol) {
      Serial.print(received_symbol);

      strncat(morse_word, &received_symbol, 1); 
    
      m_last_input_time = millis();
    }

    if (millis() - m_last_input_time > kNewWordThreshhold) {
      char decoded_ch = MorseToChar(morse_word);
      strncat(m_decoded_str, &decoded_ch, 1);

      break;
    }
  }
}

void MorseDecoderGame::OutputSentence() {
  Serial.println("\nDecoded message:");
  Serial.println(m_decoded_str);
  Serial.println();
}


#endif  // MORSE_DECODER_GAME_H_