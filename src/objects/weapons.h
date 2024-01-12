class weapons()
{
    private:
        std::string name;

        int x;
        int y; 

        int str;
        int tol;
        int nim;
        int und;
        int wil;

        float damage;
    public:
        void setName(std::string);
        void setPos(int x, int y);
        void setStats(int str, int tol, int nim, int und, int wil);
        void setStr(int x);
        void setTol(int x);
        void setNim(int x);
        void setUnd(int x);
        void setWil(int x);
        int getPos();
        int getTol();
        int getNim();
        int getUnd();
        int getWil();
        float getDamage();
        void setDamage(float x);
}