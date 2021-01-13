/**
 *
 *  File: led_utils.h
 *  Desc: 
 *
 */

#ifndef LED_UTILS_H_
#define LED_UTILS_H_


/**
 *  Declarations
 */
void LED_TurnOn(const int pin_num);
void LED_TurnOff(const int pin_num);

void LED_Flash(const int pin_num, const unsigned long duration);
void LED_Blink(const int pin_num, const unsigned long flash_dur, const unsigned long blink_dur);
void LED_DoubleBlink_Split(const int pin1_num, const int pin2_num, const unsigned long flash_dur, const unsigned long blink_dur);
void LED_DoubleBlink_Parallel(const int pin1_num, const int pin2_num, const unsigned long flash_dur, const unsigned long blink_dur);


/**
 *  Implementations
 */
void LED_TurnOn(const int pin_num) {
  digitalWrite(pin_num, HIGH);
}

void LED_TurnOff(const int pin_num) {
  digitalWrite(pin_num, LOW);
}

void LED_Flash(const int pin_num, const unsigned long duration) {
  digitalWrite(pin_num, HIGH);
  delay(duration);
  digitalWrite(pin_num, LOW);
}

void LED_Blink(const int pin_num, const unsigned long flash_dur, const unsigned long blink_dur) {
  for (unsigned long time = 0; time < blink_dur; time += flash_dur * 2) {
    LED_Flash(pin_num, flash_dur);
    delay(flash_dur);
  }

  LED_TurnOff(pin_num);
}

void LED_DoubleBlink_Split(const int pin1_num, const int pin2_num, const unsigned long flash_dur, const unsigned long blink_dur) {
  for (unsigned long time = 0; time < blink_dur; time += flash_dur * 2) {
    LED_TurnOn(pin1_num);
    LED_TurnOff(pin2_num);
    delay(flash_dur);

    LED_TurnOff(pin1_num);
    LED_TurnOn(pin2_num);
    delay(flash_dur);
  }

  LED_TurnOff(pin1_num);
  LED_TurnOff(pin2_num);
}

void LED_DoubleBlink_Parallel(const int pin1_num, const int pin2_num, const unsigned long flash_dur, const unsigned long blink_dur) {
    for (unsigned long time = 0; time < blink_dur; time += flash_dur * 2) {
    LED_TurnOn(pin1_num);
    LED_TurnOn(pin2_num);
    delay(flash_dur);

    LED_TurnOff(pin1_num);
    LED_TurnOff(pin2_num);
    delay(flash_dur);
  }

  LED_TurnOff(pin1_num);
  LED_TurnOff(pin2_num);
}



#endif  // LED_UTILS_H_
