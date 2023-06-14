#ifndef CHESS_SAMPLE_KING_POSSIBLE_MOVE_H
#define CHESS_SAMPLE_KING_POSSIBLE_MOVE_H


#include "pos.h"
#include "Board.h"
#include "Positions.h"

//! Return true if the cell is a possible move for the King
bool is_possible_move(pos position, bool is_white, Positions &enemy_positions, Board &board);


#endif //CHESS_SAMPLE_KING_POSSIBLE_MOVE_H
