#ifndef UNTITLED2_STATESMANAGER_HPP
#define UNTITLED2_STATESMANAGER_HPP

#include "State.h"
#include "Board.h"
#include "Positions.h"

class StatesManager{
private:
    State* white_state;
    State* black_state;
    Board* board;
    Positions* poses;

    State* current_state;

    bool curr_state;
    bool next_state;

public:
    StatesManager(State* white, State* black, Board* board, Positions* poses):
        white_state{white},
        black_state{black},
        board{board},
        poses{poses}{
        current_state = white_state;
        curr_state = true;
        next_state = true;
    };

    void process();

};

#endif //UNTITLED2_STATESMANAGER_HPP
