#include "Figure.h"

//! Base class for figures
Figure::Figure(int x, int y, bool is_white){
    color = is_white;
    position = pos{x, y};
}

//! Return true if it is white
bool Figure::is_white(){
    return color;
}

//! Return the position
pos Figure::get_position(){
    return position;
}

//! Set new position to the figure
void Figure::new_position(int x, int y){
    //! Will it even work with private variable in c/c++?
    position = pos{x, y};
}
