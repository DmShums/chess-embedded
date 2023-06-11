#include <iostream>
#include "Board.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"


Board::Board() {
    // Fill the chessboard with some initial values

    // Initialize the white figures
    board[0][0] = new Rook(1, 0, true);
    board[0][1] = new Knight(0, 1, true);
    board[0][2] = new Bishop(0, 2, true);
    board[0][3] = new King(0, 4, true);
    board[0][4] = new Queen(0, 3, true);
    board[0][5] = new Bishop(0, 5, true);
    board[0][6] = new Knight(0, 6, true);
    board[0][7] = new Rook(0, 7, true);

    // Initialize the white pawns
    for (int col = 0; col < 8; col++) {
        board[1][col] = new Pawn(1, col, true);
    }

    // Initialize the black figures
    board[7][0] = new Rook(7, 0, false);
    board[7][1] = new Knight(7, 1, false);
    board[7][2] = new Bishop(7, 2, false);
    board[7][3] = new King(7, 4, false);
    board[7][4] = new Queen(7, 3, false);
    board[7][5] = new Bishop(7, 5, false);
    board[7][6] = new Knight(7, 6, false);
    board[7][7] = new Rook(7, 7, false);

    // Initialize the black pawns
    for (int col = 0; col < 8; col++) {
        board[6][col] = new Pawn(6, col, false);
    }

    // Initialize the empty positions
    for (int row = 2; row < 6; row++) {
        for (int col = 0; col < 8; col++) {
            board[row][col] = nullptr;
        }
    }

    board[4][4] = new King(4, 4, true);

}

// N: Do we still need it?
//Board::Board() {
//    // Fill the chessboard with some initial values
//    for (int row = 0; row < 8; row++) {
//        for (int col = 0; col < 8; col++) {
//            auto* figure = new Figure('w', true);
//            board[row][col] = figure;
//            board[row][col] = nullptr;
//        }
//    }
//}

// Temporary function to print board. I have a bit changed it, so it prints a number of each row
void Board::print_board() {
    for (int row = 0; row < 8; row++) {
        std::cout << row << " ";
        for (int col = 0; col < 8; col++) {
            std::cout << board[row][col] << ((col == 7) ? "" : "_");
        }
        std::cout << std::endl;
    }
}

// Return Figure at the position or ptrnull
Figure* Board::cell_value(int x, int y){
    return board[x][y];
}

void Board::make_move(pos current, pos new_position) {
    if (is_white) {
        if (board[current.x][current.y] != nullptr){
//            if (board[new_position.x][new_position.y] == nullptr && board[current.x][current.y]->can_move) {
            if (board[new_position.x][new_position.y] == nullptr) {
                std::cout << "white move";
                // check if current figure can make moves
                board[new_position.x][new_position.y] = board[current.x][current.y];
                board[current.x][current.y] = nullptr;
            }
        is_white = false;
        }else{
            std::cout << "invalid move";
        }
    } else {
        if (board[current.x][current.y] != nullptr){
//            if (board[new_position.x][new_position.y] == nullptr && board[current.x][current.y]->can_move) {
            if (board[new_position.x][new_position.y] == nullptr) {
                std::cout << "black move";
                // check if current figure can make moves
                board[new_position.x][new_position.y] = board[current.x][current.y];
                board[current.x][current.y] = nullptr;
            }
            is_white = true;
        }else{
            std::cout << "invalid move";
        }
    }
}

