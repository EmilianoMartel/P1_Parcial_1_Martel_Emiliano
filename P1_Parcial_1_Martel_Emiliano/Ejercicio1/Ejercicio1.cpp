#include <iostream>
#include "Game.h"

using namespace std;

const char* TITLE = "Warriors Fight - Emiliano Martel";

int main()
{
    setTitle(TITLE);
    
    Game game = Game();
    game.start();

    cin.get();
}