#include "Board.h"
#include "Arduino.h"
#include "Pins.hpp"
//#include "Highlight.h"
#include "Positions.h"
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Arduino.h"
#include "State.h"


CRGB leds[NUM_LEDS];

Positions poses = Positions(64);
Board board = Board();
State white_state = State(board, poses, true);
State black_state = State(board, poses, false);

State* current_state = &white_state;
bool curr_state = true;
bool next_state = true;


void setup() {
    Serial.begin(9600);
    FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
    FastLED.setBrightness(100);
    FastLED.clear();
    FastLED.show();

    // config pins
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);

    for(int i=I0; i<I0+7; ++i){
        pinMode(i, INPUT);
    }

    current_state->enter();
}

void loop(){
    curr_state = next_state;
    auto next_state = current_state->process();
    if(curr_state != next_state){
        if(next_state == false){
            current_state = &black_state;
            current_state->enter();
        }
        else{
            current_state = &white_state;
            current_state->enter();
        }
    }

}



//void loop() {
//    highlight.turn_on(4, 4, board_chess, bor);
//    highlight.turn_all_red(bor);
//    // highlight.turn_off(bor);
//
//    for (int i = 0; i < NUM_LEDS; i++) { // Turn off lights
//            leds[i] = CRGB(0, 0, 0);
//        }
//        FastLED.show();
//        delay(50);
//
//        for (int row = 0; row < 8; row++) {
//            for (int col = 0; col < 8; col++) {
//                if (bor[row][col] == 1) {
//                    leds[row + col] = CRGB(0, 0, 255);
//                }
//                Serial.print(bor[row][col]);
//                Serial.print(" ");
//            }
//            Serial.println();
//        }
//
//        FastLED.show();
//        delay(50);
//}
