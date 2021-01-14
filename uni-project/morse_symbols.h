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
char MorseToChar(const char* str);

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
      return "-.";
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

char MorseToChar(const char* str) {
  if (strcmp(str, ".-") == 0) {
    return 'a';
  }
  if (strcmp(str, "-...") == 0) {
    return 'b';
  }
  if (strcmp(str, "-.-.") == 0) {
    return 'c';
  }
  if (strcmp(str, "-..") == 0) {
    return 'd';
  }
  if (strcmp(str, ".") == 0) {
    return 'e';
  }
  if (strcmp(str, "..-.") == 0) {
    return 'f';
  }
  if (strcmp(str, "--.") == 0) {
    return 'g';
  }
  if (strcmp(str, "....") == 0) {
    return 'h';
  }
  if (strcmp(str, "..") == 0) {
    return 'i';
  }
  if (strcmp(str, ".---") == 0) {
    return 'j';
  }
  if (strcmp(str, "-.-") == 0) {
    return 'k';
  }
  if (strcmp(str, ".-..") == 0) {
    return 'l';
  }
  if (strcmp(str, "--") == 0) {
    return 'm';
  }
  if (strcmp(str, "-.") == 0) {
    return 'n';
  }
  if (strcmp(str, "---") == 0) {
    return 'o';
  }
  if (strcmp(str, ".--.") == 0) {
    return 'p';
  }
  if (strcmp(str, "--.-") == 0) {
    return 'q';
  }
  if (strcmp(str, ".-.") == 0) {
    return 'r';
  }
  if (strcmp(str, "...") == 0) {
    return 's';
  }
  if (strcmp(str, "-") == 0) {
    return 't';
  }
  if (strcmp(str, "..-") == 0) {
    return 'u';
  }
  if (strcmp(str, "...-") == 0) {
    return 'v';
  }
  if (strcmp(str, ".--") == 0) {
    return 'w';
  }
  if (strcmp(str, "-..-") == 0) {
    return 'x';
  }
  if (strcmp(str, "-.--") == 0) {
    return 'y';
  }
  if (strcmp(str, "--..") == 0) {
    return 'z';
  }
  
  return 0;
}

#endif  // MORSE_SYMBOLS_H_
