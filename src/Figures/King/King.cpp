#include "King.h"
#include "pos.h"
#include "diagonals.h"
#include "straight_lines.h"
#include "knight_moves.h"
#include "king_possible_move.h"
#include "utils.h"

//! Use constructor of Figure
King::King(int x, int y, bool is_white) : Figure(x, y, is_white) {
}

int King::figure_id() {
    return KING;
}

void King::possible_moves(Positions &possible_moves, Board &board) {
    //! Set size of the array equal to 0
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
        if ((board.cell_value(cur_pos.x, cur_pos.y) != nullptr and board.cell_value(cur_pos.x, cur_pos.y)->is_white() !=
             is_white()) or board.cell_value(cur_pos.x, cur_pos.y) == nullptr) {
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
    }

    //! top (x - 1, y)
    if (king_pos.x - 1 >= 0) {
        cur_pos = pos{king_pos.x - 1, king_pos.y};
        if ((board.cell_value(cur_pos.x, cur_pos.y) != nullptr and board.cell_value(cur_pos.x, cur_pos.y)->is_white() !=
             is_white()) or board.cell_value(cur_pos.x, cur_pos.y) == nullptr) {
            enemy_positions.reset_size();

            check_diagonals(cur_pos, is_white(), enemy_positions, board);
            check_straight_lines(cur_pos, is_white(), enemy_positions, board);
            check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

            if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
                possible_moves.add_pos(cur_pos.x, cur_pos.y);
            }
        }
    }

    //! right (x, y + 1)
    if (king_pos.y + 1 < 8) {
        cur_pos = pos{king_pos.x, king_pos.y + 1};
        if ((board.cell_value(cur_pos.x, cur_pos.y) != nullptr and board.cell_value(cur_pos.x, cur_pos.y)->is_white() !=
             is_white()) or board.cell_value(cur_pos.x, cur_pos.y) == nullptr) {
            enemy_positions.reset_size();

            check_diagonals(cur_pos, is_white(), enemy_positions, board);
            check_straight_lines(cur_pos, is_white(), enemy_positions, board);
            check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

            if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
                possible_moves.add_pos(cur_pos.x, cur_pos.y);
            }
        }
    }

    //! left (x, y - 1)
    if (king_pos.y - 1 >= 0) {
        cur_pos = pos{king_pos.x, king_pos.y - 1};
        if ((board.cell_value(cur_pos.x, cur_pos.y) != nullptr and board.cell_value(cur_pos.x, cur_pos.y)->is_white() !=
             is_white()) or board.cell_value(cur_pos.x, cur_pos.y) == nullptr) {
            enemy_positions.reset_size();

            check_diagonals(cur_pos, is_white(), enemy_positions, board);
            check_straight_lines(cur_pos, is_white(), enemy_positions, board);
            check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

            if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
                possible_moves.add_pos(cur_pos.x, cur_pos.y);
            }
        }
    }

    //! down right (x + 1, y + 1)
    if ((king_pos.x + 1 < 8) && (king_pos.y + 1 < 8)) {
        cur_pos = pos{king_pos.x + 1, king_pos.y + 1};
        if ((board.cell_value(cur_pos.x, cur_pos.y) != nullptr and board.cell_value(cur_pos.x, cur_pos.y)->is_white() !=
             is_white()) or board.cell_value(cur_pos.x, cur_pos.y) == nullptr) {
            enemy_positions.reset_size();

            check_diagonals(cur_pos, is_white(), enemy_positions, board);
            check_straight_lines(cur_pos, is_white(), enemy_positions, board);
            check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

            if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
                possible_moves.add_pos(cur_pos.x, cur_pos.y);
            }
        }
    }

    //! down left (x + 1, y - 1)
    if ((king_pos.x + 1 < 8) && (king_pos.y - 1 >= 0)) {
        cur_pos = pos{king_pos.x + 1, king_pos.y - 1};
        if ((board.cell_value(cur_pos.x, cur_pos.y) != nullptr and board.cell_value(cur_pos.x, cur_pos.y)->is_white() !=
             is_white()) or board.cell_value(cur_pos.x, cur_pos.y) == nullptr) {
            enemy_positions.reset_size();

            check_diagonals(cur_pos, is_white(), enemy_positions, board);
            check_straight_lines(cur_pos, is_white(), enemy_positions, board);
            check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

            if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
                possible_moves.add_pos(cur_pos.x, cur_pos.y);
            }
        }
    }

    //! top right (x - 1, y + 1)
    if ((king_pos.x - 1 >= 0) && (king_pos.y + 1 < 8)) {
        cur_pos = pos{king_pos.x - 1, king_pos.y + 1};
        if ((board.cell_value(cur_pos.x, cur_pos.y) != nullptr and board.cell_value(cur_pos.x, cur_pos.y)->is_white() !=
             is_white()) or board.cell_value(cur_pos.x, cur_pos.y) == nullptr) {
            enemy_positions.reset_size();

            check_diagonals(cur_pos, is_white(), enemy_positions, board);
            check_straight_lines(cur_pos, is_white(), enemy_positions, board);
            check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

            if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
                possible_moves.add_pos(cur_pos.x, cur_pos.y);
            }
        }
    }

    //! top left (x - 1, y - 1)
    if ((king_pos.x - 1 >= 0) && (king_pos.y - 1 >= 0)) {
        cur_pos = pos{king_pos.x - 1, king_pos.y - 1};
        if ((board.cell_value(cur_pos.x, cur_pos.y) != nullptr and board.cell_value(cur_pos.x, cur_pos.y)->is_white() !=
             is_white()) or board.cell_value(cur_pos.x, cur_pos.y) == nullptr) {
            enemy_positions.reset_size();

            check_diagonals(cur_pos, is_white(), enemy_positions, board);
            check_straight_lines(cur_pos, is_white(), enemy_positions, board);
            check_knight_moves(cur_pos, is_white(), enemy_positions, board); // It does not work and I do not know why

            if (is_possible_move(cur_pos, is_white(), enemy_positions, board)) {
                possible_moves.add_pos(cur_pos.x, cur_pos.y);
            }
        }
    }

    // add castling right(short)
    if (king_pos.y + 3 == 7) {
        if (board.cell_value(king_pos.x, king_pos.y + 3) != nullptr &&
            board.cell_value(king_pos.x, king_pos.y + 3)->figure_id() == 5 &&
            board.cell_value(king_pos.x, king_pos.y + 3)->is_white() == is_white() &&
            board.cell_value(king_pos.x, king_pos.y + 1) == nullptr &&
            board.cell_value(king_pos.x, king_pos.y + 2) == nullptr) {
            possible_moves.add_pos(king_pos.x, king_pos.y + 2);
        }
    }

    // add castling left(long)
    if (king_pos.y - 4 == 0) {
        if (board.cell_value(king_pos.x, king_pos.y - 4) != nullptr &&
            board.cell_value(king_pos.x, king_pos.y - 4)->figure_id() == 5 &&
            board.cell_value(king_pos.x, king_pos.y - 4)->is_white() == is_white() &&
            board.cell_value(king_pos.x, king_pos.y - 1) == nullptr &&
            board.cell_value(king_pos.x, king_pos.y - 2) == nullptr) {
            possible_moves.add_pos(king_pos.x, king_pos.y - 3);
        }
    }
}
