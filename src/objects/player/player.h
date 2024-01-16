#include <iostream>

class player
{
private:
      float health;
      float maxHealth; // change to float
      float damage;
      //int id;

      int width;
      int height; //get from sprite size 
		  //todo(krekr) do a function to get image size
      float x;
      float y;
      //double speed; // I could get this from like dex stat

      // base stats
      int strength; // raw power scaling
      int tolerance; // how much damage can u take, stamina
      int nimbleness; // speed related things
      int understanding; // crafting and magic stuff
      int willpower; // stamina and magic stuff

      std::string pillar;

public:
      player(float health, float maxHealth, float damage);
      ~player();

      void setHealth(float x);
      void setMaxHealth(float x);
      void setDamage(float x);
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

      // pillars of :gods: ?
      std::string setPillar(std::string x);
      void removePillar();
      void getPillar();

      //movement
      int getPos();
      void movePos(float x, float y); // make a transform function 
      // and combine it with the input function 

      //getters
      float getHealth();
      float getMaxHealth();
      float getDamage();
      //int getId();
};
