#include "Highlight.h"

CRGB leds[NUM_LEDS];

//CRGB cell_1_color = CRGB(0, 10, 10); //! purple
CRGB cell_1_color = CRGB(30, 30, 30); //! white
//CRGB cell_2_color = CRGB(10, 0, 0); //! green
CRGB cell_2_color = CRGB(0, 0, 0); //! black

int pm_color_r = 15;
int pm_color_g = 15;
int pm_color_b = 250;
CRGB mistake_color = CRGB(0, 255, 0);

void set_color(int i) {
    leds[i] = ((i / 8 + i % 8) % 2)? cell_1_color : cell_2_color;
}

void highlight::reset() {
    for (int i = 0; i < NUM_LEDS; ++i) {
        set_color(i);
    }
//    FastLED.show();
}

void highlight::hint_on(Positions& p_moves, Board& board) {
    int coef;
    int led_idx;
    for (int i = 0; i < p_moves.get_size(); ++i) {
        led_idx = p_moves.get_pos(i).x + p_moves.get_pos(i).y * 8;
        if (board.cell_value(p_moves.get_pos(i).x, p_moves.get_pos(i).y) != nullptr) {
            leds[led_idx] = mistake_color;
        } else {
            coef = ((led_idx / 8 + led_idx % 8) % 2)? -5 : 5;
            leds[led_idx] = CRGB(pm_color_g + coef, pm_color_r + coef, pm_color_b + coef);
        }
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
