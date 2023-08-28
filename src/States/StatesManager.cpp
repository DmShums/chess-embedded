#include "StatesManager.hpp"

void StatesManager::process() {
    next_state = current_state->process();

    // get kings' position
    pos white_king = board->find_kings_position(true);
    pos black_king = board->find_kings_position(false);

    // if the move didnt pass to other player
    if(curr_state == next_state) return;

    // if the move did pass to other player
    curr_state = next_state;
    if(next_state){
        current_state = white_state;
        check(current_state, white_king, black_king);
    }
    else{
        current_state = black_state;
        check(current_state, white_king, black_king);
    }
    current_state->enter();

}

bool StatesManager::check(State* state, pos white_king, pos black_king) {
    // add coloring
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            auto current_cell = board->cell_value(row, col);
            if (current_cell != nullptr) {
                bool cell_color = current_cell->is_white();
                bool same_color = (cell_color and state == white_state) or (!cell_color and state == black_state);
                current_cell->possible_moves(*poses, *board);
                for (int i=0; i<poses->get_size(); ++i){
                    auto pos = poses->get_pos(i);
                    if (cell_color and state != white_state) {
                        if (black_king == pos) {
                            return true;
                        }
                    }
                    if (!cell_color and state == black_state) {
                        if (white_king == pos) {
                            return true;
                        }
                    }
                }

            }
        }
    }
    return false;

}