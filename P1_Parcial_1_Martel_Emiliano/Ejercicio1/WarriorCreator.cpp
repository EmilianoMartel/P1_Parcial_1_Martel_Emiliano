#include "WarriorCreator.h"

WarriorCreator::WarriorCreator() {
	weaponSize = 0;
	armorSize = 0;
	warriorsSize = 0;
}

void WarriorCreator::custom() {
	string input;
	bool inputValue = false;
	int size = 0;
	string lines = "How many warriors do you want to create?";
	printData(lines, 41, 0);

	startWarriorsArray(size, false);
}

void WarriorCreator::standard() {
	startWarriorsArray(2, true);
}

void WarriorCreator::startWarriorsArray(int arraySize, bool isStandard) {
	for (int i = 0; i < arraySize; ++i) {
		warriors.push_back(createWarrior(isStandard));
		warriors[i].setWarriorID(i);
		system("cls");
	}
}

Warrior WarriorCreator::createWarrior(bool isStandard) {
	string input;
	bool createNew = false;
	float life = 0;
	string line = "Please insert the warrior name: ";
	int indexer;
	printData(line, 40, &indexer);
	indexer++;
	goToCoordinates(40, indexer);
	getline(cin, input);
	string name = input;
	line = "";
	printData(line, 40, &indexer);
	indexer++;
	life = floatInputLoop("How many life points does it have ?", 41, indexer);
	Warrior warrior = Warrior(name, life);

	if (isStandard) {
		createStandarArmors();
		createStandarWeapons();
	}
	line = "";
	printData(line, 40, &indexer);
	indexer++;
	createNew = yesOrNoLoop("Do you want the warrior to have a weapon? Y/N", 40, indexer);
	if (createNew) {
		warrior.setWeapon(setWarriorWeapon());
	}
	line = "";
	printData(line, 40, &indexer);
	indexer++;
	createNew = yesOrNoLoop("Do you want the warrior to have a armor? Y/N", 40, indexer);
	if (createNew) {
		warrior.setArmor(createArmor());
	}

	return warrior;
}

void WarriorCreator::createStandarWeapons() {
	weapons.push_back(Weapon("Standard Sword", Sword, 15.f, 30.5f, 20.f));
	weapons.push_back(Weapon("Standard Lance", Lance, 20.f, 20.5f, 50.f));
	weapons.push_back(Weapon("Standard Bow", Bow, 20.6f, 40.8f, 10.f));
}

void WarriorCreator::createStandarArmors() {
	armors.push_back(Armor("Standard Leather", Leather, 20.f, 5.f));
	armors.push_back(Armor("Standard Heavy", HeavyArmor, 20.f, 20.f));
}

Weapon WarriorCreator::setWarriorWeapon() {
	bool useCreatedWeapon = false;
	int input = 0;

	if (weapons.size() <= 0) {
		weapons.push_back(newWeapon());

		return weapons[0];
	}
	else {
		int indexer;
		string lines = "";
		printData(lines, 40, &indexer);
		indexer++;
		useCreatedWeapon = yesOrNoLoop("Do you want to use an already created weapon? Y/N", 40, indexer);
		if (useCreatedWeapon) {
			for (size_t i = 0; i < weapons.size(); i++)
			{
				lines += to_string(i + 1) + " - " + weapons[i].printData();
			}
			do
			{
				printData(lines, 20, &indexer);
				indexer++;
				input = intInputLoop("Insert a number: ", 40, indexer);
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
	int indexer;
	string lines = "Please insert the weapon name: ";
	printData(lines, 40, &indexer);
	indexer++;
	goToCoordinates(40, indexer);
	getline(cin, input);
	string name = input;

	type = weaponTypeSelector();

	lines = "";
	printData(lines, 40, &indexer);
	attack = floatInputLoop("How many attack point does it have?", 41, indexer);
	printData(lines, 40, &indexer);
	critRate = floatInputLoop("How much critical rate damage does it have?", 41, indexer);
	printData(lines, 40, &indexer);
	critDamage = floatInputLoop("How much critical damage points does it have?", 41, indexer);

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
		string lines = "";
		int indexer;
		printData(lines, 40, &indexer);
		indexer++;
		useCreatedArmor = yesOrNoLoop("Do you want to use an already created armor? Y/N", 40, indexer);
		if (useCreatedArmor) {
			for (size_t i = 0; i < armors.size(); i++)
			{
				lines += to_string(i + 1) + " - " + armors[i].printData();
			}
			do
			{
				printData(lines, 20, &indexer);
				indexer++;
				input = intInputLoop("Insert a number: ", 40, indexer);
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
	int indexer;
	string lines = "Please insert the armor name: ";
	printData(lines, 40, &indexer);
	indexer++;
	goToCoordinates(40, indexer);
	getline(cin, input);
	string name = input;

	type = armorTypeSelector();

	lines = "";
	printData(lines, 40, &indexer);
	defense = floatInputLoop("How many defense point does it have?", 41, indexer);
	printData(lines, 40, &indexer);
	weight = floatInputLoop("How much does it weigh? If you have too much weigh your critical chances will be reduced.\nRecommend number between 0 to 30.", 41, indexer);

	return Armor(name, type, defense, weight);
}

WeaponType WarriorCreator::weaponTypeSelector() {
	int input = 0;
	int indexer;
	string lines = R"(What weapon type is it?
1 - Grips
2 - Sword
3 - Lance
4 - Bow)";
	printData(lines, 40, &indexer);
	indexer++;
	do
	{
		input = intInputLoop("Insert a number: ", 41, indexer);
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
	int indexer;
	string lines = R"(What armor type is it?
1 - Clothes (standard defense)
2 - Leather (increment 5 points defense, reduce 10 poins crit rate)
3 - HeavyArmor (increment 10 points defense, reduce 15 poins crit rate))";
	printData(lines, 40, &indexer);
	indexer++;
	do
	{
		input = intInputLoop("Insert a number: ", 41, indexer);
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