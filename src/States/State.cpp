#include "State.h"
#include "Arduino.h"
#include "Highlight.h"

void State::enter() {
    is_fig_up = false;
    is_enemy_fig_up = false;
    init_fig_pos = pos{10, 10};
}

// main function, processes the move, returns what state should be next (if the move is changed or not)
bool State::process() {
    auto p = question_sensors();
    if (p.x == 10) {
        return is_white;
    }

    Serial.print(p.x);
    if (!is_fig_up) {
        is_fig_up = true;

        auto fig = board.cell_value(p.x, p.y); //! Save the figure
        fig->possible_moves(poses, board); //! Save possible moves

        // Poses now has POSSIBLE MOVES

        //! HIGHLIGHT THEM
        highlight::hint_on(poses, board);



        // The move continues
        return is_white;

    }
    else {
        if (init_fig_pos.x != 10) {

            if (p.x == init_fig_pos.x and p.y == init_fig_pos.y) {
                // The fig is put back

                // The move passes to other side
                return !is_white;
            }
            else if(board.cell_value(p.x, p.y) == nullptr) {
                // THE FIGURE GOT PUT HERE!!!!
                // NEED TO MOVE HERE IN BOARD AND FIGURES
            }
            else {
                // IDK SOMETHING BAD HAPPENED, maybe enemy fig picked up, need logic for this
            }
        }
    }


    return false;
}


// Question all Hall sensors and see if anything changed
// if something did change, wait to avoid bouncing (коли з 0 на 1 дуже часто міняєтья)
pos State::question_sensors() {
    for (int a = 0; a <= 7; ++a) {
        digitalWrite(S0, (a & 0b001));
        digitalWrite(S1, (a & 0b010));
        digitalWrite(S2, (a & 0b100));

        for (int i = I0; i < I0 + 7; ++i) {
            auto val = digitalRead(i);
            if((board.cell_value(a, i-I0) != nullptr and val == UP) or
               (board.cell_value(a, i-I0) == nullptr and val == DOWN)){

                // delay for debouncing
                delay(100);
                return pos{a, i - I0};
            }
        }
    }

    // if nothing changed
    return pos{10,10};
}

void State::figure_up(bool new_state) {
    is_fig_up = new_state;
}

bool State::get_bool_fig_up() {
    return is_fig_up;
}