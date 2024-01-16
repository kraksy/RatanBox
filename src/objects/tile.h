class tile
{
    private:
        float x, y;
        int h, s, l;       
    public:
        tile(float x, float y);
        ~tile();

        // colour related

        void setColour(int x, int y, in z);
        // getColour // maybe get array? 
        int getH();
        int getS();
        int getL();

        void setRed();
        void setBlue();
        void setGreen();

        void setBlack();
        void setWhite();

        // size related 

        void changeSize(float x, float y);
        void setX(float x);
        void setY(float y);
        void removeSize();
        void removeX();
        void removeY();

        float getX();
        float getY();
}

tile::tile(float x, float y)
{
    this->x = x;
    this->y = y;
}

tile::~tile()
{
}

void tile::changeSize(float x, float y)
{
    this -> x = x;
    this -> y = y;
}

void tile::setX()
{
    this->x = x;
}

void tile::SetY()
{
    this->y = y;
}

void tile::removeSize()
{
    this->x = 0.0f;
    this->y = 0.0f;
}

void tile::removeX()
{
    this->x = 0.0f;
}

void tile::removeY()
{
    this->y = 0.0f;
}

float tile::getX()
{
    return this->x;
}

float tile::getY()
{
    return this->y;
}