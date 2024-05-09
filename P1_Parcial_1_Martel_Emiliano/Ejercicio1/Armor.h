#pragma once
#include <string>
#include "ArmorType.h"

using namespace std;

class Armor {
private:
	string name;
	ArmorType armorType;
	float defense;
	float weight;
public:
	Armor();
	Armor(string name, ArmorType armorType,float defense,float weight);
	float getDamageReductionPercent(float damage);
	float getCritRateReduction();
	string getName();
};