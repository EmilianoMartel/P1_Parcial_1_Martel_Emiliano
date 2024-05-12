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
		int indexer;
		string lines = "1 - Play\n2 - Instructions\n3 - Exit";
		printData(lines,41,&indexer);
		goToCoordinates(41, indexer);
		input = intInputLoop("Select a option: ",41,indexer);
		switch (input)
		{
		case 1:
			typeGameSelection();
			break;
		case 2:
			instructions();
			break;
		case 3:
			exit = yesOrNoLoop("Are you sure? Y/N",40,1);
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

void Game::instructions() {
	system("cls");
	string lines = R"(Is is a turn-based combat.
In your turn you can select who to attack.
Then you can choose which type of attack to make.
          - Fast -
Increases your critical chance 10%
but you lose 5% of critical damage.
          - Normal - 
Increase your basic damage 5%
but you lose your critical chance in 10%.
          - Charged - 
Increse your basic and critical damage in 10%
but you lose your critical chance in 15%.)";
	int indexer;
	printData(lines, 24, &indexer);
	indexer++;
	goToCoordinates(24, indexer);
	cout << "Press any key to continue..." << endl;
	_getch();
	system("cls");
}

void Game::typeGameSelection() {
	int input;
	do
	{
		system("cls");
		string lines = R"(1 - Standard Game
2 - Custom Game
3 - Back to menu)";
		int indexer = draw();
		indexer++;
		printData(lines, 40, &indexer);
		indexer++;
		input = intInputLoop("Select a option: ",41, indexer);
		switch (input)
		{
		case 1:
			standarGame();
			break;
		case 2:
			customGame();
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

	system("cls");
	string lines = R"(It's )" + warrior.getName() + R"( turn.)";
	int indexer = draw();
	indexer++;
	printData(lines, 40, &indexer);
	indexer++;

	attackedWarrior = setSelectedWarriors(warrior);
	attackType = attackTypeSelector();
	
	lines = warrior.getName() + " attack " + attackedWarrior->getName() + "\n" + attackedWarrior->getName() + " recive " + to_string(warrior.attack(attackedWarrior, attackType, &isCritic)) + " damage points.";

	if (isCritic) {
		lines +=  "\nIS CRITIC.";
	}
	printData(lines, 40, &indexer);
	indexer++;
	goToCoordinates(40, indexer);
	cout << "Press any key to coninue...";
	_getch();
	if (!attackedWarrior->isAlive())
		deadWarriors++;
}

Warrior* Game::setSelectedWarriors(Warrior warrior) {
	canSelectedWarriors.clear();
	int selection = 0;
	int indexList = 0;
	vector<int> ids;
	string lines = "";
	for (size_t i = 0; i < warriors.size(); i++)
	{
		if (warriors[i].getWarriorID() == warrior.getWarriorID() || !warriors[i].isAlive())
			continue;

		indexList++;
		lines += to_string(indexList) + " - " + warriors[i].getName() + " life: " + to_string(warriors[i].getLife()) + "\n";
		ids.push_back(warriors[i].getWarriorID());
	}
	system("cls");
	int indexer = draw();
	indexer++;
	printData(lines, 40, &indexer);
	indexer++;
	do
	{
		selection = intInputLoop("Who do you want to attack? (Select number)", 40, indexer);
	} while (selection < 1 || selection > warriors.size() - 1);

	selection = ids[selection - 1];

	return &warriors[selection];
}

AttackType Game::attackTypeSelector() {
	int input = 0;
	system("cls");
	string lines = R"(What attack type do you want to do?
1 - Fast
2 - Normal
3 - Charged)";
	int indexer = draw();
	indexer++;
	printData(lines, 40, &indexer);
	do
	{
		input = intInputLoop("Insert a number: ", 40, indexer);
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
	int indexer;
	string line = "";
	printData(line,40,&indexer);
	indexer++;
	goToCoordinates(40,indexer);
	cout << warriors[index].getName() << " WINS!!!" << endl;
	cin.get();
}