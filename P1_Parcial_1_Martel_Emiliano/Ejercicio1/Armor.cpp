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
	switch (armorType)
	{
	case Clothes:
		break;
	case Leather:
		this->defense += 5.f;
		break;
	case HeavyArmor:
		this->defense += 10.f;
		break;
	default:
		break;
	}
	this->weight = weight;

	if (weight <= 10)
		this->defense += 5;

	if (weight <= 20)
		this->defense += 15;

	if (weight <= 30)
		this->defense += 20;
}

float Armor::getDamageReductionPercent(float damage)
{
	if (damage <= defense || 100.f * (defense / damage) > 90.f) {
		return 90.f;
	}

	return 100.f * (defense / damage);
}

string Armor::getName() {
	return name;
}

float Armor::getCritRateReduction()
{
	float rateReduction = 0;
	switch (armorType)
	{
	case Clothes:
		rateReduction = 0;
		break;
	case Leather:
		rateReduction = 10;
		break;
	case HeavyArmor:
		rateReduction = 15;
		break;
	default:
		break;
	}

	if (weight <= 10)
		rateReduction += 5;

	if (weight <= 20)
		rateReduction += 15;

	if (weight <= 30)
		rateReduction += 20;

	return rateReduction;
}

void Armor::printData() {
	cout << "Name: " << name << endl;
	cout << "Defense -" << defense << endl;
	cout << "Weight - " << weight << endl;
}