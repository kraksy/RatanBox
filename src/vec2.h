class vec2
{
private:
      double x;
      double y;
public:
      double getX;
      double getY;

      bool operator == (const vec2 & rhs) const;

      vec2(double x, double y);
      ~vec2();
};

vec2::vec2(double x, double y)
{
}

vec2::~vec2()
{
}
