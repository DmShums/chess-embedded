#include "State.h"
#include "Arduino.h"
#include "Highlight.h"

void State::enter() {
    is_fig_up = false;
    is_enemy_fig_up = false;
    init_fig_pos = pos{10, 10};
    init_enemy_fig_pos = pos{10, 10};
    error = false;
}

// main function, processes the move, returns what state should be next (if the move is changed or not)
bool State::process() {
    auto p = question_sensors();

    if (p.x == 10) return is_white;

    auto active_fig = board.cell_value(p.x, p.y);

    Serial.print(p.x, p.y);
    Serial.print('\n');

    // Handle errors first
    if(error and p == init_enemy_fig_pos){
        highlight::reset();
        highlight::show();
        is_enemy_fig_up = false;
        init_enemy_fig_pos = pos{10, 10};
        return is_white;
    }

    // The turn started, right player lifted the figure!
    if(!is_fig_up and active_fig != nullptr and active_fig->is_white() == is_white){
        is_fig_up = true;
        init_fig_pos = p;
        board.lift_figure(p);
        active_fig->possible_moves(poses, board); //! Save possible moves
        highlight::hint_on(poses, board);
        highlight::show();

        return is_white;
    }
    // IF the wrong player lifted the figure!!!
    else if(!is_fig_up and active_fig != nullptr and active_fig->is_white() != is_white){
        init_enemy_fig_pos = p;
        highlight::turn_all_red();
        highlight::show();
        error = true;
        return is_white;
    }

    // Our figure is put back down!!
    if(is_fig_up and active_fig != nullptr and active_fig->is_white() == is_white and p == init_fig_pos){
        highlight::reset();
        highlight::show();

        board.lower_figure(p);
        init_fig_pos = pos{10, 10};
        is_fig_up = false;
        return is_white;
    }

    // The white figure is moved to the new position
    if(is_fig_up and active_fig == nullptr){
        highlight::reset();
        highlight::show();

        board.lower_figure(p);
        return !is_white;
    }

    // Our figure is up and we lifted enemy figure
    if(is_fig_up and !is_enemy_fig_up and active_fig != nullptr and active_fig->is_white() != is_white){
        init_enemy_fig_pos = p;
        is_enemy_fig_up = true;
        board.delete_figure(p);
        return is_white;
    }

    // Our figure is put down where enemy fig was
    if(is_fig_up and is_enemy_fig_up and p == init_enemy_fig_pos){
        board.lower_figure(p);
        highlight::reset();
        highlight::show();

        return !is_white;
    }

    // shuma's code
    // Our figure is put down were own fig was
    if (is_fig_up and active_fig != nullptr and active_fig->is_white() == is_white and p == init_fig_pos) {
        if (board.cell_value(p.x, p.y) != nullptr && board.cell_value(p.x, p.y)->is_white() == is_white) {
            // Attempt to capture own piece
            highlight::reset();
            // highlight::highlight_cell(p, Color::Purple); // Highlight the attempted destination cell in purple
            highlight::show();

            // Reset the state
            board.lower_figure(p);
            init_fig_pos = pos{10, 10};
            is_fig_up = false;
            return is_white;
        } else {
        // Valid move: Put the figure back down
            highlight::reset();
            highlight::show();

            board.lower_figure(p);
            init_fig_pos = pos{10, 10};
            is_fig_up = false;
            return is_white;
        }
    }
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