//
// Created by Shuma on 25.04.2023.
//

#ifndef TEST_INO_PAWN_H
#define TEST_INO_PAWN_H

// N: So malloc works
#include <cstdlib>

// bullshit?
#include "Figure.h"

class Pawn: public Figure {
public:
    // use constructor for Figure
    Pawn(int x, int y, bool is_white);

    // change the argument possible_moves that is passed
    void possible_moves(Positions& possible_moves, Board& board) override;
};


#endif //TEST_INO_PAWN_H
