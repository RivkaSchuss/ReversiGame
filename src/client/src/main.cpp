#include <iostream>
#include "../include/Game.h"

using namespace std;

/**
 * the main.
 * @param argc the number of arguments.
 * @param argv the arguments.
 * @return 0.
 */
int main(int argc, char* argv[]) {
    Game* game = new Game();
    game->runMenu();
    delete game;
    return 0;
}
