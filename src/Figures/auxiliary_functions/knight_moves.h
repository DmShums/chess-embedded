#ifndef CHESS_SAMPLE_STRAIGHT_LINES_H
#define CHESS_SAMPLE_STRAIGHT_LINES_H


#include "../../structures/pos.h"
#include "../../Board/Board.h"
#include "../Positions.h"

void check_knight_moves(pos pos, bool is_white, Positions& possible_moves, Board& board);


#endif //CHESS_SAMPLE_STRAIGHT_LINES_H
