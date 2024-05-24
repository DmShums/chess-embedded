#include "Board.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"

#include "State.h"

#include "Arduino.h"
#include "Highlight.h"

Board::Board() {
    init_board();
}

//! Delete it
void Board::add_fig(pos position, Figure *fig) {
    board[position.x][position.y] = fig;
}

void Board::init_board() {
    // Fill the chessboard with some initial values

    lifted_fig = nullptr;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = nullptr;
        }
    }

//    board[0][0] = new Knight(0, 0, true); //! old for v1
//    board[2][1] = new Knight(2, 1, false);

    // Initialize the white figures
//    board[0][0] = new Rook(0, 0, true); //! no magnits
//    board[0][1] = new Knight(0, 1, true);
//    board[0][2] = new Bishop(0, 2, true);
//    board[0][3] = new King(0, 3, true);
    board[0][4] = new Queen(0, 4, true);
    board[0][5] = new Bishop(0, 5, true);
//    board[0][6] = new Knight(0, 6, true);
    board[0][7] = new Rook(0, 7, true);

    // Initialize the white pawns
    for (int col = 0; col < 8; col++) {
        board[1][col] = new Pawn(1, col, true);
    }

    // Initialize the black figures
    board[7][0] = new Rook(7, 0, false);
//    board[7][1] = new Knight(7, 1, false);
    board[7][2] = new Bishop(7, 2, false);
    board[7][3] = new King(7, 3, false);
    board[7][4] = new Queen(7, 4, false);
    board[7][5] = new Bishop(7, 5, false);
//    board[7][6] = new Knight(7, 6, false);
    board[7][7] = new Rook(7, 7, false);

    // Initialize the black pawns
    for (int col = 0; col < 8; col++) {
        board[6][col] = new Pawn(6, col, false);
    }

    // Initialize the empty positions
//    for (int row = 2; row < 6; row++) {
//        for (int col = 0; col < 8; col++) {
//            board[row][col] = nullptr;
//        }
//    }
}


// Temporary function to print board. I have a bit changed it, so it prints a number of each row
// void Board::print_board() {
//     for (int row = 0; row < 8; row++) {
//         std::cout << row << " ";
//         for (int col = 0; col < 8; col++) {
//             std::cout << ((board[row][col] == nullptr) ? 0: board[row][col]->figure_id()) << ((col == 7) ? "" : "_");
//         }
//         std::cout << std::endl;
//     }
// }

// Return Figure at the position or ptrnull
Figure *Board::cell_value(int x, int y) {
    return board[x][y];
}

void Board::make_move(pos current, pos new_position) {
    if (is_white) {
        // check if figure exists on the current cell
        if (board[current.x][current.y] != nullptr) {
            // check if figure exists on the current cell
            if (board[new_position.x][new_position.y] == nullptr) {
                set_figure(current, new_position);
                delete_figure(current);
            }
            is_white = false;
        }
    } else {
        // check if figure exists on the current cell
        if (board[current.x][current.y] != nullptr) {
            // check if figure exists on the current cell
            if (board[new_position.x][new_position.y] == nullptr) {
                set_figure(current, new_position);
                delete_figure(current);
            }
            is_white = true;
        }
    }
}

void Board::set_figure(pos current, pos new_position) {
    board[new_position.x][new_position.y] = board[current.x][current.y];
}

void Board::delete_figure(pos position) {
    board[position.x][position.y] = nullptr;
}

Figure *Board::get_lifted() {
    return lifted_fig;
}

void Board::lift_figure(pos position, State* state) {
    state->figure_up(true);
    lifted_fig = board[position.x][position.y];
    board[position.x][position.y] = nullptr;

    Positions possible_moves = Positions(64);
    lifted_fig->possible_moves(possible_moves, *this);
    highlight::hint_on(possible_moves, *this);
    highlight::show();
}

void Board::lower_figure(pos position, State* state) {
    state->figure_up(false);
    board[position.x][position.y] = lifted_fig;
    lifted_fig->new_position(position.x, position.y);
    lifted_fig = nullptr;
    highlight::reset();
    highlight::show();
}

void Board::toggle_cell(pos position, State* state) {
    highlight::reset();
    if (state->get_bool_fig_up()) {
        if (cell_value(position.x, position.y) == nullptr) {
            lower_figure(position, state);
        } else {
            delete_figure(position);
        }
    } else {
        lift_figure(position, state);
    }
}