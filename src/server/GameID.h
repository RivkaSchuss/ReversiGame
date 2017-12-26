//
// Created by Rivka Schuss on 25/12/2017.
//

#ifndef REVERSIGAME_GAMEID_H
#define REVERSIGAME_GAMEID_H

#include <iostream>

using namespace std;

enum Available {noPlayers, onePlayer, twoPlayers};

class GameID {
public:
    GameID(string name);
    ~GameID();
    void updateAvailability(Available status);
    Available getAvailability();
    string getName();
    void setFirstSock(int firstSock);
    void setSecondSock(int secSock);
private:
    string name;
    Available status;
    int player1Sock;
    int player2Sock;
};


#endif //REVERSIGAME_GAMEID_H
