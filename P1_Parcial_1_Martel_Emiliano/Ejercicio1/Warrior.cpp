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
	//POR ACA HAY QUE ARREGLAR
	currentHealth -= damage;
	return currentHealth;
}

float Warrior::attack(Warrior warrior, AttackType attackType, bool* isCrit)
{
	float damage = weapon.getDamage(attackType, warrior.armor.getCritRateReduction(), *isCrit);
	warrior.reciveDamage(damage);
	return damage;
}

void Warrior::getParameters() {
	cout << getName() << "-weapon: " << weapon.getName() << "-armor: " << armor.getName() << endl;
}

void Warrior::setWarriorID(int index) {
	warriorID = index;
}

int Warrior::getWarriorID() {
	return warriorID;
}

float Warrior::getLife() {
	return currentHealth;
}