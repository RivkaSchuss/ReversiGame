//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Join.h"
#include "GameID.h"
#include "GameCollection.h"
#include <iostream>
#include <unistd.h>

using namespace std;


Join::Join(int clientSock) : clientSock(clientSock) {

}

void Join::execute(vector<string> args) {
    vector<GameID> *list = GameCollection::getInstance()->getList();
    char second[2] = "2";
    for (int i = 0; i < list->size(); i++) {
        if (strcmp(args[0].c_str(), list->at(i).getName().c_str()) == 0) {
            if (list->at(i).getAvailability() == onePlayer) {
                list->at(i).setSecondSock(clientSock);
                list->at(i).updateAvailability(twoPlayers);
                //writing to the second client that hes the second player
                int sent_bytes2 = write(clientSock, second, sizeof(second));
                if (sent_bytes2 < 0) {
                    cout << "Error sending to client." << endl;
                    return;
                }
                cout << "Client 2 connected." << endl;
                return;
            } else {
                //create a new game
            }
        }
    }

}


