#include <iostream>

#include "src/Board/Board.h"
#include "src/Figures/Positions.h"

int main() {
    Board b = Board();
//    b.print_board();

     //! Test possible moves
    Figure* lnk = b.cell_value(4, 4);

    std::cout << "cell value " << lnk << std::endl;
    std::cout << "is fig white: " << lnk->is_white() << std::endl;

    Positions bishop_pm = Positions(64); // it will be in setup
    lnk->possible_moves(bishop_pm, b);

    std::cout << "Len of possible moves is " << bishop_pm.get_size() << std::endl;
    int bor[8][8];
    for (int row=0; row < 8; row++){
        for (int col=0; col < 8; col++){
            bor[row][col] = 0;
        }
    }

    for (int i = 0; i < bishop_pm.get_size(); i++){
        bor[bishop_pm.get_pos(i).x][bishop_pm.get_pos(i).y] = 1;
//        std::cout << "i = " << i << " x " << bishop_pm.get_pos(i).x << " y " << bishop_pm.get_pos(i).y << std::endl;
    }

    std::cout << "Test board" << std::endl;
    for (int row = 0; row < 8; row++){
        for (int col = 0; col < 8; col++){
            if (bor[row][col] == 1){
                std::cout << "_";
            } else {
                std::cout << col;
            }
            std::cout<<" ";
        }
        std::cout << " " << row << " " << std::endl;
    }

    return 0;
}
