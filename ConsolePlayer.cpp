//
// Created by yarin on 03/11/17.
//

#include <iostream>
#include "ConsolePlayer.h"

/**
 * Constructor.
 * @param type the type of the player.
 */

ConsolePlayer::ConsolePlayer(Type type) : AbstractPlayer(type), type(type){
}

/**
 * Destructor.
 */

ConsolePlayer::~ConsolePlayer() {
    delete this;
}
