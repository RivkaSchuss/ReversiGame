//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Start.h"
#include <iostream>
#include <unistd.h>

pthread_mutex_t gamesMutex;

using namespace std;

Start::Start(vector<GameID*> &gameList) : gameList(gameList) {

}

void Start::execute(vector<string> args) {
    char error[3] = "-1";
    char first[2] = "1";
    int sock;
    sscanf(args[1].c_str(), "%d", &sock);
    pthread_mutex_lock(&gamesMutex);
    for (int i = 0; i < gameList.size(); i++) {
        //if the game already exists, send an error message
        if (strcmp(gameList.at(i)->getName().c_str(), args[0].c_str()) == 0) {
            int sent_bytes = write(sock, error, sizeof(error));
            if (sent_bytes < 0) {
                cout << "Error sending to client." << endl;
                return;
            }
            return;
        }
    }
    //writing to the first client that he is player 1
    int sent_bytes = write(sock, first, sizeof(first));
    if (sent_bytes < 0) {
        cout << "Error sending to client." << endl;
        return;
    }
    GameID* game = new GameID(args[0]);
    pthread_mutex_unlock(&gamesMutex);
    game->updateAvailability(onePlayer);
    game->setFirstSock(sock);
    gameList.push_back(game);
}


