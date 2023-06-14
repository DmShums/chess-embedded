cmake_minimum_required(VERSION 3.23)
project(chess_sample)

set(CMAKE_CXX_STANDARD 17)

#add_executable(chess_sample main.cpp)
add_executable(chess_sample main.cpp
        src/Board/Board.cpp
        src/Board/Board.h
        src/Figures/Bishop/Bishop.cpp
        src/Figures/Bishop/Bishop.h
        src/Figures/King/King.cpp
        src/Figures/King/King.h
        src/Figures/Knight/Knight.cpp
        src/Figures/Knight/Knight.h
        src/Figures/Pawn/Pawn.cpp
        src/Figures/Pawn/Pawn.h
        src/Figures/Queen/Queen.cpp
        src/Figures/Queen/Queen.h
        src/Figures/Rook/Rook.cpp
        src/Figures/Rook/Rook.h
        src/Figures/Figure/Figure.cpp
        src/Figures/Figure/Figure.h
        src/structures/pos.h
        src/Figures/auxiliary_functions/diagonals.cpp
        src/Figures/auxiliary_functions/diagonals.h
        src/Figures/auxiliary_functions/straight_lines.cpp
        src/Figures/auxiliary_functions/straight_lines.h
        src/Figures/auxiliary_functions/knight_moves.cpp
        src/Figures/auxiliary_functions/knight_moves.h 
        src/Figures/auxiliary_functions/king_possible_move.cpp 
        src/Figures/auxiliary_functions/king_possible_move.h)

target_include_directories(
        chess_sample
        PUBLIC
        src/Figures/Bishop/
        src/Figures/Figure/
        src/Figures/King/
        src/Figures/Knight/
        src/Figures/Pawn/
        src/Figures/Queen/
        src/Figures/Rook/
        src/Figures/auxiliary_functions/
        src/Board/
)
