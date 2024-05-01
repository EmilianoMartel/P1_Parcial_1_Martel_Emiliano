#pragma once
#include <string>
#include "Armor.h"
#include "Weapon.h"

using namespace std;
class Warrior {
private:
	string name;
	Weapon weapon = Weapon("Grips", Grips,1,1,1);
	Armor armor = Armor("Clothes", Clothes,0,0);
	float maxHealth;
	float currentHealth;
public:
	Warrior(string name, float maxHealth);
	void setWeapon(Weapon weapon);
	void setArmor(Armor armor);
	string getName();
	float reciveDamage(float damage);
	float attack(Warrior warrior, AttackType attackType, bool& isCrit);
};