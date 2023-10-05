#include "triangle.h"
#include <glm/glm.hpp>

namespace Graphics 
{
  namespace primitives 
  {
    struct Vertex {
      std::array<float, 4> color;
      std::array<float, 3> position;
    };     

    std::array<Vertex, 6> triangle = 
    {
      // vertexes for triangle
    }

  } 
}
