#pragma once
#include "WarriorCreator.h"

using namespace std;

class Game {
private:
	vector<Warrior> warriors;
	int index;
	int deadWarriors;
public:
	Game();
	void start();
	void setWarriors(vector<Warrior> warriors);
};