class armours()
{
    private:
        int x;
        int y;

        float health;

        float armorPoints;
        float dodgePoints;
        

        // bonuses
        //int str;
        //int tol;

    public: 
        armours();
        ~armours();

        void create();

        void changePos(int x , int y);
         
        

}

void armours::changePos(int x, int y)
{
    this->x = x;
    this->y = y;
}

