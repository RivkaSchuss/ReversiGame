//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Start.h"
#include "GameCollection.h"
#include <iostream>
#include <unistd.h>

using namespace std;

Start::Start(int clientSock) : clientSock(clientSock){

}

void Start::execute(vector<string> args) {
    vector<GameID> *list = GameCollection::getInstance()->getList();
    char error[3] = "-1";
    char first[2] = "1";
    for (int i = 0; i < list->size(); i++) {
        if (strcmp(list->at(i).getName().c_str(), args[0].c_str()) == 0) {
            int sent_bytes = write(clientSock, error, sizeof(error));
            if (sent_bytes < 0) {
                cout << "Error sending to client." << endl;
                return;
            }
            return;
        }
    }
    //create new game
    //writing to the first client
    int sent_bytes = write(clientSock, first, sizeof(first));
    if (sent_bytes < 0) {
        cout << "Error sending to client." << endl;
        return;
    }
    GameID game = GameID(args[0]);
    game.updateAvailability(onePlayer);
    game.setFirstSock(clientSock);
    GameCollection::getInstance()->add(game);
}


