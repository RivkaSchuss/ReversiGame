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
add_executable(client ${SOURCE_FILES} src/client/src/main.cpp)

set(SERVER_FILES
        src/server/src/main.cpp
        src/server/src/Server.cpp
        src/server/include/Server.h
        src/server/include/Command.h
        src/server/src/Start.cpp
        src/server/include/Start.h
        src/server/src/Join.cpp
        src/server/include/Join.h
        src/server/src/ListGames.cpp
        src/server/include/ListGames.h
        src/server/src/CommandsManager.cpp
        src/server/include/CommandsManager.h
        src/server/src/GameID.cpp
        src/server/include/GameID.h
        src/server/src/GameManager.cpp
        src/server/include/GameManager.h
        src/server/src/Handler.cpp
        src/server/include/Handler.h
        src/server/src/ServerListener.cpp
        src/server/include/ServerListener.h src/server/src/ThreadPool.cpp src/server/src/ThreadPool.h src/server/include/Task.h)
add_executable(server ${SERVER_FILES} src/server/src/main.cpp)

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