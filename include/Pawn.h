#ifndef TEST_INO_PAWN_H
#define TEST_INO_PAWN_H

// N: So malloc works
#include <stdlib.h>

// bullshit?
#include "Figure.h"

class Pawn: public Figure {
private:
    bool is_at_starting_position = true;

public:
    // use constructor for Figure
    Pawn(int x, int y, bool is_white);
    // by default it is true
    bool two_step_move = false;

    // change the argument possible_moves that is passed
    void possible_moves(Positions& possible_moves, Board& board) override;
    int figure_id() override;

    bool getIsAtStartingPosition() const;
    void setIsAtStartingPosition(bool isAtStartingPosition);
};


#endif //TEST_INO_PAWN_H
