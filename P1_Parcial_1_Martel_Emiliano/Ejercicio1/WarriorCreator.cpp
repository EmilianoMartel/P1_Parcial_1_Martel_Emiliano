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

	size = intInputLoop("How many warriors do you want to create?", 41, 0);

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
	cout << "Please insert the warrior name: " << endl;
	getline(cin, input);
	string name = input;

	life = floatInputLoop("How many life points does it have ?", 41, 0);
	Warrior warrior = Warrior(name, life);

	if (isStandard) {
		createStandarArmors();
		createStandarWeapons();
	}

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

void WarriorCreator::createStandarWeapons(){
	weapons.push_back(Weapon("Standard Sword", Sword,15.f,30.5f,20.f));
	weapons.push_back(Weapon("Standard Lance", Lance, 20.f, 20.5f, 50.f));
	weapons.push_back(Weapon("Standard Bow", Bow, 20.6f, 40.8f, 10.f));
}

void WarriorCreator::createStandarArmors(){
	armors.push_back(Armor("Standard Leather", Leather,20.f,5.f));
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
		useCreatedWeapon = yesOrNoLoop("Do you want to use an already created weapon? Y/N");
		if (useCreatedWeapon) {
			for (size_t i = 0; i < weapons.size(); i++)
			{
				cout << i + 1 << endl;
				weapons[i].printData();
			}
			do
			{
				input = intInputLoop("Insert a number: ", 41, 0);
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

	attack = floatInputLoop("How many attack point does it have?", 41, 0);
	critRate = floatInputLoop("How much critical rate damage does it have?", 41, 0);
	critDamage = floatInputLoop("How much critical damage points does it have?", 41, 0);

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
			for (size_t i = 0; i < armors.size(); i++)
			{
				cout << i + 1 << endl;
				armors[i].printData();
			}
			do
			{
				input = intInputLoop("Insert a number: ", 41, 0);
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

	defense = floatInputLoop("How many defense point does it have?", 41, 0);
	weight = floatInputLoop("How much does it weigh? If you have too much weigh your critical chances will be reduced.\nRecommend number between 0 to 30.", 41, 0);

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
		input = intInputLoop("Insert a number: ", 41, 0);
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
	cout << "1 - Clothes (standard defense)" << endl;
	cout << "2 - Leather (increment 5 points defense, reduce 10 poins crit rate)" << endl;
	cout << "3 - HeavyArmor (increment 10 points defense, reduce 15 poins crit rate)" << endl;
	do
	{
		input = intInputLoop("Insert a number: ", 41, 0);
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