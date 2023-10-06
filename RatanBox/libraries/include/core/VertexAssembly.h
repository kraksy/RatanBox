class VertexAssembly
{
	public:	
		struct VEC;
		struct vecARRAY;
		struct Color;
		struct primitive;
};

struct VEC
{
	float x, y, z;
};

struct vecARRAY
{
	VEC vectors[];
};

struct Color
{
	float r, g, b, a;
};

struct primitive
{

};