#pragma once
#include <string>
#include <iostream>
#include "Armor.h"
#include "Weapon.h"

using namespace std;
class Warrior {
private:
	string name;
	Weapon weapon = Weapon();
	Armor armor = Armor();
	float maxHealth;
	float currentHealth;
	int warriorID;

public:
	Warrior();
	Warrior(string name, float maxHealth);
	void setWeapon(Weapon weapon);
	void setArmor(Armor armor);
	string getName();
	void getParameters();
	float reciveDamage(float damage);
	float attack(Warrior warrior, AttackType attackType, bool* isCrit);
	void setWarriorID(int index);
	int getWarriorID();
	float getLife();
};