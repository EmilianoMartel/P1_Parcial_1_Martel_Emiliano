#include <iostream>
#include "WarriorCreator.h"
#include "Game.h"

using namespace std;

int main()
{
    WarriorCreator creator = WarriorCreator();
    Game game = Game();

    creator.start();
    game.setWarriors(creator.getWarriors());

    game.start();

    cin.get();
}