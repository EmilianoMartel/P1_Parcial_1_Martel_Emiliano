#pragma once
#include <string>
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
public:
	Warrior();
	Warrior(string name, float maxHealth);
	void setWeapon(Weapon weapon);
	void setArmor(Armor armor);
	string getName();
	float reciveDamage(float damage);
	float attack(Warrior warrior, AttackType attackType, bool isCrit);
};