#pragma once
#include "WarriorCreator.h"

using namespace std;

class Game {
private:
	vector<Warrior> warriors;
	vector<Warrior> canSelectedWarriors;
	int index;
	int deadWarriors;

	bool checkWarriorLive();
	void gameOverLogic();
	Warrior setSelectedWarriors(Warrior warrior);
	void printTurn(Warrior warrior);
	AttackType attackTypeSelector();
public:
	Game();
	void start();
	void setWarriors(vector<Warrior> warriors);
};