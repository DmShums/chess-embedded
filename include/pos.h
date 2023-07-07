#ifndef CHESS_SAMPLE_POS_H
#define CHESS_SAMPLE_POS_H

// N: Save x and y
struct pos{
    int x;
    int y;
    friend bool operator==(pos first, pos second){
        return first.x == second.x and first.y == second.y;
    }
};

#endif //CHESS_SAMPLE_POS_H
