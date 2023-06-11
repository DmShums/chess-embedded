#ifndef TEST_INO_BISHOP_H
#define TEST_INO_BISHOP_H


#include "Figure.h"

class Bishop: public Figure{
public:
    Bishop(int x, int y, bool is_white);

    //! Change the argument possible_moves that is passed
    void possible_moves(Positions& possible_moves, Board& board) override;
};


#endif //TEST_INO_BISHOP_H
