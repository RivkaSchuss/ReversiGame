//
// Created by Rivka Schuss on 26/12/2017.
//

#ifndef REVERSIGAME_GAMECOLLECTION_H
#define REVERSIGAME_GAMECOLLECTION_H


#include <iostream>
#include <vector>
#include "GameID.h"

using namespace std;

class GameCollection
{
public:
    static GameCollection *getInstance();
    void add(GameID* game);
    vector<GameID*> *getList();
private:
    GameCollection() {};
    static GameCollection *instance;
    vector<GameID*> *list;
};

#endif //REVERSIGAME_GAMECOLLECTION_H
