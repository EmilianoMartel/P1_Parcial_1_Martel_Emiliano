#include "Warrior.h"

Warrior::Warrior(string name, float maxHealth)
{
	this->name = name;
	this->maxHealth = maxHealth;
	currentHealth = maxHealth;
}

void Warrior::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void Warrior::setArmor(Armor armor)
{
	this->armor = armor;
}

string Warrior::getName()
{
	return name;
}

float Warrior::reciveDamage(float damage) 
{

}

float Warrior::attack(Warrior warrior, AttackType attackType, bool& isCrit)
{
	warrior.reciveDamage(weapon.getDamage(attackType,warrior.armor.getCritRateReduction(), isCrit));
}