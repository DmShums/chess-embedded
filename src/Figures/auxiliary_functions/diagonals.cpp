#include "diagonals.h"

//! Check diagonals
void check_diagonals(pos pos, bool is_white, Positions &possible_moves, Board &board) {
    //! Right down diagonal
    int coeff = 1;
    while (true) {
        //! The cell is out of the board
        if ((pos.x + coeff > 7) || (pos.y + coeff > 7)) {
            break;
        }

        //! The cell contains a figure
        if (board.cell_value(pos.x + coeff, pos.y + coeff) != nullptr) {
            //! The figure has a different color
            if (board.cell_value(pos.x + coeff, pos.y + coeff)->is_white() != is_white) {
                //! Add a possible move
                possible_moves.add_pos(pos.x + coeff, pos.y + coeff);
            }
            break;
        } else {
            //! Add a possible move
            possible_moves.add_pos(pos.x + coeff, pos.y + coeff);
        }

        coeff = coeff + 1;
    }

    //! Right top diagonal
    coeff = 1;
    while (true) {
        //! The cell is out of the board
        if ((pos.x - coeff < 0) || (pos.y + coeff > 7)) {
            break;
        }

        //! The cell contains a figure
        if (board.cell_value(pos.x - coeff, pos.y + coeff) != nullptr) {
            //! The figure has a different color
            if (board.cell_value(pos.x - coeff, pos.y + coeff)->is_white() != is_white) {
                //! Add a possible move
                possible_moves.add_pos(pos.x - coeff, pos.y + coeff);
            }
            break;
        } else {
            //! Add a possible move
            possible_moves.add_pos(pos.x - coeff, pos.y + coeff);
        }

        coeff = coeff + 1;
    }

    //! Left down diagonal
    coeff = 1;
    while (true) {
        //! The cell is out of the board
        if ((pos.x + coeff > 7) || (pos.y - coeff < 0)) {
            break;
        }

        //! The cell contains a figure
        if (board.cell_value(pos.x + coeff, pos.y - coeff) != nullptr) {
            //! The figure has a different color
            if (board.cell_value(pos.x + coeff, pos.y - coeff)->is_white() != is_white) {
                //! Add a possible move
                possible_moves.add_pos(pos.x + coeff, pos.y - coeff);
            }
            break;
        } else {
            //! Add a possible move
            possible_moves.add_pos(pos.x + coeff, pos.y - coeff);
        }

        coeff++;
    }

    //! Left top diagonal
    coeff = 1;
    while (true) {
        //! The cell is out of the board
        if ((pos.x - coeff < 0) || (pos.y - coeff < 0)) {
            break;
        }

        //! The cell contains a figure
        if (board.cell_value(pos.x - coeff, pos.y - coeff) != nullptr) {
            //! The figure has a different color
            if (board.cell_value(pos.x - coeff, pos.y - coeff)->is_white() != is_white) {
                //! Add a possible move
                possible_moves.add_pos(pos.x - coeff, pos.y - coeff);
            }
            break;
        } else {
            //! Add a possible move
            possible_moves.add_pos(pos.x - coeff, pos.y - coeff);
        }

        coeff++;
    }
};
