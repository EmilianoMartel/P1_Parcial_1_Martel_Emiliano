#pragma once
#include "WarriorCreator.h"
#include "AwesomeLibrary.h"
#include <iostream>
#include <conio.h>

using namespace std;

class Game {
private:
	WarriorCreator creator;
	vector<Warrior> warriors;
	vector<Warrior> canSelectedWarriors;
	int index;
	int deadWarriors;

	int xInit = 1;
	int yInit = 1;
	int xFinal = 100;
	int yFinal = 25;
	char* titleArt;

	void menu();
	void gameLoop();
	void instructions();
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