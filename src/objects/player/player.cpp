#include <player.h>

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

void player::setStrenght(int x)
{
	this->strenght = x;
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

int player::getStrenght()
{
	return this->strenght;
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

double player::setHealth(double x)
{
      this->health = x;
}

double player::setMaxHealth(double x)
{
      this->maxHealth = x;
}

double player::setDamage(double x)
{
      this->damage = x;
}

double player::changeId(int x)
{
      this->damage = x;
}

double player::getHealth()
{
      return this->health;
}

double player:getMaxHealth()
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
