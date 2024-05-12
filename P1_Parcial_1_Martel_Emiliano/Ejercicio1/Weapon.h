#pragma once
#include <string>
#include <iostream>
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
	Weapon();
	Weapon(string name, WeaponType weaponType, float attack,float critRate,float critDamage);
	float getDamage(AttackType attackType, float critRateReduction,bool& isCrit);
	string getName();
	string printData();
};