cmake_minimum_required(VERSION 3.8)
project(ReversiGame)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
include_directories(/Tests)

set(SOURCE_FILES Board.cpp Board.h Location.cpp Location.h Cell.cpp Cell.h Player.h AbstractPlayer.cpp
        AbstractPlayer.h ConsolePlayer.cpp ConsolePlayer.h Game.cpp Game.h AbstractGameLogic.cpp AbstractGameLogic.h
        DefaultGameLogic.cpp DefaultGameLogic.h GameLogic.h AIPlayer.cpp AIPlayer.h)
add_executable(ReversiGame ${SOURCE_FILES} main.cpp)

set(SOURCE_FILES_TEST Tests/test_main.cpp Board.cpp Board.h Location.cpp Location.h Cell.cpp Cell.h Player.h
        AbstractPlayer.cpp AbstractPlayer.h ConsolePlayer.cpp ConsolePlayer.h Game.cpp Game.h AbstractGameLogic.cpp
        AbstractGameLogic.h DefaultGameLogic.cpp DefaultGameLogic.h GameLogic.h AIPlayer.cpp AIPlayer.h Tests/test_logic.cpp Tests/test_board.cpp Tests/test_cell.cpp Tests/test_player.cpp Tests/BoardCreator.cpp Tests/BoardCreator.h)
add_executable(ReversiTest ${SOURCE_FILES_TEST} ${SOURCE_FILES})
target_link_libraries(ReversiTest gtest gtest_main)