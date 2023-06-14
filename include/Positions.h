#ifndef CHESS_SAMPLE_POSITIONS_H
#define CHESS_SAMPLE_POSITIONS_H


#include "pos.h"
//! So that malloc works
#include <stdlib.h>

// N: Save N number of pos
class Positions{
private:
    pos* ppositions;
    //! Current number of pos
    int size;
    //! Maximum number of pos
    int capacity;
public:
    Positions(int init_capacity){
        capacity = init_capacity;
        size = 0;
        //! Array of pos`s with maximum size of capacity
        ppositions = static_cast<pos*> (malloc(sizeof(pos)*capacity));
    }

    ~Positions(){
        free(ppositions);
    }

    void add_pos(int x, int y){
        ppositions[size] = pos{x, y};
        size++;
    }

    pos get_pos(int idx){
        return ppositions[idx];
    }

    int get_size(){
        return size;
    }

    void reset_size(){
        size = 0;
    }
};


#endif //CHESS_SAMPLE_POSITIONS_H
