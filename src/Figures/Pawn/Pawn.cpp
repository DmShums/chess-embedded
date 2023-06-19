#include "Pawn.h"

Pawn::Pawn(int x, int y, bool is_white) : Figure(x, y, is_white) {}

//! Return ID of a figure
/*!
 * King - 1
 * Queen - 2
 * Bishop - 3
 * Knight - 4
 * Rook - 5
 * Pawn - 6
 */

int Pawn::figure_id() {
    return 6;
}

void Pawn::possible_moves(Positions &possible_moves, Board &board) {
    possible_moves.reset_size();
    auto pos = get_position();

    int forward_direction = is_white() ? 1 : -1;

    // Move forward if the cell is empty
    if (board.cell_value(pos.x + forward_direction, pos.y) == nullptr) {
        possible_moves.add_pos(pos.x + forward_direction, pos.y);

        // Move two steps forward from the starting position
        if (is_at_starting_position && board.cell_value(pos.x + 2 * forward_direction, pos.y) == nullptr) {
            possible_moves.add_pos(pos.x + 2 * forward_direction, pos.y);
        }
    }

    // Capture diagonally if there is an opponent's piece
    if (board.cell_value(pos.x + forward_direction, pos.y + 1) != nullptr &&
        board.cell_value(pos.x + forward_direction, pos.y + 1)->is_white() != is_white()) {
        possible_moves.add_pos(pos.x + forward_direction, pos.y + 1);
    }

    if (board.cell_value(pos.x + forward_direction, pos.y - 1) != nullptr &&
        board.cell_value(pos.x + forward_direction, pos.y - 1)->is_white() != is_white()) {
        possible_moves.add_pos(pos.x + forward_direction, pos.y - 1);
    }

    //en passant
    // left side en passant
    // if it is on the same horizontal line should it look like this?
    // add board.cell_value(pos.x, pos.y - 1)->two_step_move
    if (!is_at_starting_position &&
        board.cell_value(pos.x, pos.y - 1) != nullptr &&
        board.cell_value(pos.x, pos.y - 1)->is_white() != is_white() &&
        board.cell_value(pos.x, pos.y - 1)->figure_id() == 6) {
        if (((Pawn *)board.cell_value(pos.x, pos.y - 1))->two_step_move) {
            possible_moves.add_pos(pos.x + forward_direction, pos.y - 1);
        }
    }

    // right side en passant
    if (!is_at_starting_position &&
        board.cell_value(pos.x, pos.y + 1) != nullptr &&
        board.cell_value(pos.x, pos.y + 1)->is_white() != is_white() &&
        board.cell_value(pos.x, pos.y + 1)->figure_id() == 6) {
        if (((Pawn *)board.cell_value(pos.x, pos.y + 1))->two_step_move) {
            possible_moves.add_pos(pos.x + forward_direction, pos.y + 1);
        }
    }
}