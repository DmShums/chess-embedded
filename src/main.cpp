//#include <vector>   // for std::array
//#include "Board.h"

#include "Arduino.h"
#include "T/t.h"
void setup() {
    Serial.begin(9600);


//    Board board_chess = Board();
//    board_chess.print_board();
}

void loop(){
    TTT a{};
    Serial.print(a.add());    
}