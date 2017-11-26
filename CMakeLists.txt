cmake_minimum_required(VERSION 3.8)
project(ReversiGame)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/include)
include_directories(lib/googletest/googlemock/include)
include_directories(/Tests)

set(SOURCE_FILES main.cpp Board.cpp Board.h Location.cpp Location.h Cell.cpp Cell.h Player.h AbstractPlayer.cpp AbstractPlayer.h ConsolePlayer.cpp ConsolePlayer.h Game.cpp Game.h AbstractGameLogic.cpp AbstractGameLogic.h DefaultGameLogic.cpp DefaultGameLogic.h GameLogic.h AIPlayer.cpp AIPlayer.h)
add_executable(ReversiGame ${SOURCE_FILES})
target_link_libraries(ReversiGame gtest gtest_main)

set(SOURCE_FILES2 Tests/test_main.cpp Board.cpp Board.h Location.cpp Location.h Cell.cpp Cell.h Player.h AbstractPlayer.cpp AbstractPlayer.h ConsolePlayer.cpp ConsolePlayer.h Game.cpp Game.h AbstractGameLogic.cpp AbstractGameLogic.h DefaultGameLogic.cpp DefaultGameLogic.h GameLogic.h AIPlayer.cpp AIPlayer.h)
add_executable(test_main.cpp ${SOURCE_FILES2})
target_link_libraries(ReversiGame gtest gtest_main)