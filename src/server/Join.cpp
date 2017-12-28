//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Join.h"
#include "GameID.h"
#include "GameManager.h"
#include <iostream>
#include <unistd.h>

using namespace std;


Join::Join(vector<GameID*> &gameList, vector<pthread_t> &threadList) :  gameList(gameList), threadList(threadList) {

}

void Join::execute(vector<string> args) {
    char second[2] = "2";
    char error[3] = "-2";
    int sockSecond;
    sscanf(args[1].c_str(), "%d", &sockSecond);
    for (int i = 0; i < gameList.size(); i++) {
        if (strcmp(args[0].c_str(), gameList.at(i)->getName().c_str()) == 0) {
            cout << "got here" << endl;
            if (gameList.at(i)->getAvailability() == onePlayer) {
                gameList.at(i)->setSecondSock(sockSecond);
                gameList.at(i)->updateAvailability(twoPlayers);
                //writing to the second client that hes the second player
                int sent_bytes2 = write(sockSecond, second, sizeof(second));
                int sockFirst = gameList.at(i)->getFirstSock();
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
                pthread_t gameRunner;
                int gameThread = pthread_create(&gameRunner, NULL, sendToGameManager, gameList.at(i));
                threadList.push_back(gameRunner);
                if (gameThread) {
                    cout << "Error: unable to create thread, " << gameThread << endl;
                    exit(-1);
                }
                return;
            }
            else if(gameList.at(i)->getAvailability() == twoPlayers) {
                int sent_bytes2 = write(sockSecond, error, sizeof(error));
                if (sent_bytes2 < 0) {
                    cout << "Error sending to client." << endl;
                    return;
                }
                return;
            } else{
                cout << "That game doesn't exist." << endl;
                return;
            }
        }
    }
}

void *Join::sendToGameManager(void* game) {
    GameID* gameID = (GameID*) game;
    GameManager* manager = new GameManager(gameID);
    manager->startGame();
    delete manager;
}


