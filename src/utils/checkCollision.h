class checkCollision // check if 2 points colided
{
private:

public:
      checkCollision();
      ~checkCollision();
      bool chech1VectorCollision(double x, double y);
      bool check2VectorCollision(double x, double y, double x2, double y2);
      bool check3VectorCollision(double x, double y, double x1, double y2, double x3, double y3)
      bool check4VectorCollision(double x,double y,double x2,double y2,double x3,double y3 ,double x4 ,double y4);

      bool check1VectorCollision(vectors::vec1);
      bool check2VectorCollision(vectors::vec1, vectors::vec1);
      bool check2VectorCollision(vectors::vec2);
      bool check3VectorCollision(vectors::vec1, vectors::vec1, vectors::vec1);
      bool check3VectorCollision(vectors::vec2, vectors::vec1);
      bool check3VectorCollision(vectors::vec3);
      bool check4VectorCollision(vectors::vec1, vectors::vec1, vectors::vec1, vectors::vec1);
      bool check4VectorCollision(vectors::vec2, vectors::vec2);
      bool check4VectorCollision(vectors::vec3, vectors::vec1)
};

checkCollision::checkCollision()
{
}

checkCollision::~checkCollision()
{
}

bool checkCollision::chech1VectorCollision(double x, double y)
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

bool checkCollision::chech1VectorCollision(vectors::vec1)
{
      
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
