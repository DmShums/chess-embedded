#ifndef CHESS_SAMPLE_STATE_H
#define CHESS_SAMPLE_STATE_H

#include "Board.h"
#include "pos.h"


// ONE IS FIGURE STANDING
#define DOWN 1
#define UP 0

class Board;

class State {
private:
    bool is_white;
    bool is_fig_up;
    bool is_enemy_fig_up;
    Board &board;
    Positions &poses;

    pos init_fig_pos;

public:
    State(Board &board, Positions &pos, bool white): board{board}, poses{pos} {
        is_white = white;
        is_fig_up = false;
        is_enemy_fig_up = false;
    }

    ~State() = default;


    void enter();

    void exit();

    void figure_up(bool new_state);

    bool process();

    bool get_bool_fig_up();

    pos question_sensors();
};

#endif //CHESS_SAMPLE_STATE_H
