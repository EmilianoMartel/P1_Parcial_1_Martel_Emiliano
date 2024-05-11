#include "Game.h"

Game::Game() {
	index = 0;
	deadWarriors = 0;
}

void Game::start() {
	do
	{
		printTurn(warriors[index]);

		index++;
	} while (deadWarriors <= warriors.size());
}

void Game::setWarriors(vector<Warrior> warriors) {
	this->warriors = warriors;
}

void Game::printTurn(Warrior warrior) {
	Warrior attackedWarrior;
	AttackType attackType;
	bool isCritic = false;

	cout << "It´s " << warrior.getName() << " turn." << endl;

	attackedWarrior = setSelectedWarriors(warrior);
	attackType = attackTypeSelector();

	cout << warrior.getName() << " attack " << attackedWarrior.getName() << endl;

	warrior.attack(attackedWarrior,attackType,&isCritic);

	if (isCritic) {
		cout << "IS CRITIC." << endl;
	}
}

Warrior Game::setSelectedWarriors(Warrior warrior) {
	canSelectedWarriors.clear();
	int num = 0;
	int indexList = 0;

	for (size_t i = 0; i < warriors.size(); i++)
	{
		if (warriors[i].getWarriorID() == warrior.getWarriorID()) {
			continue;
		}

		indexList++;
		cout << indexList << " - " << warriors[i].getName() << " life: " << warriors[i].getLife() << endl;
	}

	do
	{
		num = intInputLoop("How do you want to attack? (Select number)");
	} while (num < 1 || num > warriors.size() - 1);

	if (num < warrior.getWarriorID()) {
		num--;
	}

	return warriors[num];
}

AttackType Game::attackTypeSelector() {
	int input = 0;
	cout << "What attack type do you want to do?" << endl;
	cout << "1 - Fast" << endl;
	cout << "2 - Normal" << endl;
	cout << "3 - Charged" << endl;
	do
	{
		input = intInputLoop("Insert a number: ");
	} while (input < 1 || input > 3);

	switch (input)
	{
	case 1:
		return Fast;
		break;
	case 2:
		return Normal;
		break;
	case 3:
		return Charged;
		break;
	default:
		return Fast;
		break;
	}
}