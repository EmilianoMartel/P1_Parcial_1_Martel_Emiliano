#include "Armor.h"

Armor::Armor() {
	name = "Clothes";
	armorType = Clothes;
	defense = 1;
	weight = 1;
}

Armor::Armor(string name, ArmorType armorType, float defense, float weight)
{
	this->name = name;
	this->armorType = armorType;
	this->defense = defense;
	this->weight = weight;
}

float Armor::getDamageReductionPercent(float damage)
{
	if (damage <= defense) {
		return 99;
	}
	return damage / defense;
}

string Armor::getName() {
	return name;
}

float Armor::getCritRateReduction()
{
	switch (armorType)
	{
	case Clothes:
		return 0;
		break;
	case Leather:
		return 10;
		break;
	case HeavyArmor:
		return 40;
		break;
	default:
		return 0;
		break;
	}
}