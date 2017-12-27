//
// Created by Rivka Schuss on 26/12/2017.
//

#include "GameCollection.h"
#include <iostream>
using namespace std;

GameCollection* GameCollection::instance = NULL;

GameCollection *GameCollection::getInstance() {
    if (instance == NULL) {
        instance = new GameCollection();
        return instance;
    }
    else {
        return instance;
    }
}

void GameCollection::add(GameID* game) {
    list->push_back(game);
}

vector<GameID*> *GameCollection::getList() {
    return this->list;
}



