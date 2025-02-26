#ifndef TEST_INO_QUEEN_H
#define TEST_INO_QUEEN_H


#include "Figure.h"

class Queen final : public Figure {
public:
    Queen(int x, int y, bool is_white);

    void possible_moves(Positions &possible_moves, Board &board) override;

    int figure_id() override;
};


#endif //TEST_INO_QUEEN_H
