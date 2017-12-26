//
// Created by Rivka Schuss on 25/12/2017.
//

#include "Play.h"
#include <iostream>
#include <unistd.h>

using namespace std;


Play::Play(int clientSock) : clientSock(clientSock) {

}

void Play::execute(vector<string> args) {
    int secondSocket;
    sscanf(args[0].c_str(), "%d", &secondSocket);
    int length = args[1].length() + args[2].length();
    char move[length + 1];
    strcpy(move, args[1].c_str());
    move[args[1].length() + 1] = ' ';
    strcpy(move, args[2].c_str());
    int sent_bytes = write(secondSocket, move, sizeof(move));
    if (sent_bytes < 0) {
        cout << "Error sending to client." << endl;
        return;
    }
}


