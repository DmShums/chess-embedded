#include "StatesManager.hpp"

void StatesManager::process() {
    next_state = current_state->process();

    // if the move didnt pass to other player
    if(curr_state == next_state) return;

    // if the move did pass to other player
    curr_state = next_state;
    if(next_state){
        current_state = white_state;
    }
    else{
        current_state = black_state;
    }
    current_state->enter();

}