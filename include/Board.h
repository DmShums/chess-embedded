#ifndef TEST_INO_BOARD_H
#define TEST_INO_BOARD_H


#include "pos.h"
#include "Figure.h"
#include <stdlib.h>

class Figure;
class Board{
private:
    Figure* board[8][8];

public:
    // Print the chessboard to the console
    void print_board();
    bool is_white = true;
//    map<string, integer> section;

    Board();
    ~Board() {
        for(auto & i : board){
            for(auto & j : i){
                if (j != nullptr) {
                    free(j);
                };
            }
        }
    }

    void make_move(pos current, pos new_position);

    // Return Figure at the position or ptrnull
    Figure* cell_value(int x, int y);
};


#endif //TEST_INO_BOARD_H
