#include "Pawn.h"

Pawn::Pawn(int x, int y, bool is_white) : Figure(x, y, is_white) {}

void Pawn::possible_moves(Positions &possible_moves, Board &board) {
    possible_moves.reset_size();
    auto pos = get_position();
    // figure can stay at the same cell
    possible_moves.add_pos(get_position().x, get_position().y);

    // add all possible moves
    // the cell contains a figure (right-top)
    if (board.cell_value(pos.x + 1, pos.y + 1) != nullptr){
        // the figure has a different color
        if (board.cell_value(pos.x + 1, pos.y + 1)->is_white() != is_white()){
            // add a possible move
            possible_moves.add_pos(pos.x + 1, pos.y + 1);
        }
    }

    // the cell contains a figure (left-top)
    if (board.cell_value(pos.x - 1, pos.y + 1) != nullptr){
        // the figure has a different color
        if (board.cell_value(pos.x - 1, pos.y + 1)->is_white() != is_white()){
            // add a possible move
            possible_moves.add_pos(pos.x - 1, pos.y + 1);
        }
    }

    // the cell contains a figure (right-bottom)
    if (board.cell_value(pos.x + 1, pos.y - 1) != nullptr){
        // the figure has a different color
        if (board.cell_value(pos.x + 1, pos.y - 1)->is_white() == is_white()){
            // add a possible move
            possible_moves.add_pos(pos.x + 1, pos.y - 1);
        }
    }

    // the cell contains a figure (right-bottom)
    if (board.cell_value(pos.x - 1, pos.y - 1) != nullptr){
        // the figure has a different color
        if (board.cell_value(pos.x - 1, pos.y - 1)->is_white() == is_white()){
            // add a possible move
            possible_moves.add_pos(pos.x - 1, pos.y - 1);
        }
    }

    // the cell doesn't contain a figure (top)
    if (board.cell_value(pos.x, pos.y)->is_white() == is_white()) {
        if (board.cell_value(pos.x, pos.y + 1) == nullptr){
            possible_moves.add_pos(pos.x, pos.y + 1);
        }
    }

    // the cell doesn't contain a figure (bottom)
    if (board.cell_value(pos.x, pos.y)->is_white() != is_white()) {
        if (board.cell_value(pos.x, pos.y - 1) == nullptr){
            possible_moves.add_pos(pos.x, pos.y - 1);
        }
    }

}