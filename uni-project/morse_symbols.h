/**
 *
 *  File: morse_symbols.h
 *  Desc: File containing the associative container with the dot/dash string 
 *        and the respective letter/digit
 *
 */

#ifndef MORSE_SYMBOLS_H_
#define MORSE_SYMBOLS_H_

#include <unordered_map>


const std::map<const char*, const char> kMorseMap = {
  {".-"     , 'a'},
  {"-..."   , 'b'},
  {"-.-."   , 'c'},
  {"-.."    , 'd'},
  {"."      , 'e'},
  {"..-."   , 'f'},
  {"--."    , 'g'},
  {"...."   , 'h'},
  {".."     , 'i'},
  {".---"   , 'j'},
  {"-.-"    , 'k'},
  {".-.."   , 'l'},
  {"--"     , 'm'},
  {"-."     , 'n'},
  {"---"    , 'o'},
  {".--."   , 'p'},
  {"--.-"   , 'q'},
  {".-."    , 'r'},
  {"..."    , 's'},
  {"-"      , 't'},
  {"..-"    , 'u'},
  {"...-"   , 'v'},
  {".--"    , 'w'},
  {"-..-"   , 'x'},
  {"-.--"   , 'y'},
  {"--.."   , 'z'},

  {".----"  , '1'},
  {"..---"  , '2'},
  {"...--"  , '3'},
  {"....-"  , '4'},
  {"....."  , '5'},
  {"-...."  , '6'},
  {"--..."  , '7'},
  {"---.."  , '8'},
  {"----."  , '9'},
  {"-----"  , '0'}
};


#endif  // MORSE_SYMBOLS_H_
