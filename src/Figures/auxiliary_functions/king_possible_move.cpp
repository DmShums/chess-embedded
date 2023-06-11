#include "king_possible_move.h"

/*_______HOW IT WORKS_______
 * We get a Positions of pos where can be an enemy.
 * (1) We check every pos out of there.
 * (2) If there is an enemy, (3) we get possible moves of the enemy in pos_moves.
 * (4) We iterate pos_moves and (5) if there is the position we consider as possible,
 * the function returns false.
 */


//! Return true if it is a possible move for the King
//! position - coordinates of a cell we want to check
//! is_white - color of the King
//! enemy_positions - Positions (class) of positions we have to check for an enemy
bool is_possible_move(pos position, bool is_white, Positions& enemy_positions, Board& board) {
    //! For possible moves of an enemy
    Positions pos_moves = Positions(64);

    //! (1)
    for (int i = 0; i < enemy_positions.get_size(); i++) {
        pos enemy_pos = enemy_positions.get_pos(i);
        //! (2)
        if (board.cell_value(enemy_pos.x, enemy_pos.y) != nullptr) {
            if (board.cell_value(enemy_pos.x, enemy_pos.y)->is_white() != is_white) {
                pos_moves.reset_size();
                //! (3)
                board.cell_value(enemy_pos.x, enemy_pos.y)->possible_moves(pos_moves, board);
                //! (4)
                for (int j = 0; j < pos_moves.get_size(); j++) {
                    //! (5)
                    if ((position.x == pos_moves.get_pos(j).x) && (position.y == pos_moves.get_pos(j).y)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
