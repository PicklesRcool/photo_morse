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
    case 'A':
    case 'a': {
      return ".-";
    }
    case 'B':
    case 'b': {
      return "-...";
    }
    case 'C':
    case 'c': {
      return "-.-.";
    }
    case 'D':
    case 'd': {
      return "-..";
    }
    case 'E':
    case 'e': {
      return ".";
    }
    case 'F':
    case 'f': {
      return "..-.";
    }
    case 'G':
    case 'g': {
      return "--.";
    }
    case 'H':
    case 'h': {
      return "....";
    }
    case 'I':
    case 'i': {
      return "..";
    }
    case 'J':
    case 'j': {
      return ".---";
    }
    case 'K':
    case 'k': {
      return "-.-";
    }
    case 'L':
    case 'l': {
      return ".-..";
    }
    case 'M':
    case 'm': {
      return "--";
    }
    case 'N':
    case 'n': {
      return "-.";
    }
    case 'O':
    case 'o': {
      return "---";
    }
    case 'P':
    case 'p': {
      return ".--.";
    }
    case 'Q':
    case 'q': {
      return "--.-";
    }
    case 'R':
    case 'r': {
      return ".-.";
    }
    case 'S':
    case 's': {
      return "...";
    }
    case 'T':
    case 't': {
      return "-";
    }
    case 'U':
    case 'u': {
      return "..-";
    }
    case 'V':
    case 'v': {
      return "...-";
    }
    case 'W':
    case 'w': {
      return ".--";
    }
    case 'X':
    case 'x': {
      return "-..-";
    }
    case 'Y':
    case 'y': {
      return "-.--";
    }
    case 'Z':
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
