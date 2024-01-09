class player
{
private:
      double health;
      double maxHealth;
      double damage;
      int id;
public:
      player(double health, double maxHealth, double damage, int id);
      ~player();
      double setHealth(double x);
      double setMaxHealth(double x);
      double setDamage(double x);
      double changeId(int x);

      double getHealth();
      double getMaxHealth();
      double getDamage();
      int getId();
};

player::player(double health, double maxHealth, double damage, int id)
{
      this->health = health;
      this->maxHealth = maxHealth;
      this->damage = damage;
      this->id = id;
}

player::~player()
{
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