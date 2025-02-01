#ifndef TEST_INO_KING_H
#define TEST_INO_KING_H


#include "Figure.h"

class King final : public Figure {
public:
    King(int x, int y, bool is_white);

    /**
     * Changes the argument possible_moves that is passed
     *
     * @param possible_moves - array of pos'
     * @param board
     */
    void possible_moves(Positions &possible_moves, Board &board) override;

    /**
     *
     * @return
     */
    int figure_id() override;
};


#endif //TEST_INO_KING_H
