#include "Highlight.h"

CRGB leds[NUM_LEDS];


void Highlight::turn_on(int x, int y, Board &board, int (*bor)[8]) {
    Figure* lnk = board.cell_value(x, y);
    Positions pm = Positions(64);
    lnk->possible_moves(pm, board);

    for (int row=0; row < 8; row++){
        for (int col=0; col < 8; col++){
            bor[row][col] = 0;
        }
    }

    for (int i = 0; i < pm.get_size(); i++){
        bor[pm.get_pos(i).x][pm.get_pos(i).y] = 1;
    }

}

void Highlight::turn_off(int (*bor)[8]) {
    for (int row=0; row < 8; row++){
        for (int col=0; col < 8; col++){
            bor[row][col] = 0;
        }
    }
}

void Highlight::turn_all_red(int (*bor)[8]) {
    for (int row=0; row < 8; row++){
        for (int col=0; col < 8; col++){
            bor[row][col] = 1;
        }
    }
}
