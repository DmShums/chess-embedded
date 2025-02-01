#include "Board.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"

#include "State.h"
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

    // Set empty spots
    for (auto & row : board) {
        for (auto & cell : row) {
            cell = nullptr;
        }
    }

    // Initialize the white figures
    //    board[0][0] = new Rook(0, 0, true); //! no magnits
    //    board[0][1] = new Knight(0, 1, true);
    //    board[0][2] = new Bishop(0, 2, true);
    //    board[0][3] = new King(0, 3, true);
    board[0][4] = new Queen(0, 4, true);
    board[0][5] = new Bishop(0, 5, true);
    board[0][6] = new Knight(0, 6, true);
    board[0][7] = new Rook(0, 7, true);

    // // Initialize the white pawns
    // for (int col = 0; col < 8; col++) {
    //     board[1][col] = new Pawn(1, col, true);
    // }

    // Initialize the black figures
    //     board[7][0] = new Rook(7, 0, false);
    // //    board[7][1] = new Knight(7, 1, false);
    //     board[7][2] = new Bishop(7, 2, false);
    //     board[7][3] = new King(7, 3, false);
    //     board[7][4] = new Queen(7, 4, false);
    //     board[7][5] = new Bishop(7, 5, false);
    // //    board[7][6] = new Knight(7, 6, false);
    //     board[7][7] = new Rook(7, 7, false);

    // Initialize the black pawns
    for (int col = 3; col < 6; col++) {
        board[6][col] = new Pawn(6, col, false);
    }
    // Initialize the empty positions
    //    for (int row = 2; row < 6; row++) {
    //        for (int col = 0; col < 8; col++) {
    //            board[row][col] = nullptr;
    //        }
    //    }
}


// Return Figure at the position or ptrnull
Figure *Board::cell_value(const int x, const int y) const {
    return board[x][y];
}

void Board::make_move(const pos current, const pos new_position) {
    // check if figure exists on the current cell
    if (board[current.x][current.y] != nullptr) {
        // check if figure exists on the current cell
        if (board[new_position.x][new_position.y] == nullptr) {
            set_figure(current, new_position);
            delete_figure(current);
        }
    }
}

void Board::set_figure(const pos current, const pos new_position) {
    board[new_position.x][new_position.y] = board[current.x][current.y];
}

void Board::delete_figure(const pos position) {
    board[position.x][position.y] = nullptr;
}

Figure *Board::get_lifted() const {
    return lifted_fig;
}

void Board::lift_figure(const pos position, State *state) {
    state->figure_up(true);
    lifted_fig = board[position.x][position.y];
    board[position.x][position.y] = nullptr;

    auto possible_moves = Positions();
    lifted_fig->possible_moves(possible_moves, *this);
    highlight::hint_on(possible_moves, *this);
    highlight::show();
}

void Board::lower_figure(const pos position, State *state) {
    state->figure_up(false);
    board[position.x][position.y] = lifted_fig;
    lifted_fig->new_position(position.x, position.y);
    lifted_fig = nullptr;
    highlight::reset();
    highlight::show();
}

void Board::toggle_cell(const pos position, State *state) {
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

Figure *Board::operator[](const pos &position) const {
    return board[position.x][position.y];
}
