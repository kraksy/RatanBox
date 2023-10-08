#ifndef SHAPES_H
#define SHAPES_H

#include <core/core.h>

// Define a vertex structure
struct Vertex {
    float x, y, z;
};

class Shapes {
public:
    // Constructor
    Shapes();

    // Function to define a shape by name
    void DefineShape(const std::string& name, const std::vector<Vertex>& vertices);

    // Function to get a shape by name
    std::vector<Vertex> GetShape(const std::string& name) const;

private:
    std::map<std::string, std::vector<Vertex>> shapes_;
};

#endif // SHAPES_H
