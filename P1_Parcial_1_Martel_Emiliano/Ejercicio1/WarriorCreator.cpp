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
		warriors[i].setWarriorID(i);
		system("cls");
	}
}

Warrior WarriorCreator::createWarrior() {
	string input;
	bool createNew = false;
	float life = 0;
	cout << "Please insert the warrior name: " << endl;
	getline(cin, input);
	string name = input;

	life = floatInputLoop("How many life points does it have ?");
	Warrior warrior = Warrior(name, life);

	createNew = yesOrNoLoop("Do you want the warrior to have a weapon? Y/N");
	if (createNew) {
		warrior.setWeapon(setWarriorWeapon());
	}

	createNew = yesOrNoLoop("Do you want the warrior to have a armor? Y/N");
	if (createNew) {
		warrior.setArmor(createArmor());
	}

	return warrior;
}

Weapon WarriorCreator::setWarriorWeapon() {
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
				cout << i + 1 << endl;
				weapons[i].printData();
			}
			do
			{
				input = intInputLoop("Insert a number: ");
			} while (input < 1 || input > weapons.size());
			return weapons[input - 1];
		}
		else {
			weapons.push_back(newWeapon());
			return weapons[weapons.size() - 1];
		}
	}
}

Weapon WarriorCreator::newWeapon() {
	string input;
	WeaponType type;
	float attack;
	float critRate;
	float critDamage;
	cout << "Please insert the weapon name: " << endl;
	getline(cin, input);
	string name = input;

	type = weaponTypeSelector();

	attack = floatInputLoop("How many attack point does it have?");
	critRate = floatInputLoop("How much critical rate damage does it have?");
	critDamage = floatInputLoop("How much critical damage points does it have?");

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
				armors[i].printData();
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
	float defense;
	float weight;

	cout << "Please insert the armor name: " << endl;
	getline(cin, input);
	string name = input;

	type = armorTypeSelector();

	defense = floatInputLoop("How many defense point does it have?");
	weight = floatInputLoop("How much does it weigh?");

	return Armor(name, type, defense, weight);
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
	} while (input < 1 || input > 3);

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

vector<Warrior> WarriorCreator::getWarriors() {
	return warriors;
}