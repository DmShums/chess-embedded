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

    // check where to move
    int forward_direction = is_white() ? 1 : -1;

    // Move forward if the cell is empty
    if (board.cell_value(pos.x + forward_direction, pos.y) == nullptr) {
        possible_moves.add_pos(pos.x + forward_direction, pos.y);
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

}
