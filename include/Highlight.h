#ifndef TEST_INO_HIGHLIGHT_H
#define TEST_INO_HIGHLIGHT_H

#include "Positions.h"
#include "Arduino.h"
#include <FastLED.h>
#include "Figure.h"
#include "Positions.h"

#define LED_PIN 22
#define MAG_PIN 28
#define NUM_LEDS 64
#define SIZE 8

extern CRGB leds[NUM_LEDS];

namespace highlight {
 void hint_on(Positions& p_moves);
 void turn_all_red();
 void reset();
 void show();
};


#endif //TEST_INO_HIGHLIGHT_H
