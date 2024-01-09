class tile
{
    private:
        double x, y;
    public:
        void setSize(double x, double y);
}

void tile::setSize(double x, double y)
{
    this -> x = x;
    this -> y = y;
}