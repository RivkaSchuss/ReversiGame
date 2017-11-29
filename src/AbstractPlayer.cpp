//
// Created by yarin on 03/11/17.
//

#include <iostream>
#include "../include/AbstractPlayer.h"
#include "../include/GameLogic.h"

using namespace std;

/**
 * Constructor.
 * @param type the type of the player.
 */
AbstractPlayer::AbstractPlayer(Type type) : type(type) {}

/**
 * Destructor.
 */
AbstractPlayer::~AbstractPlayer() {
}

