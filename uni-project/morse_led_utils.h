/**
 *
 *  File: morse_led_utils.h
 *  Desc: File containing configurable values of important variables for the app
 *
 */

#ifndef MORSE_LED_UTILS_H_
#define MORSE_LED_UTILS_H_

#include <stdio.h>
#include <string.h>

#include "config.h"
#include "led_utils.h"
#include "morse_symbols.h"


/**
 *  Declarations
 */
void LED_MorseDot(const uint8_t pin_num);
void LED_MorseDash(const uint8_t pin_num);
void LED_MorseSymbol(const uint8_t pin_num, const char ch);
void LED_MorseLetter(const uint8_t pin_num, const char ch);
void LED_MorseSentence(const uint8_t pin_num, const char* word_str);


/**
 *  Implementations
 */
void LED_MorseDot(const uint8_t pin_num) {
  LED_Flash(pin_num, kMorseDotDuration);
  delay(kMorseSymbolInterval);
}

void LED_MorseDash(const uint8_t pin_num) {
  LED_Flash(pin_num, kMorseDashDuration);
  delay(kMorseSymbolInterval);
}

void LED_MorseSymbol(const uint8_t pin_num, const char morse_ch) {
  if  (morse_ch == '.')
    LED_MorseDot(pin_num);
  else if (morse_ch == '-')
    LED_MorseDash(pin_num);
}

void LED_MorseLetter(const uint8_t pin_num, const char ch) {
  const char* dot_dash_str = CharToMorse(ch);

  for (int i = 0; i < strlen(dot_dash_str); ++i) {
    LED_MorseSymbol(pin_num, dot_dash_str[i]);
  }

  delay(kMorseLetterInterval);
}

void LED_MorseWord(const uint8_t pin_num, const char* word_str) {
  for (int i = 0; i < strlen(word_str); ++i) {
    LED_MorseLetter(pin_num, word_str[i]);
  }

  delay(kMorseWordInterval);
}

void LED_MorseSentence(const uint8_t pin_num, const char* sentence_str) {
  for (int i = 0; i < strlen(sentence_str); ++i) {
    if (sentence_str[i] == ' ') {
      delay(kMorseWordInterval);
    }
    else {
      LED_MorseLetter(pin_num, sentence_str[i]);
    }
  }
}


#endif  // #ifndef MORSE_LED_UTILS_H_