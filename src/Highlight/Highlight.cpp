#include "Highlight.h"

CRGB leds[NUM_LEDS];

CRGB cell_1 = CRGB(0, 200, 200);
CRGB cell_2 = CRGB(200, 0, 0);
CRGB pm_colour = CRGB(0, 0, 255);
CRGB mistake_color = CRGB(0, 255, 0);

void get_color(int i) {
    leds[i] = ((i / 8 + i % 8) % 2)? cell_1 : cell_2;
}

void highlight::reset() {
    for (int i = 0; i < NUM_LEDS; ++i) {
        get_color(i);
    }
//    FastLED.show();
}

void highlight::hint_on(Positions& p_moves) {
    for (int i = 0; i < p_moves.get_size(); ++i) {
        leds[p_moves.get_pos(i).x + p_moves.get_pos(i).y * 8] = pm_colour;
    }

//    FastLED.show();

}

void highlight::turn_all_red() {
    for (int i = 0; i < NUM_LEDS; ++i) {
        leds[i] = mistake_color;
    }

//    FastLED.show();

}

void highlight::show(){
    FastLED.show();
}
