#include "Rook.h"
#include "straight_lines.h"

//! Use constructor of Figure
Rook::Rook(int x, int y, bool is_white) : Figure(x, y, is_white) {}

//! Return ID of a figure
/*!
 * King - 1
 * Queen - 2
 * Bishop - 3
 * Knight - 4
 * Rook - 5
 * Pawn - 6
 */
int Rook::figure_id() {
    return 5;
}

//! Change the argument possible_moves that is passed
void Rook::possible_moves(Positions& possible_moves, Board& board) {
    //! Say that possible_moves is empty
    possible_moves.reset_size();
    //! Save position of the Queen
    auto pos = get_position();

    //! Check all of straight lines for possible moves
    check_straight_lines(pos, is_white(), possible_moves, board);

}

