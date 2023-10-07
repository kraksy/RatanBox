#include <vector>

class VertexAssembly
{
	public:	
		struct VEC; // one vector
		struct vecARRAY; // array of vectors
		struct Color; // colour rgb values
		struct indices; // just the indices points
		struct degenerate; // its a shape with id
};

struct VEC
{
	float x, y, z;
};

struct vecARRAY
{
	VEC array[];
};

struct Color
{
	float r, g, b, a;
};

struct indices
{
	VEC points[];
};


// triangle.dynamicArray = new VEC[triangle.size]{ vec1, vec2 ,vec3 };
struct degenerate
{
	int id;
	VEC* dynamicArray;
	int size;
};