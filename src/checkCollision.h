class checkCollision // check if 2 points colided
{
private:
      int x;
      int y;
public:
      checkCollision();
      ~checkCollision();
};

checkCollision::checkCollision()
{
}

checkCollision::~checkCollision()
{
}

checkCollision::checkVectorCollision(int x1, int y1, int x2, int y2)
{
      if (x1 == x2 && y1 == y2)
      {
            return true;
      }
      else
      {
            return false;
      }
}
