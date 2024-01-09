class player
{
private:
      double health;
      double maxHealth;
      double damage;
      //int id;

      int width;
      int height; //get from sprite size 
		  //todo(krekr) do a function to get image size
      double x;
      double y;
      double speed;
public:
      player(double health, double maxHealth, double damage, int id);
      ~player();
      void setHealth(double x);
      void setMaxHealth(double x);
      void setDamage(double x);
      //void changeId(int x);
	
      int getPos();
      void movePos(double x, double y) // make a transform function 
      // and combine it with the input function 

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
