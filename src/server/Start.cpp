//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Start.h"
#include <iostream>
#include <unistd.h>

using namespace std;

Start::Start(int clientSock, vector<GameID> &listOfGames) : clientSock(clientSock),
                                                                        listOfGames(listOfGames){

}

void Start::execute(vector<string> args) {
    char error[3] = "-1";
    for (int i = 0; i < listOfGames.size(); i++) {
        if (strcmp(listOfGames[i].getName().c_str(), args[0].c_str()) == 0) {
            int sent_bytes = write(clientSock, error, sizeof(error));
            if (sent_bytes < 0) {
                cout << "Error sending to client." << endl;
                return;
            }
            return;
        }
    }
    //create new game
    GameID game = GameID(args[0]);
    game.updateAvailability(onePlayer);
    game.setFirstSock(clientSock);
    listOfGames.push_back(game);
}


