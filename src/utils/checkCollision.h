class checkCollision // check if 2 points colided
{
private:

public:
      checkCollision();
      ~checkCollision();
      bool chech1VectorCollision(int x, int y);
      bool check2VectorCollision(int x1, int y1, int x2, int y2);
      bool check4VectorCollision(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
};

checkCollision::checkCollision()
{
}

checkCollision::~checkCollision()
{
}

bool checkCollision::chech1VectorCollision(int x, int y)
{
      if ( x == y )
      {
            return true;
      }
      else
      {
            return false;
      }
}

bool checkCollision::check2VectorCollision(int x1, int y1, int x2, int y2)
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

bool checkCollision::check4VectorCollision(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
      if ()
}