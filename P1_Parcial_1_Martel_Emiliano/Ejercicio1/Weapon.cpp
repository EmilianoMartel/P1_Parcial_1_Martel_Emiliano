#include "Weapon.h"

Weapon::Weapon() {
	name = "Grips";
	weaponType = Grips;
	attack = 1;
	critDamage = 1;
	critRate = 1;
}

Weapon::Weapon(string name, WeaponType weaponType, float attack, float critRate, float critDamage) {
	this->name = name;
	this->weaponType = weaponType;
	this->attack = attack;
	this->critRate = critRate;
	this->critDamage = critDamage;
}

float Weapon::getDamage(AttackType attackType, float critRateReduction, bool& isCrit) {
	int max = 100;
	int chances = rand() % 100;
	float damage = attack;

	isCrit = false;

	switch (attackType)
	{
	case Fast:

		break;
	case Normal:

		break;
	case Charged:

		break;
	default:
		break;
	}

	if (chances <= critRate - critRateReduction) {
		damage += critDamage;
		isCrit = true;
	}

	return damage;
}

string Weapon::getName(){
	return name;
}

void Weapon::printData() {
	cout << "Name: " << name << endl;
	cout << "Damage -" << attack << endl;
	cout << "Crit.Rate - " << critRate << endl;
	cout << "Critical Damage -" << critDamage << endl;
}