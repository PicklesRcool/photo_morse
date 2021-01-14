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
void LED_TurnOn(const uint8_t pin_num);
void LED_TurnOff(const uint8_t pin_num);

void LED_Flash(const uint8_t pin_num, const uint32_t duration);
void LED_Blink(const uint8_t pin_num, const uint32_t flash_dur, const uint32_t blink_dur);
void LED_DoubleBlink_Split(const uint8_t pin1_num, const uint8_t pin2_num, const uint32_t flash_dur, const uint32_t blink_dur);
void LED_DoubleBlink_Parallel(const uint8_t pin1_num, const uint8_t pin2_num, const uint32_t flash_dur, const uint32_t blink_dur);


/**
 *  Implementations
 */
void LED_TurnOn(const uint8_t pin_num) {
  digitalWrite(pin_num, HIGH);
}

void LED_TurnOff(const uint8_t pin_num) {
  digitalWrite(pin_num, LOW);
}

void LED_Flash(const uint8_t pin_num, const uint32_t duration) {
  digitalWrite(pin_num, HIGH);
  delay(duration);
  digitalWrite(pin_num, LOW);
}

void LED_Blink(const uint8_t pin_num, const uint32_t flash_dur, const uint32_t blink_dur) {
  for (uint32_t time = 0; time < blink_dur; time += flash_dur * 2) {
    LED_Flash(pin_num, flash_dur);
    delay(flash_dur);
  }

  LED_TurnOff(pin_num);
}

void LED_DoubleBlink_Split(const uint8_t pin1_num, const uint8_t pin2_num, const uint32_t flash_dur, const uint32_t blink_dur) {
  for (uint32_t time = 0; time < blink_dur; time += flash_dur * 2) {
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

void LED_DoubleBlink_Parallel(const uint8_t pin1_num, const uint8_t pin2_num, const uint32_t flash_dur, const uint32_t blink_dur) {
    for (uint32_t time = 0; time < blink_dur; time += flash_dur * 2) {
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
