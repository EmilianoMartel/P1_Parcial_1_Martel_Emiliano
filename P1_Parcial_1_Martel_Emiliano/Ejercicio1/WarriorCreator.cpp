#include "WarriorCreator.h"

WarriorCreator::WarriorCreator() {
	weaponSize = 0;
	armorSize = 0;
	warriorsSize = 0;
}

void WarriorCreator::start() {
	string input;
	bool inputValue = false;
	int size = 0;

	size = intInputLoop("How many warriors do you want to create?");

	startWarriorsArray(size);
}

void WarriorCreator::startWarriorsArray(int arraySize) {
	for (int i = 0; i < arraySize; ++i) {
		warriors.push_back(createWarrior());
	}
}

Warrior WarriorCreator::createWarrior() {
	string input;
	bool createNew = false;
	int life = 0;
	cout << "Please insert the warrior name: " << endl;
	getline(cin, input);
	string name = input;

	life = intInputLoop("How many life points does it have ?");
	Warrior warrior = Warrior(name, life);

	createNew = yesOrNoLoop("Do you want the warrior to have a weapon? Y/N");
	if (createNew) {
		warrior.setWeapon(createWeapon());
	}

	createNew = yesOrNoLoop("Do you want the warrior to have a armor? Y/N");
	if (createNew) {
		warrior.setArmor(createArmor());
	}

	return warrior;
}

Weapon WarriorCreator::createWeapon() {
	bool useCreatedWeapon = false;
	int input = 0;
	
	if (weapons.size() <= 0) {
		weapons.push_back(newWeapon());

		return weapons[0];
	}
	else {
		useCreatedWeapon = yesOrNoLoop("Do you want to use an already created weapon? Y/N");
		if (useCreatedWeapon) {
			for (size_t i = 0; i < weapons.size(); i++)
			{
				cout << i + 1 << " - " << weapons[i].getName() << endl;
			}
			do
			{
				input = intInputLoop("Insert a number: ");
			} while (input < 1 || input > weapons.size());
			return weapons[input - 1];
		}
		else {
			weapons[weaponSize - 1] = newWeapon();
			return weapons[weaponSize - 1];
		}
	}
}

Weapon WarriorCreator::newWeapon() {
	string input;
	WeaponType type;
	int attack;
	int critRate;
	int critDamage;
	cout << "Please insert the weapon name: " << endl;
	getline(cin, input);
	string name = input;

	type = weaponTypeSelector();

	attack = intInputLoop("How many attack point does it have?");
	critRate = intInputLoop("How much critical rate damage does it have?");
	critDamage = intInputLoop("How much critical damage points does it have?");

	return Weapon(name, type, attack, critRate, critDamage);
}

Armor WarriorCreator::createArmor() {
	bool useCreatedArmor = false;
	int input = 0;
	if (armors.size() == 0) {
		armors.push_back(newArmor());
		return armors[0];
	}
	else {
		useCreatedArmor = yesOrNoLoop("Do you want to use an already created armor? Y/N");
		if (useCreatedArmor) {
			for (size_t i = 0; i < weapons.size(); i++)
			{
				cout << i + 1 << " - " << armors[i].getName() << endl;
			}
			do
			{
				input = intInputLoop("Insert a number: ");
			} while (input < 1 || input > armors.size());
			return armors[input - 1];
		}
		else {
			armors.push_back(newArmor());
			return armors[armors.size() - 1];
		}
	}
}

Armor WarriorCreator::newArmor() {
	string input;
	ArmorType type;
	int defense;
	int weight;

	cout << "Please insert the armor name: " << endl;
	getline(cin, input);
	string name = input;

	type = armorTypeSelector();

	defense = intInputLoop("How many defense point does it have?");
	weight = intInputLoop("How much does it weigh?");

	return Armor(name, type, defense, weight);
}

bool WarriorCreator::intCheacker(string input) {
	for (char c : input) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

int WarriorCreator::intInputLoop(string question) {
	string input;
	bool inputValid = false;
	do
	{
		cout << question << endl;
		getline(cin, input);

		inputValid = intCheacker(input);

		if (inputValid) {
			return stoi(input);
		}
		else {
			cout << "Invalid input, try again." << endl;
		}
	} while (!inputValid);
	return 0;
}

bool WarriorCreator::yesOrNoLoop(string question) {
	string input;
	bool inputValid = false;
	do
	{
		cout << question << endl;
		getline(cin, input);

		if (input == "Y" || input == "y" || input == "N" || input == "n") {
			inputValid = true;
		}
		else {
			cout << "Invalid input. Try again." << endl;
		}
	} while (!inputValid);

	if (input == "Y" || input == "y") {
		return true;
	}
	return false;
}

WeaponType WarriorCreator::weaponTypeSelector() {
	int input = 0;
	cout << "What weapon type is it?" << endl;
	cout << "1 - Grips" << endl;
	cout << "2 - Sword" << endl;
	cout << "3 - Lance" << endl;
	cout << "4 - Bow" << endl;
	do
	{
		input = intInputLoop("Insert a number: ");
	} while (input < 1 || input > 4);

	switch (input)
	{
	case 1:
		return Grips;
		break;
	case 2:
		return Sword;
		break;
	case 3:
		return Lance;
		break;
	case 4:
		return Bow;
		break;
	default:
		return Grips;
		break;
	}
}

ArmorType WarriorCreator::armorTypeSelector() {
	int input = 0;
	cout << "What armor type is it?" << endl;
	cout << "1 - Clothes" << endl;
	cout << "2 - Leather" << endl;
	cout << "3 - HeavyArmor" << endl;
	do
	{
		input = intInputLoop("Insert a number: ");
	} while (input > 0 && input < 5);

	switch (input)
	{
	case 1:
		return Clothes;
		break;
	case 2:
		return Leather;
		break;
	case 3:
		return HeavyArmor;
		break;
	default:
		return Clothes;
		break;
	}
}