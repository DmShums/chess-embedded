#ifndef TEST_INO_KNIGHT_H
#define TEST_INO_KNIGHT_H


#include "Figure.h"

class Knight: public Figure{
public:
    Knight(int x, int y, bool is_white);

    void possible_moves(Positions& possible_moves, Board& board) override;
};


#endif //TEST_INO_KNIGHT_H
