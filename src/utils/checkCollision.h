class checkCollision // check if 2 points colided
{
private:

public:
      checkCollision();
      ~checkCollision();
      bool checkVectorCollision(int x1, int y1, int x2, int y2);
};

checkCollision::checkCollision()
{
}

checkCollision::~checkCollision()
{
}

bool checkCollision::checkVectorCollision(int x1, int y1, int x2, int y2)
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
      