#ifndef CHESS_SAMPLE_STRAIGHT_LINES_H
#define CHESS_SAMPLE_STRAIGHT_LINES_H


#include "pos.h"
#include "Board.h"
#include "Positions.h"

void check_straight_lines(pos pos, bool is_white, Positions &possible_moves, Board &board);


#endif //CHESS_SAMPLE_STRAIGHT_LINES_H
