#include "Knight.h"
#include "knight_moves.h"

//! Use constructor of Figure
Knight::Knight(int x, int y, bool is_white) : Figure(x, y, is_white) {}

//! Return ID of a figure
/*!
 * King - 1
 * Queen - 2
 * Bishop - 3
 * Knight - 4
 * Rook - 5
 * Pawn - 6
 */
int Knight::figure_id() {
    return 4;
}

//! Change the argument possible_moves that is passed
void Knight::possible_moves(Positions& possible_moves, Board& board){
    //! Say that possible_moves is empty
    possible_moves.reset_size();
    //! Save position of the Knight
    auto pos = get_position();

    //! Check possible moves of the Knight
    check_knight_moves(pos, is_white(), possible_moves, board);

}
