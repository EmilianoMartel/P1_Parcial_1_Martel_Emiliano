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

	void startWarriorsArray(int arraySize);
	Warrior createWarrior();
	Weapon setWarriorWeapon();
	Weapon newWeapon();
	Armor createArmor();
	Armor newArmor();
	bool intCheacker(string input);
	int intInputLoop(string question);
	bool yesOrNoLoop(string question);
	WeaponType weaponTypeSelector();
	ArmorType armorTypeSelector();

public:
	WarriorCreator();
	void start();
	vector<Warrior> getWarriors();
};