#include "Board.h"
#include "Arduino.h"
#include "Highlight.h"
#include "Positions.h"

// CRGB leds[NUM_LEDS];


int bor[8][8];
Board board_chess = Board();
Highlight highlight;

void setup() {
    Serial.begin(9600);
    FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
    FastLED.setBrightness(4);
    FastLED.clear();
    FastLED.show();

    // How to do this in a better way?
    // Deallocate memory
    // for (int i = 0; i < 8; i++) {
    //     delete[] bor[i];
    // }
    // delete[] bor;

}

void loop() {
    highlight.turn_on(4, 4, board_chess, bor);
    highlight.turn_all_red(bor);
    // highlight.turn_off(bor);

    for (int i = 0; i < NUM_LEDS; i++) { // Turn off lights
            leds[i] = CRGB(0, 0, 0);
        }
        FastLED.show();
        delay(50);

        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                if (bor[row][col] == 1) {
                    leds[row + col] = CRGB(0, 0, 255);
                }
                Serial.print(bor[row][col]);
                Serial.print(" ");
            }
            Serial.println();
        }

        FastLED.show();
        delay(50);
}
