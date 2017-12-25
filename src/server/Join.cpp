//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Join.h"
#include "GameID.h"
#include <iostream>

using namespace std;


Join::Join(int clientSock, vector<GameID> &gameList) : clientSock(clientSock),
                                                          gameList(gameList){

}

void Join::execute(vector<string> args) {
    for (int i = 0; i < gameList.size(); i++) {
        if (strcmp(args[0].c_str(), gameList[i].getName().c_str()) == 0) {
            if (gameList[i].getAvailability() == onePlayer) {
                //join
                return;
            } else {
                //create a new game
            }
        }
    }

}


