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

/**
 * constructor.
 * @param gameList reference to the list of games.
 */
ListGames::ListGames(vector<GameID*> &gameList) :  gameList(gameList) {

}

/**
 * executes the list game command, prints the list of games.
 * @param args
 */
void ListGames::execute(vector<string> args) {
    int sock;
    sscanf(args[1].c_str(), "%d", &sock);
    string names;
    //changing the list of games to be in a printable format.
    for (int i = 0; i < gameList.size(); i++) {
        names += gameList.at(i)->getName();
        names += '\n';
    }
    char buffer[names.length()];
    strcpy(buffer, names.c_str());
    //writing the list to the client.
    int sentBytes = write(sock, buffer, sizeof(buffer));
    if (sentBytes < 0) {
        cout << "Error sending to client." << endl;
        return;
    }
}



