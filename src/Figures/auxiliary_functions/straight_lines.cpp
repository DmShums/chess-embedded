#include "straight_lines.h"

void check_straight_lines(pos pos, bool is_white, Positions& possible_moves, Board& board){
    int coeff = 1;

    //! Top
    coeff = 1;
    while (true) {
        //! The cell is out of the board
        if ((pos.x - coeff < 0)) {
            break;
        }

        //! The cell contains a figure
        if (board.cell_value(pos.x - coeff, pos.y) != nullptr) {
            //! The figure has a different color
            if (board.cell_value(pos.x - coeff, pos.y)->is_white() != is_white) {
                //! Add a possible move
                possible_moves.add_pos(pos.x - coeff, pos.y);
            }
            break;
        } else {
            // add a possible move
            possible_moves.add_pos(pos.x - coeff, pos.y);
        }

        coeff++;
    }

    //! Down
    coeff = 1;
    while (true) {
        //! The cell is out of the board
        if ((pos.x + coeff > 7)) {
            break;
        }

        //! The cell contains a figure
        if (board.cell_value(pos.x + coeff, pos.y) != nullptr) {
            //! The figure has a different color
            if (board.cell_value(pos.x + coeff, pos.y)->is_white() != is_white) {
                //! Add a possible move
                possible_moves.add_pos(pos.x + coeff, pos.y);
            }
            break;
        } else {
            //! Add a possible move
            possible_moves.add_pos(pos.x + coeff, pos.y);
        }

        coeff++;
    }

    //! Left
    coeff = 1;
    while (true){
        //! The cell is out of the board
        if ((pos.y - coeff < 0)) {
            break;
        }

        //! The cell contains a figure
        if (board.cell_value(pos.x, pos.y - coeff) != nullptr) {
            //! The figure has a different color
            if (board.cell_value(pos.x, pos.y - coeff)->is_white() != is_white) {
                //! Add a possible move
                possible_moves.add_pos(pos.x, pos.y - coeff);
            }
            break;
        } else {
            //! Add a possible move
            possible_moves.add_pos(pos.x, pos.y - coeff);
        }

        coeff++;
    }

    //! Right
    coeff = 1;
    while (true) {
        //! The cell is out of the board
        if ((pos.y + coeff > 7)) {
            break;
        }

        //! The cell contains a figure
        if (board.cell_value(pos.x, pos.y + coeff) != nullptr) {
            //! The figure has a different color
            if (board.cell_value(pos.x, pos.y + coeff)->is_white() != is_white) {
                //! Add a possible move
                possible_moves.add_pos(pos.x, pos.y + coeff);
            }
            break;
        } else {
            //! Add a possible move
            possible_moves.add_pos(pos.x, pos.y + coeff);
        }

        coeff++;
    }
}
