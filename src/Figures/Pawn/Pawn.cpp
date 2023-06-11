#include "Pawn.h"

Pawn::Pawn(int x, int y, bool is_white) : Figure(x, y, is_white) {}

void Pawn::possible_moves(Positions &possible_moves, Board &board) {
    possible_moves.reset_size();
    auto pos = get_position();

    //! The cell contains a figure (right-top)
    if (board.cell_value(pos.x + 1, pos.y + 1) != nullptr){
        // the figure has a different color
        if (board.cell_value(pos.x + 1, pos.y + 1)->is_white() != is_white()) {
            // add a possible move
            possible_moves.add_pos(pos.x + 1, pos.y + 1);
        }
    }

    //! The cell contains a figure (left-top)
    if (board.cell_value(pos.x + 1, pos.y - 1) != nullptr){
        // the figure has a different color
        if (board.cell_value(pos.x + 1, pos.y - 1)->is_white() != is_white()) {
            // add a possible move
            possible_moves.add_pos(pos.x + 1, pos.y - 1);
        }
    }

    //! The cell contains a figure (right-bottom)
    if (board.cell_value(pos.x - 1, pos.y + 1) != nullptr){
        //! The figure has a different color
        if (board.cell_value(pos.x - 1, pos.y + 1)->is_white() == is_white()) {
            //! Add a possible move
            possible_moves.add_pos(pos.x - 1, pos.y + 1);
        }
    }

    //! The cell contains a figure (right-bottom)
    if (board.cell_value(pos.x - 1, pos.y - 1) != nullptr){
        //! The figure has a different color
        if (board.cell_value(pos.x - 1, pos.y - 1)->is_white() == is_white()) {
            //! Add a possible move
            possible_moves.add_pos(pos.x - 1, pos.y - 1);
        }
    }

    //! The cell doesn't contain a figure (top)
    if (board.cell_value(pos.x, pos.y)->is_white() == is_white()) {
        if (board.cell_value(pos.x + 1, pos.y) == nullptr) {
            possible_moves.add_pos(pos.x + 1, pos.y);
        }
    }

    //! The cell doesn't contain a figure (bottom)
    if (board.cell_value(pos.x, pos.y)->is_white() != is_white()) {
        if (board.cell_value(pos.x - 1, pos.y) == nullptr) {
            possible_moves.add_pos(pos.x - 1, pos.y);
        }
    }

}