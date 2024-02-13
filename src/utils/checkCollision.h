class checkCollision // check if 2 points colided
{
private:

public:
      checkCollision();
      ~checkCollision();
      
      bool checkVec2(float x, float y, float x2, float y2);
      bool checkVec3(float x , float y, float x2, float y2, float x3, float y3);
      bool checkVec4(float x, float ,y, float x2, float y2, float x3, float y3, float x4, float y4);
};

checkCollision::checkCollision()
{
}

checkCollision::~checkCollision()
{
}

bool checkVec2(float x, float y, float x2, float y2)
{
      if ( x == x2 || y == y2)
      {
            return true;
      }
      if (x == y2 || y == x2)
      {
            return true;
      }
      
      else
      {
            return false;
      }
}

bool checkVec3(float x, float y, float x2, float y2, float x3, float y3)
{
      if ( x == x2 )
      {
            /* code */
      }
      
}

