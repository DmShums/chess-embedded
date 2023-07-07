#include "Arduino.h"

#include "Pins.hpp"

#include "Board.h"
#include "State.h"
#include "Highlight.h"

#include "Positions.h"

#include "FastLED.h"
#include "StatesManager.hpp"


Positions poses = Positions(64);
Board board = Board();
State white_state = State(board, poses, true);
State black_state = State(board, poses, false);

State *current_state = &white_state; //! White goes first
bool st = true;
bool next_state = true;

StatesManager states_manager{&white_state, &black_state, &board, &poses};


void setup() {
//    board.init_board();
    Serial.begin(9600);
    FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
    FastLED.setBrightness(100);
    FastLED.clear();
    highlight::reset();
    FastLED.show();

    //! Config pins to send the number of a Hall sensor in a row
    pinMode(S0, OUTPUT); //! 1st bit
    pinMode(S1, OUTPUT); //! 2nd bit
    pinMode(S2, OUTPUT); //! 3rd bit

    for (int i = I0; i < I0 + 7; ++i) { //! Go through all rows (3-10 pins in a row)
        pinMode(i, INPUT);
    }

    current_state->enter(); //! All figures are down
}

void loop() {
    states_manager.process();


//    pos fig_pos = current_state->question_sensors();
//    if (fig_pos.x == 10) {
//        return;
//    }
//
//    board.toggle_cell(fig_pos, current_state);

//    curr_state = next_state; //! Default true (white goes first)
//    current_state->enter();
//    next_state = current_state->process();
//    delay(50);
//    if (curr_state != next_state) {
//        if (!next_state) {
//            current_state = &black_state;
//            current_state->enter();
//        }
//        else {
//            current_state = &white_state;
//            current_state->enter();
//        }
//    }

}
