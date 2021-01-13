/**
 *
 *  File: morse_symbols.h
 *  Desc: File containing the associative container with the dot/dash string 
 *        and the respective letter/digit
 *
 */

#ifndef MORSE_SYMBOLS_H_
#define MORSE_SYMBOLS_H_

const char* CharToMorse(const char c);

const char* CharToMorse(const char c) {
  switch(c) {
    case 'a': {
      return ".-";
    }
    case 'b': {
      return "-...";
    }
    case 'c': {
      return "-.-.";
    }
    case 'd': {
      return "-..";
    }
    case 'e': {
      return ".";
    }
    case 'f': {
      return "..-.";
    }
    case 'g': {
      return "--.";
    }
    case 'h': {
      return "....";
    }
    case 'i': {
      return "..";
    }
    case 'j': {
      return ".---";
    }
    case 'k': {
      return "-.-";
    }
    case 'l': {
      return ".-..";
    }
    case 'm': {
      return "--";
    }
    case 'n': {
      return ".-";
    }
    case 'o': {
      return "---";
    }
    case 'p': {
      return ".--.";
    }
    case 'q': {
      return "--.-";
    }
    case 'r': {
      return ".-.";
    }
    case 's': {
      return "...";
    }
    case 't': {
      return "-";
    }
    case 'u': {
      return "..-";
    }
    case 'v': {
      return "...-";
    }
    case 'w': {
      return ".--";
    }
    case 'x': {
      return "-..-";
    }
    case 'y': {
      return "-.--";
    }
    case 'z': {
      return "--..";
    }
  }
}


#endif  // MORSE_SYMBOLS_H_
