class player
{
private:
      double health;
      double maxHealth; // change to float
      double damage;
      //int id;

      int width;
      int height; //get from sprite size 
		  //todo(krekr) do a function to get image size
      double x;
      double y;
      //double speed; // I could get this from like dex stat

      // base stats
      int strength; // raw power scaling
      int tolerance; // how much damage can u take, stamina
      int nimbleness; // speed related things
      int understanding; // crafting and magic stuff
      int willpower; // stamina and magic stuff

      std::string pilar;

public:
      player(double health, double maxHealth, double damage);
      ~player();
      void setHealth(double x);
      void setMaxHealth(double x);
      void setDamage(double x);
      //void changeId(int x);

      //stats
      void setStrength(int x);
      void setTolerance(int x);
      void setNimbleness(int x);
      void setUnderstanding(int x);
      void setWillpower(int x);

      int getStrength();
      int getTolerance();
      int getNimbleness();
      int getUnderstanding();
      int getWillpower();

      void setPillar();
      void removePillar();
      std::string getPillar();

      //movement
      int getPos();
      void movePos(double x, double y); // make a transform function 
      // and combine it with the input function 

      //getters
      double getHealth();
      double getMaxHealth();
      double getDamage();
      //int getId();
};