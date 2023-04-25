//
// Created by Shuma on 25.04.2023.
//

#ifndef TEST_INO_BOARD_H
#define TEST_INO_BOARD_H


class Board{
private:
    int board[8][8];

public:
    // Print the chessboard to the console
    void print_board();

    Board();
    ~Board() = default;
};



#endif //TEST_INO_BOARD_H
