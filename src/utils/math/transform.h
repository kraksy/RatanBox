class transform
{
    private:
        int x;
        int y;
    public:
        transform();
        ~transform();
        void move(float x, float y);
        void rotate();
}

transform::transform()
{
}

transform::~transform()
{
}

void transform::move(float x, float y)
{
    this->x = x;
    this->y = y;
}

void transform::rotate()
{
    //todo
}
