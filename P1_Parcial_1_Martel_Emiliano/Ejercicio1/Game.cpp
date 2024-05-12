#include "Game.h"

Game::Game() {
	creator = WarriorCreator();
	index = -1;
	deadWarriors = 0;
}

void Game::start() {
	menu();
}

void Game::menu() {
	int input;
	bool exit = false;
	do
	{
		system("cls");
		cout << "Warriors Fight." << endl;
		cout << "1 - Play" << endl;
		cout << "2 - Instructions" << endl;
		cout << "3 - Exit" << endl;
		input = intInputLoop("Select a option: ");
		switch (input)
		{
		case 1:
			typeGameSelection();
			break;
		case 2:
			break;
		case 3:
			exit = yesOrNoLoop("Are you sure? Y/N");
			if (exit)
				ExitProcess(0);
			
			input = 0;
			break;
		default:
			cout << "Wrong input." << endl;
			miliSleep(500);
			break;
		}
	} while (input != 3);
}

void Game::typeGameSelection() {
	int input;
	do
	{
		system("cls");
		cout << "Warriors Fight." << endl;
		cout << "1 - Standar Game" << endl;
		cout << "2 - Custom Game" << endl;
		cout << "3 - Back to menu" << endl;
		input = intInputLoop("Select a option: ");
		switch (input)
		{
		case 1:
			standarGame();
			break;
		case 2:
			creator.custom();
			break;
		case 3:
			break;
		default:
			cout << "Wrong input." << endl;
			miliSleep(500);
			break;
		}
	} while (input != 3);

	menu();

}

void Game::standarGame() {
	creator.standard();
	setWarriors(creator.getWarriors());
	gameLoop();
}

void Game::customGame() {
	creator.custom();
	setWarriors(creator.getWarriors());
	gameLoop();
}

void Game::gameLoop() {
	do
	{
		index++;
		if (index >= warriors.size() || index < 0)
			index = 0;

		if (warriors[index].isAlive())
			printTurn(warriors[index]);

	} while (deadWarriors < warriors.size() - 1);

	gameOverLogic();
}

void Game::setWarriors(vector<Warrior> warriors) {
	this->warriors = warriors;
}

void Game::printTurn(Warrior warrior) {
	Warrior* attackedWarrior;
	AttackType attackType;
	bool isCritic = false;

	cout << "It´s " << warrior.getName() << " turn." << endl;

	attackedWarrior = setSelectedWarriors(warrior);
	attackType = attackTypeSelector();

	cout << warrior.getName() << " attack " << attackedWarrior->getName() << endl;
	cout << attackedWarrior->getName() << " recive " << warrior.attack(attackedWarrior, attackType, &isCritic) << " damage points." << endl;

	if (isCritic) {
		cout << "IS CRITIC." << endl;
	}

	if (!attackedWarrior->isAlive())
		deadWarriors++;
}

Warrior* Game::setSelectedWarriors(Warrior warrior) {
	canSelectedWarriors.clear();
	int selection = 0;
	int indexList = 0;
	vector<int> ids;

	for (size_t i = 0; i < warriors.size(); i++)
	{
		if (warriors[i].getWarriorID() == warrior.getWarriorID() || !warriors[i].isAlive())
			continue;

		indexList++;
		cout << indexList << " - " << warriors[i].getName() << " life: " << warriors[i].getLife() << endl;
		ids.push_back(warriors[i].getWarriorID());
	}

	do
	{
		selection = intInputLoop("How do you want to attack? (Select number)");
	} while (selection < 1 || selection > warriors.size() - 1);

	selection = ids[selection - 1];

	return &warriors[selection];
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

void Game::gameOverLogic() {
	cout << warriors[index].getName() << " WINS!!!" << endl;
	cin.get();
}