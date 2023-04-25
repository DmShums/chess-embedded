//
// Created by Shuma on 25.04.2023.
//

#include "Board.h"

Board::Board() {
    // Fill the chessboard with some initial values
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            board[row][col] = col;
        }
    }
}


void Board::print_board() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
//            Serial.print(board[row][col]);
        }
    }
}
