//
// Created by Rivka Schuss on 25/12/2017.
//

#include "ListGames.h"
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


using namespace std;


ListGames::ListGames(vector<GameID*> &gameList) :  gameList(gameList) {

}

void ListGames::execute(vector<string> args) {
    int sock;
    sscanf(args[1].c_str(), "%d", &sock);
    string names;
    for (int i = 0; i < gameList.size(); i++) {
        names += gameList.at(i)->getName();
        names += '\n';
    }
    char buffer[names.length()];
    strcpy(buffer, names.c_str());
    int sentBytes = write(sock, buffer, sizeof(buffer));
    if (sentBytes < 0) {
        cout << "Error sending to client." << endl;
        return;
    }
}



