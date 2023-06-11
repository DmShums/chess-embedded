#ifndef KNIGHT_MOVES_H
#define KNIGHT_MOVES_H


#include "../../structures/pos.h"
#include "../../Board/Board.h"
#include "../Positions.h"

void check_knight_moves(pos pos, bool is_white, Positions& possible_moves, Board& board);


#endif //KNIGHT_MOVES_H
