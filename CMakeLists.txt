cmake_minimum_required(VERSION 3.23)
project(chess_sample)

set(CMAKE_CXX_STANDARD 17)

#add_executable(chess_sample main.cpp)
add_executable(chess_sample src/main.cpp
        src/Board/Board.cpp
        src/Figures/Bishop/Bishop.cpp
        src/Figures/King/King.cpp
        src/Figures/Knight/Knight.cpp
        src/Figures/Pawn/Pawn.cpp
        src/Figures/Queen/Queen.cpp
        src/Figures/Rook/Rook.cpp
        src/Figures/Figure/Figure.cpp
        src/Figures/auxiliary_functions/diagonals.cpp
        src/Figures/auxiliary_functions/straight_lines.cpp
        src/Figures/auxiliary_functions/knight_moves.cpp
        src/Figures/auxiliary_functions/king_possible_move.cpp)


target_include_directories(
        chess_sample
        PUBLIC
        include
)
