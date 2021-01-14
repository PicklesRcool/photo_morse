#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "config.h"
#include "sensor_reader.h"
#include "morse_sensor_reader.h"
#include "morse_symbols.h"
#include "led_utils.h"
#include "morse_letter_game.h"
#include "morse_decoder_game.h"


SensorReader sensor_reader(kLedPin);
MorseSensorReader morse_reader(kLedPin);
Game* current_game = nullptr;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(kLedPin, OUTPUT);
  pinMode(kRedLedPin_1, OUTPUT);
  pinMode(kRedLedPin_2, OUTPUT);

  pinMode(kSensorPin, INPUT);
  analogReference(0);
  
  Serial.begin(kSerialDataRate);
  Serial.print("\n\nSerial output initialized. Data rate: ");
  Serial.println(kSerialDataRate);

  delay(1000);
  randomSeed(analogRead(0));

  LED_DoubleBlink_Parallel(kRedLedPin_1, kRedLedPin_2, 200, 1000);

  Serial.println("Hello user! This app can help you learn and improve your Morse code skills by playing games!");
  Serial.println("There are two games available at the moment");
  Serial.println("1. Morse code letter encoding game;");
  Serial.println("2. Morse code decoder game;");
  Serial.println("10. Exit.");
  Serial.print  ("Make your choise: ");

  uint8_t choise = -1;
  char ch = 0;
  while (ch != '-') {
    ch = morse_reader.WaitAndGetSymbol(0);
    ++choise;
  }

  Serial.println(choise);
  Serial.println();

  switch (choise) {
    case 1: {
      current_game = new MorseLetterGame(sensor_reader);
      break;
    }
    case 2: {
      current_game = new MorseDecoderGame(morse_reader);
      break;
    }
    case 10: {
      break;
    }
    default: {
      Serial.println("Invalid input. Reset to try again.");
    }
  }
}

void loop() {
#if 1  // For stopping program execution

  if (current_game)
    current_game->Exec();

#endif
}
