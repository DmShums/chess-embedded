#ifndef TEST_INO_FIGURE_H
#define TEST_INO_FIGURE_H


#include "Positions.h"
#include "pos.h"
#include "Board.h"

//! Why the code does not work without next line?
class Board;

//! Base class for figures
class Figure{
private:
    pos position;
    bool color; //! True if color is white

public:
    //! Constructor
    Figure(int x, int y, bool figure_color);
    //! Return true if it is white
    bool is_white();
    //! Return the position
    pos get_position();
    //! Set new position to the figure
    void new_position(int x, int y);
    //! Return ID of a figure
    /*!
     * King - 1
     * Queen - 2
     * Bishop - 3
     * Knight - 4
     * Rook - 5
     * Pawn - 6
     */
    virtual int figure_id() = 0;
    //! Virtual to call this method on the corresponding figure
    //! 0 to not implement here
    virtual void possible_moves(Positions& possible_moves, Board& board) = 0;

};


#endif //TEST_INO_FIGURE_H
