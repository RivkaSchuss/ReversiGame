cmake_minimum_required(VERSION 3.8)
project(assignment1)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h Location.cpp Location.h Cell.cpp Cell.h Player.h AbstractPlayer.cpp AbstractPlayer.h ConsolePlayer.cpp ConsolePlayer.h Game.cpp Game.h AbstractGameLogic.cpp AbstractGameLogic.h DefaultGameLogic.cpp DefaultGameLogic.h GameLogic.h)
add_executable(ReversiGame ${SOURCE_FILES})