//
// Created by Shuma on 25.04.2023.
//

#ifndef TEST_INO_HIGHLIGHT_H
#define TEST_INO_HIGHLIGHT_H

#include "Positions.h"
#include "Arduino.h"
#include <FastLED.h>
#include "Figure.h"

#define LED_PIN 26
#define MAG_PIN 28
#define NUM_LEDS 64
#define SIZE 8

extern CRGB leds[NUM_LEDS];

class Highlight {
public:

void turn_on(int x, int y, Board& board, int (*bor)[8]);
void turn_off(int (*bor)[8]);
void turn_all_red(int (*bor)[8]);
};


#endif //TEST_INO_HIGHLIGHT_H
