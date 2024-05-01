#include "Weapon.h"

Weapon::Weapon(string name, WeaponType weaponType, float attack, float critRate, float critDamage) {
	this->name = name;
	this->weaponType = weaponType;
	this->attack = attack;
	this->critRate = critRate;
	this->critDamage = critDamage;
}

float Weapon::getDamage(AttackType attackType, float critRateReduction, bool isCrit) {
	int max = 100;
	int chances = rand() % 100;
	int damage = attack;

	isCrit = false;

	if (chances <= critRate - critRateReduction) {
		attack += critDamage;
		isCrit = true;
	}

	return attack;
}