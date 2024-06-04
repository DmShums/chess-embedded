#include "Bishop.h"
#include "diagonals.h"
#include "utils.h"

//! Use constructor of Figure
Bishop::Bishop(int x, int y, bool is_white) : Figure(x, y, is_white) {}

int Bishop::figure_id() {
    return BISHOP;
}

//! Change the argument possible_moves that is passed
void Bishop::possible_moves(Positions& possible_moves, Board& board) {
    //! Say that possible_moves is empty
    possible_moves.reset_size();
    //! Save position of the Queen
    auto bishop_position = get_position();

    //! Check diagonals for possible moves
    check_diagonals(bishop_position, is_white(), possible_moves, board);
}
