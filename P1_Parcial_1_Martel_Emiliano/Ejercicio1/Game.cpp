#include "Game.h"

Game::Game() {
	index = 0;
	deadWarriors = 0;
}

void Game::start() {
	do
	{

	} while (deadWarriors <= warriors.size());
}

void Game::setWarriors(vector<Warrior> warriors) {
	this->warriors = warriors;
}