#include "Queen.h"
#include "diagonals.h"
#include "straight_lines.h"
#include "utils.h"

//! Use constructor of Figure
Queen::Queen(int x, int y, bool is_white) : Figure(x, y, is_white) {
}

int Queen::figure_id() {
    return QUEEN;
}

//! Change the argument possible_moves that is passed
void Queen::possible_moves(Positions &possible_moves, Board &board) {
    //! Say that possible_moves is empty
    possible_moves.reset_size();
    //! Save position of the Queen
    auto pos = get_position();

    //! Check diagonals for possible moves
    check_diagonals(pos, is_white(), possible_moves, board);
    //! Check all of straight lines for possible moves
    check_straight_lines(pos, is_white(), possible_moves, board);
}
