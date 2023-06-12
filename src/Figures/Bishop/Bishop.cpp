#include "Bishop.h"
#include "../auxiliary_functions/diagonals.h"

//! Use constructor of Figure
Bishop::Bishop(int x, int y, bool is_white) : Figure(x, y, is_white) {}

//! Return ID of a figure
/*!
 * King - 1
 * Queen - 2
 * Bishop - 3
 * Knight - 4
 * Rook - 5
 * Pawn - 6
 */
int Bishop::figure_id() {
    return 3;
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
