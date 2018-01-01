//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Join.h"

/**
 * constructor.
 * @param gameList reference to the list of games.
 * @param threadList reference to the list of threads.
 */
Join::Join(vector<GameID*> &gameList, vector<pthread_t> &threadList) :  gameList(gameList), threadList(threadList) {

}

/**
 * executes the join command, joins an existing game.
 * @param args
 */
void Join::execute(vector<string> args) {
    char second[2] = "2";
    char error1[3] = "-2";
    char error2[3] = "-3";
    int sockSecond;
    sscanf(args[1].c_str(), "%d", &sockSecond);
    //going over the list of games
    for (int i = 0; i < gameList.size(); i++) {
        //if we've found the name received as an argument:
        if (strcmp(args[0].c_str(), gameList.at(i)->getName().c_str()) == 0) {
            //and it has an available spot, we'll join it.
            if (gameList.at(i)->getAvailability() == onePlayer) {
                gameList.at(i)->setSecondSock(sockSecond);
                gameList.at(i)->updateAvailability(twoPlayers);
                //writing to the second client that hes the second player
                int sent_bytes2 = write(sockSecond, second, sizeof(second));
                int sockFirst = gameList.at(i)->getFirstSock();
                //writing to the first player that the second player has joined
                int sent_p1Bytes = write(sockFirst, second, sizeof(second));
                if (sent_p1Bytes < 0) {
                    cout << "Error sending to client." << endl;
                    return;
                }
                if (sent_bytes2 < 0) {
                    cout << "Error sending to client." << endl;
                    return;
                }
                cout << "Client 2 connected." << endl;
                //creating a new thread to run the game.
                pthread_t gameRunner;
                threadList.push_back(gameRunner);
                int gameThread = pthread_create(&gameRunner, NULL, sendToGameManager, gameList.at(i));
                if (gameThread) {
                    cout << "Error: unable to create thread, " << gameThread << endl;
                    exit(-1);
                }
                return;
            }
                //if the game was full, send an error to the client
            else if(gameList.at(i)->getAvailability() == twoPlayers) {
                int sent_bytes2 = write(sockSecond, error1, sizeof(error1));
                if (sent_bytes2 < 0) {
                    cout << "Error sending to client." << endl;
                    return;
                }
                return;
            }
        }
    }
    //if the game was full, send an error to the client.
    int sent_bytes2 = write(sockSecond, error2, sizeof(error2));
    if (sent_bytes2 < 0) {
        cout << "Error sending to client." << endl;
        return;
    }
    return;
}

void *Join::sendToGameManager(void* game) {
    //casts the arguments to be a gameId, and creates a game manager for the game.
    GameID* gameID = (GameID*) game;
    GameManager* manager = new GameManager(gameID);
    //starts the game.
    manager->startGame();
    delete manager;
}


