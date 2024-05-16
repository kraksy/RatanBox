#include <iostream>

class weapons
{
    private:
        std::string name;

        float x, y; // I will guess that the weapon will be on another layer from player doing all the animation , so the position will be here

        // stats are just "scaling factor for the specific weapon"
        int str;
        int tol;
        int nim;
        int und;
        int wil;

        float damage;
    public:
        //setters
        void setName(std::string);
        void setPos(float x, float y);
        void setStats(int str, int tol, int nim, int und, int wil);
        void setStr(int x);
        void setTol(int x);
        void setNim(int x);
        void setUnd(int x);
        void setWil(int x);

        //getters
        int getPos();
        int getTol();
        int getNim();
        int getUnd();
        int getWil();
        float getDamage(); // scale stats with defaulth damage stat
        void setDamage(float x); 
};