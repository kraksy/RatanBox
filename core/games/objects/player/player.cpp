#include <player.h>
#include <iostream>

player::player(float health, float maxHealth, float damage)
{
      this->health = health;
      this->maxHealth = maxHealth;
      this->damage = damage;
}

player::~player()
{
}

// setters

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

void player::setHealth(float x)
{
      this->health = x;
}

void  player::setMaxHealth(float x)
{
      this->maxHealth = x;
}

void  player::setDamage(float x)
{
      this->damage = x;
}

void player::setPillar(std::string x)
{
      this->pillar = x;
}

// getters

std::string player::getPillar()
{
      return this->pillar;
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

float player::getHealth()
{
      return this->health;
}

float player::getMaxHealth()
{
      return this->maxHealth;
}

float player::getDamage()
{
      return this->damage;
}