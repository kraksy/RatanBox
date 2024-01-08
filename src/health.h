#include <iostream>
#include <logger.h>

logger Logger = logger();

class health 
{
    int hp;
    int maxhp;
    
    public:
        int getHealth;
        int getMaxHealth;
        void setHealth(int health);
        void setMaxHealth(int health);

}

void health::setHealth(int health)
{
    if (health <= 0)
    {
        Logger.log("you cant set health to 0 or less.");
    }

    this.hp = health;
}

void health::setMaxHealth(int health)
{
    if (health <= health.hp)
    {
        std::cout << "you cant set maxHealth as hp."
    }
    if (health == health.maxhp)
    {
        std::cout << "you cant set same value."
    }
}