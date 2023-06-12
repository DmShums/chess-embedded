#include "King.h"
#include "../../structures/pos.h"
#include "../auxiliary_functions/diagonals.h"
#include "../auxiliary_functions/straight_lines.h"
#include "../auxiliary_functions/knight_moves.h"
#include "../auxiliary_functions/king_possible_move.h"

//! Use constructor of Figure
King::King(int x, int y, bool is_white) : Figure(x, y, is_white) {}

//! Return ID of a figure
/*!
 * King - 1
 * Queen - 2
 * Bishop - 3
 * Knight - 4
 * Rook - 5
 * Pawn - 6
 */
int King::figure_id() {
    return 1;
}

//! Change the argument possible_moves that is passed
void King::possible_moves(Positions& possible_moves, Board& board) {
    //! Say that possible_moves is empty
    possible_moves.reset_size();
    //! Save the position of the King
    auto king_pos = get_position();

    //! Save positions, we have to check for an enemy
    //! Capacity is 36 bcs is the number of cells on straight lines, diagonals and possible moves of a Knight
    Positions enemy_positions = Positions(36);

    //! Current position of the King
    //! We will change it to look around the King (+- 1 cell)
    pos cur_pos = pos{king_pos.x, king_pos.y};

    //! down (x + 1, y)
    if (king_pos.x + 1 < 8) {
        //! We will check the cell
        cur_pos = pos{king_pos.x + 1, king_pos.y};
        //! Say that enemy_positions is empty
        enemy_positions.reset_size();

        //! Add to enemy_positions coordinates of cells to check for an enemy
        check_diagonals(cur_pos, is_white(), enemy_positions, board);
        check_straight_lines(cur_pos, is_white(), enemy_positions, board);
        check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

        //! Add the move if it is possible
        if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
            possible_moves.add_pos(cur_pos.x, cur_pos.y);
        }
    }

    //! top (x - 1, y)
    if (king_pos.x - 1 >= 0) {
        cur_pos = pos{king_pos.x - 1, king_pos.y};
        enemy_positions.reset_size();

        check_diagonals(cur_pos, is_white(), enemy_positions, board);
        check_straight_lines(cur_pos, is_white(), enemy_positions, board);
        check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

        if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
            possible_moves.add_pos(cur_pos.x, cur_pos.y);
        }
    }

    //! right (x, y + 1)
    if (king_pos.y + 1 < 8) {
        cur_pos = pos{king_pos.x + 1, king_pos.y};
        enemy_positions.reset_size();

        check_diagonals(cur_pos, is_white(), enemy_positions, board);
        check_straight_lines(cur_pos, is_white(), enemy_positions, board);
        check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

        if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
            possible_moves.add_pos(cur_pos.x, cur_pos.y);
        }
    }

    //! left (x, y - 1)
    if (king_pos.y - 1 >= 0) {
        cur_pos = pos{king_pos.x, king_pos.y - 1};
        enemy_positions.reset_size();

        check_diagonals(cur_pos, is_white(), enemy_positions, board);
        check_straight_lines(cur_pos, is_white(), enemy_positions, board);
        check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

        if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
            possible_moves.add_pos(cur_pos.x, cur_pos.y);
        }
    }

    //! down right (x + 1, y + 1)
    if ((king_pos.x + 1 < 8) && (king_pos.y + 1 < 8)) {
        cur_pos = pos{king_pos.x + 1, king_pos.y + 1};
        enemy_positions.reset_size();

        check_diagonals(cur_pos, is_white(), enemy_positions, board);
        check_straight_lines(cur_pos, is_white(), enemy_positions, board);
        check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

        if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
            possible_moves.add_pos(cur_pos.x, cur_pos.y);
        }
    }

    //! down left (x + 1, y - 1)
    if ((king_pos.x + 1 < 8) && (king_pos.y - 1 >= 0)) {
        cur_pos = pos{king_pos.x + 1, king_pos.y - 1};
        enemy_positions.reset_size();

        check_diagonals(cur_pos, is_white(), enemy_positions, board);
        check_straight_lines(cur_pos, is_white(), enemy_positions, board);
        check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

        if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
            possible_moves.add_pos(cur_pos.x, cur_pos.y);
        }
    }

    //! top right (x - 1, y + 1)
    if ((king_pos.x - 1 >= 0) && (king_pos.y + 1 < 8)) {
        cur_pos = pos{king_pos.x - 1, king_pos.y + 1};
        enemy_positions.reset_size();

        check_diagonals(cur_pos, is_white(), enemy_positions, board);
        check_straight_lines(cur_pos, is_white(), enemy_positions, board);
        check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

        if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
            possible_moves.add_pos(cur_pos.x, cur_pos.y);
        }
    }

    //! top left (x - 1, y - 1)
    if ((king_pos.x - 1 >= 0) && (king_pos.y - 1 >= 0)) {
        cur_pos = pos{king_pos.x - 1, king_pos.y - 1};
        enemy_positions.reset_size();

        check_diagonals(cur_pos, is_white(), enemy_positions, board);
        check_straight_lines(cur_pos, is_white(), enemy_positions, board);
        check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

        if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
            possible_moves.add_pos(cur_pos.x, cur_pos.y);
        }
    }

}
