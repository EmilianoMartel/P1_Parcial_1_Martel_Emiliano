#pragma once
#include "WarriorCreator.h"
#include "AwesomeLibrary.h"

using namespace std;

class Game {
private:
	WarriorCreator creator;
	vector<Warrior> warriors;
	vector<Warrior> canSelectedWarriors;
	int index;
	int deadWarriors;

	void menu();
	void gameLoop();
	void typeGameSelection();
	void standarGame();
	void customGame();
	void gameOverLogic();
	Warrior* setSelectedWarriors(Warrior warrior);
	void printTurn(Warrior warrior);
	AttackType attackTypeSelector();
public:
	Game();
	void start();
	void setWarriors(vector<Warrior> warriors);
};