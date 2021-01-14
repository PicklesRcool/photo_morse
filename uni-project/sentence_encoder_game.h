/**
 *
 *  File: sentence_encoder_game.h
 *  Desc: 
 *
 */

#ifndef SENTENSE_ENCODER_GAME_H_
#define SENTENSE_ENCODER_GAME_H_

#include "game.h"
#include "morse_led_utils.h"


class SentenceEncoderGame : public Game {
 public:
  SentenceEncoderGame(const uint8_t led_pin);
  void Exec() override;


 private:
  uint8_t m_led_pin;
  const char* m_sentence;
};


SentenceEncoderGame::SentenceEncoderGame(const uint8_t led_pin) : m_led_pin(led_pin) {
  Serial.println("Welcome to the sentence encoding game!");
  Serial.println("This game features your microcontroller encoding and transmitting a encoded sentence.");
  Serial.print("Enter your message: ");

  while(Serial.available() == 0) { }
  String message = Serial.readString();

  unsigned char* buf = new unsigned char[100];
  message.getBytes(buf, 100, 0);
  
  const char *message_c_str = (const char*)buf;

  Serial.print(message_c_str);

  Serial.println("Your message is gonna be transmitted shortly!");
  Serial.println();

  m_sentence = message_c_str;
}

void SentenceEncoderGame::Exec() {
  LED_MorseSentence(m_led_pin, m_sentence);
}


#endif  // SENTENSE_ENCODER_GAME_H_