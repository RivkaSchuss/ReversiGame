//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Join.h"
#include "GameID.h"
#include "GameCollection.h"
#include <iostream>
#include <unistd.h>

using namespace std;


Join::Join(vector<GameID*> &gameList) :  gameList(gameList) {

}

void Join::execute(vector<string> args) {
    //vector<GameID*> *list = GameCollection::getInstance()->getList();
    char second[2] = "2";
    int sock;
    sscanf(args[1].c_str(), "%d", &sock);
    for (int i = 0; i < gameList.size(); i++) {
        if (strcmp(args[0].c_str(), gameList.at(i)->getName().c_str()) == 0) {
            if (gameList.at(i)->getAvailability() == onePlayer) {
                gameList.at(i)->setSecondSock(sock);
                gameList.at(i)->updateAvailability(twoPlayers);
                //writing to the second client that hes the second player
                int sent_bytes2 = write(sock, second, sizeof(second));
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
                return;
            } else {
                //create a new game
            }
        }
    }

}


