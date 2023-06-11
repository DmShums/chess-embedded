#include "knight_moves.h"

void check_knight_moves(pos pos, bool is_white, Positions& possible_moves, Board& board) {
    //! Const (move of a knight consist of such moves)
    int COEFF_1 = 1;
    int COEFF_2 = 2;

    //! x + COEFF_1, y + COEFF_2
    if ((pos.x + COEFF_1 < 8) && (pos.y + COEFF_2 < 8)) {
        if (board.cell_value(pos.x + COEFF_1, pos.y + COEFF_2) == nullptr) {
            //! Add a possible move
            possible_moves.add_pos(pos.x + COEFF_1, pos.y + COEFF_2);
        } else if (board.cell_value(pos.x + COEFF_1, pos.y + COEFF_2)->is_white() != is_white) {
            //! Add a possible move
            possible_moves.add_pos(pos.x + COEFF_1, pos.y + COEFF_2);
        }
    }

    //! x + COEFF_1, y - COEFF_2
    if ((pos.x + COEFF_1 < 8) && (pos.y - COEFF_2 >= 0)) {
        if (board.cell_value(pos.x + COEFF_1, pos.y - COEFF_2) == nullptr) {
            //! Add a possible move
            possible_moves.add_pos(pos.x + COEFF_1, pos.y - COEFF_2);
        } else if (board.cell_value(pos.x + COEFF_1, pos.y - COEFF_2)->is_white() != is_white) {
            //! Add a possible move
            possible_moves.add_pos(pos.x + COEFF_1, pos.y - COEFF_2);
        }
    }

    //! x - COEFF_1, y - COEFF_2
    if ((pos.x - COEFF_1 >= 0) && (pos.y - COEFF_2 >= 0)) {
        if (board.cell_value(pos.x - COEFF_1, pos.y - COEFF_2) == nullptr) {
            //! Add a possible move
            possible_moves.add_pos(pos.x - COEFF_1, pos.y - COEFF_2);
        } else if (board.cell_value(pos.x - COEFF_1, pos.y - COEFF_2)->is_white() != is_white) {
            //! Add a possible move
            possible_moves.add_pos(pos.x - COEFF_1, pos.y - COEFF_2);
        }
    }

    //! x - COEFF_1, y + COEFF_2
    if ((pos.x - COEFF_1 >= 0) && (pos.y + COEFF_2 < 8)) {
        if (board.cell_value(pos.x - COEFF_1, pos.y + COEFF_2) == nullptr) {
            // add a possible move
            possible_moves.add_pos(pos.x - COEFF_1, pos.y + COEFF_2);
        } else if (board.cell_value(pos.x - COEFF_1, pos.y + COEFF_2)->is_white() != is_white) {
            // add a possible move
            possible_moves.add_pos(pos.x - COEFF_1, pos.y + COEFF_2);
        }
    }

    //! x + COEFF_2, y + COEFF_1
    if ((pos.x + COEFF_2 < 8) && (pos.y + COEFF_1 < 8)) {
        if (board.cell_value(pos.x + COEFF_2, pos.y + COEFF_1) == nullptr) {
            //! Add a possible move
            possible_moves.add_pos(pos.x + COEFF_2, pos.y + COEFF_1);
        } else if (board.cell_value(pos.x + COEFF_2, pos.y + COEFF_1)->is_white() != is_white) {
            //! Add a possible move
            possible_moves.add_pos(pos.x + COEFF_2, pos.y + COEFF_1);
        }
    }

    //! x + COEFF_2, y - COEFF_1
    if ((pos.x + COEFF_2 < 8) && (pos.y - COEFF_1 >= 0)) {
        if (board.cell_value(pos.x + COEFF_2, pos.y - COEFF_1) == nullptr) {
            //! Add a possible move
            possible_moves.add_pos(pos.x + COEFF_2, pos.y - COEFF_1);
        } else if (board.cell_value(pos.x + COEFF_2, pos.y - COEFF_1)->is_white() != is_white) {
            //! Add a possible move
            possible_moves.add_pos(pos.x + COEFF_2, pos.y - COEFF_1);
        }
    }

    //! x - COEFF_2, y - COEFF_1
    if ((pos.x - COEFF_2 >= 0) && (pos.y - COEFF_1 >= 0)) {
        if (board.cell_value(pos.x - COEFF_2, pos.y - COEFF_1) == nullptr) {
            //! Add a possible move
            possible_moves.add_pos(pos.x - COEFF_2, pos.y - COEFF_1);
        } else if (board.cell_value(pos.x - COEFF_2, pos.y - COEFF_1)->is_white() != is_white) {
            //! Add a possible move
            possible_moves.add_pos(pos.x - COEFF_2, pos.y - COEFF_1);
        }
    }

    //! x - COEFF_2, y + COEFF_1
    if ((pos.x - COEFF_2 >= 0) && (pos.y + COEFF_1 < 8)) {
        if (board.cell_value(pos.x - COEFF_2, pos.y + COEFF_1) == nullptr) {
            //! Add a possible move
            possible_moves.add_pos(pos.x - COEFF_2, pos.y + COEFF_1);
        } else if (board.cell_value(pos.x - COEFF_2, pos.y + COEFF_1)->is_white() != is_white){
            //! Add a possible move
            possible_moves.add_pos(pos.x - COEFF_2, pos.y + COEFF_1);
        }
    }
}
