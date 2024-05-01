#pragma once
#include <string>
#include "WeaponType.h"
#include "AttackType.h"

using namespace std;

class Weapon {
private:
	string name;
	WeaponType weaponType;
	float attack;
	float critRate;
	float critDamage;

public:
	Weapon(string name, WeaponType weaponType, float attack,float critRate,float critDamage);
	float getDamage(AttackType attackType, float critRateReduction,bool isCrit);
};