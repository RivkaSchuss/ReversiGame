cmake_minimum_required(VERSION 3.8)
project(ReversiGame)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pthread")
add_subdirectory(src/client/lib/googletest)
include_directories(src/client/lib/googletest/googletest/include)
include_directories(src/client/lib/googletest/googlemock/include)
include_directories(src/client/Tests)

set(SOURCE_FILES
        src/client/src/Board.cpp
        src/client/include/Board.h
        src/client/src/Location.cpp
        src/client/include/Location.h
        src/client/src/Cell.cpp
        src/client/include/Cell.h
        src/client/include/Player.h
        src/client/src/AbstractPlayer.cpp
        src/client/include/AbstractPlayer.h
        src/client/src/ConsolePlayer.cpp
        src/client/include/ConsolePlayer.h
        src/client/src/Game.cpp
        src/client/include/Game.h
        src/client/src/AbstractGameLogic.cpp
        src/client/include/AbstractGameLogic.h
        src/client/src/DefaultGameLogic.cpp
        src/client/include/DefaultGameLogic.h
        src/client/include/GameLogic.h
        src/client/src/AIPlayer.cpp
        src/client/include/AIPlayer.h
        src/client/src/RemotePlayer.cpp
        src/client/include/RemotePlayer.h
        src/client/src/RemoteLogic.cpp
        src/client/include/RemoteLogic.h
        src/client/include/Client.h
        src/client/src/Client.cpp
        )
add_executable(ReversiGame ${SOURCE_FILES} src/client/src/main.cpp)

set(SERVER_FILES
        src/server/main.cpp
        src/server/Server.cpp
        src/server/Server.h
        src/server/Command.h
        src/server/Play.cpp
        src/server/Play.h
        src/server/Start.cpp
        src/server/Start.h
        src/server/Join.cpp
        src/server/Join.h
        src/server/ListGames.cpp
        src/server/ListGames.h
        src/server/Close.cpp
        src/server/Close.h src/server/CommandsManager.cpp src/server/CommandsManager.h src/server/GameID.cpp src/server/GameID.h)
add_executable(RunServer ${SERVER_FILES} src/server/main.cpp)

set(SOURCE_FILES_TEST
        src/client/Tests/test_main.cpp
        src/client/src/Board.cpp
        src/client/include/Board.h
        src/client/src/Location.cpp
        src/client/include/Location.h
        src/client/src/Cell.cpp
        src/client/include/Cell.h
        src/client/include/Player.h
        src/client/src/AbstractPlayer.cpp
        src/client/include/AbstractPlayer.h
        src/client/src/ConsolePlayer.cpp
        src/client/include/ConsolePlayer.h
        src/client/src/Game.cpp
        src/client/include/Game.h
        src/client/src/AbstractGameLogic.cpp
        src/client/include/AbstractGameLogic.h
        src/client/src/DefaultGameLogic.cpp
        src/client/include/DefaultGameLogic.h
        src/client/include/GameLogic.h
        src/client/src/AIPlayer.cpp
        src/client/include/AIPlayer.h
        src/client/src/RemotePlayer.cpp
        src/client/include/RemotePlayer.h
        src/client/src/RemoteLogic.cpp
        src/client/include/RemoteLogic.h
        src/client/include/Client.h
        src/client/src/Client.cpp
        src/client/Tests/test_logic.cpp
        src/client/Tests/test_board.cpp
        src/client/Tests/test_cell.cpp
        src/client/Tests/test_player.cpp
        src/client/Tests/BoardCreator.cpp
        src/client/Tests/BoardCreator.h)

add_executable(ReversiTest ${SOURCE_FILES_TEST} ${SOURCE_FILES})
target_link_libraries(ReversiTest gtest gtest_main)