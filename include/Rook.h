#ifndef TEST_INO_ROOK_H
#define TEST_INO_ROOK_H


#include "Figure.h"

class Rook final : public Figure {
public:
    Rook(int x, int y, bool is_white);

    void possible_moves(Positions &possible_moves, Board &board) override;

    int figure_id() override;
};


#endif //TEST_INO_ROOK_H
