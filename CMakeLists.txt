cmake_minimum_required(VERSION 3.8)
project(ReversiGame)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
include_directories(/Tests)

set(SOURCE_FILES
        src/Board.cpp
        include/Board.h
        src/Location.cpp
        include/Location.h
        src/Cell.cpp
        include/Cell.h
        include/Player.h
        src/AbstractPlayer.cpp
        include/AbstractPlayer.h
        src/ConsolePlayer.cpp
        include/ConsolePlayer.h
        src/Game.cpp
        include/Game.h
        src/AbstractGameLogic.cpp
        include/AbstractGameLogic.h
        src/DefaultGameLogic.cpp
        include/DefaultGameLogic.h
        include/GameLogic.h
        src/AIPlayer.cpp
        include/AIPlayer.h
        src/RemotePlayer.cpp
        include/RemotePlayer.h
        src/RemoteLogic.cpp
        include/RemoteLogic.h
        src/Server.cpp
        include/Server.h)
add_executable(ReversiGame ${SOURCE_FILES} src/main.cpp src/Client.cpp include/Client.h)

set(SOURCE_FILES_TEST
        Tests/test_main.cpp
        src/Board.cpp
        include/Board.h
        src/Location.cpp
        include/Location.h
        src/Cell.cpp
        include/Cell.h
        include/Player.h
        src/AbstractPlayer.cpp
        include/AbstractPlayer.h
        src/ConsolePlayer.cpp
        include/ConsolePlayer.h
        src/Game.cpp
        include/Game.h
        src/AbstractGameLogic.cpp
        include/AbstractGameLogic.h
        src/DefaultGameLogic.cpp
        include/DefaultGameLogic.h
        include/GameLogic.h
        src/AIPlayer.cpp
        include/AIPlayer.h
        src/RemotePlayer.cpp
        include/RemotePlayer.h
        src/RemoteLogic.cpp
        include/RemoteLogic.h
        src/Server.cpp
        include/Server.h
        Tests/test_logic.cpp
        Tests/test_board.cpp
        Tests/test_cell.cpp
        Tests/test_player.cpp
        Tests/BoardCreator.cpp
        Tests/BoardCreator.h)
add_executable(ReversiTest ${SOURCE_FILES_TEST} ${SOURCE_FILES})
target_link_libraries(ReversiTest gtest gtest_main)