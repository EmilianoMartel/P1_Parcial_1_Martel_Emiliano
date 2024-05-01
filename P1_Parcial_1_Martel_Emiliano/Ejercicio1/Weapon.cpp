#include "Weapon.h"

Weapon::Weapon(string name, WeaponType weaponType, float attack, float critRate, float critDamage) {
	this->name = name;
	this->weaponType = weaponType;
	this->attack = attack;
	this->critRate = critRate;
	this->critDamage = critDamage;
}

float Weapon::getDamage(AttackType attackType, float critRateReduction, bool isCrit) {

}