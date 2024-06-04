#ifndef TEST_INO_BOARD_H
#define TEST_INO_BOARD_H


#include "pos.h"
#include "Figure.h"
//#include <stdlib.h>

#include "State.h"

class Figure;
class State;

class Board {
private:
    Figure *board[8][8];
    Figure* lifted_fig;

public:
    bool is_white = true;

    Board();

    ~Board() {
        for (auto &i : board) {
            for (auto &j : i) {
                if (j != nullptr) {
                    delete j;
                }
            }
        }
    }

    // Print the chessboard to the console
//    void print_board();
    void make_move(pos current, pos new_position);

    void set_figure(pos current, pos new_position);

    void delete_figure(pos position);

    void init_board();

    Figure* get_lifted();

    void lift_figure(pos position, State* state);

    void lower_figure(pos position, State* state);

    void toggle_cell(pos position, State* state);


    void add_fig(pos position, Figure *fig);

    // Return Figure at the position or ptrnull
    Figure *cell_value(int x, int y);
};


#endif //TEST_INO_BOARD_H
