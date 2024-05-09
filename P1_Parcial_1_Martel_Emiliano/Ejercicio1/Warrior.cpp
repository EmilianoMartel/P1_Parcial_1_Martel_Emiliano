#include "Warrior.h"

Warrior::Warrior() {
	name = "None";
	maxHealth = 0;
	currentHealth = 0;
}

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
	currentHealth -= damage;
	return currentHealth;
}

float Warrior::attack(Warrior warrior, AttackType attackType, bool isCrit)
{
	return weapon.getDamage(attackType,warrior.armor.getCritRateReduction(), isCrit);
}