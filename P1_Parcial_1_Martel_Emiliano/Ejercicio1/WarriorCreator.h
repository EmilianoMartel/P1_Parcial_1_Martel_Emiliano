#pragma once
#include "Warrior.h"
#include "GeneralFunctions.h"
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

class WarriorCreator {
private:
	int warriorsSize = 0;
	int weaponSize = 0;
	int armorSize = 0;
	vector<Warrior> warriors;
	vector<Weapon>  weapons;
	vector<Armor> armors;

	void startWarriorsArray(int arraySize, bool isStandard);
	Warrior createWarrior(bool isStandard);
	Weapon setWarriorWeapon();
	Weapon newWeapon();
	Armor createArmor();
	Armor newArmor();
	void createStandarWeapons();
	void createStandarArmors();
	WeaponType weaponTypeSelector();
	ArmorType armorTypeSelector();

public:
	WarriorCreator();
	void custom();
	void standard();
	vector<Warrior> getWarriors();
};