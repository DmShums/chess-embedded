#ifndef CHESS_SAMPLE_DIAGONALS_H
#define CHESS_SAMPLE_DIAGONALS_H


#include "../../structures/pos.h"
#include "../../Board/Board.h"
#include "../Positions.h"

void check_diagonals(pos pos, bool is_white, Positions& possible_moves, Board& board);


#endif //CHESS_SAMPLE_DIAGONALS_H
