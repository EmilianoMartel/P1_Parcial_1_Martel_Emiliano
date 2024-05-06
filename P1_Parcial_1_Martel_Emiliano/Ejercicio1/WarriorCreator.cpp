#include "WarriorCreator.h"

void WarriorCreator::Start() {
	string input;
	bool inputValue = false;
	int size = 0;

	size = IntInputLoop("How many warriors do you want to create?");

	StartWarriorsArray(size);
}

void WarriorCreator::StartWarriorsArray(int arraySize) {
    warriors = new Warrior*[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        warriors[i] = CreateWarrior();
    }
}

Warrior* WarriorCreator::CreateWarrior() {
	string input;
	bool inputValid = false;
	int life = 0;
	cout << "Please insert the warrior name: " << endl;
	getline(cin, input);
	string name = input;

	life = IntInputLoop("How many life points does it have ?");

	cout << "Do you want the warrior to have a weapon? Y/N" << endl;

	return new Warrior(name,life);
}

Weapon* WarriorCreator::CreateWeapon() {
	return new Weapon("Grips", Grips, 1, 1, 1);
}

Armor* WarriorCreator::CreateArmor() {
	return new Armor("Clothes", Clothes, 0, 0);
}

bool WarriorCreator::IntCheacker(string input) {
	for (char c : input) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

int WarriorCreator::IntInputLoop(string question) {
	string input;
	bool inputValid = false;
	do
	{
		cout << question << endl;
		getline(cin, input);

		inputValid = IntCheacker(input);

		if (inputValid) {
			return stoi(input);
		}
		else {
			cout << "Invalid input, try again." << endl;
		}
	} while (!inputValid);
}