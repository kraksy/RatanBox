#include <player.h>
#include <iostream>

// todo fix the values

player::player(double health, double maxHealth, double damage)
{
      this->health = health;
      this->maxHealth = maxHealth;
      this->damage = damage;
      //this->id = id; // there no need for id if no multiplayer
}

player::~player()
{
}

// setters

void 

void player::setStrength(int x)
{
      this->strength = x;
}

void player::setTolerance(int x)
{
	this->tolerance = x;
}

void player::setNimbleness(int x)
{
	this->nimbleness = x;
}

void player::setUnderstanding(int x)
{
	this->understanding = x;
}

void player::setWillpower(int x)
{
	this->willpower = x;
}

void player::setHealth(double x)
{
      this->health = x;
}

void  player::setMaxHealth(double x)
{
      this->maxHealth = x;
}

void  player::setDamage(double x)
{
      this->damage = x;
}

// getters

std::string player::getPillar(std::string x)
{
      this->pillar = x;
}

int player::getStrength()
{
      return this->strength;
}

int player::getTolerance()
{
	return this->tolerance;
}

int player::getNimbleness()
{
	return this->nimbleness;
}

int player::getUnderstanding()
{
	return this->understanding;
}

int player::getWillpower()
{
	return this->willpower;
}

double player::getHealth()
{
      return this->health;
}

double player::getMaxHealth()
{
      return this->maxHealth;
}

double player::getDamage()
{
      return this->damage;
}

int player::getId()
{
      return this->id;
}
