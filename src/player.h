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
