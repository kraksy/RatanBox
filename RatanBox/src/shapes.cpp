#include "core/core.h"

Shapes::Shapes() {
    // Define and add a triangle
    shapes_["Triangle"] = {
        { -0.5f, -0.5f, 0.0f },
        { 0.5f, -0.5f, 0.0f },
        { 0.0f, 0.5f, 0.0f }
    };

    // Define and add a square
    shapes_["Square"] = {
        { -0.3f, -0.3f, 0.0f },
        { 0.3f, -0.3f, 0.0f },
        { -0.3f, 0.3f, 0.0f },
        { 0.3f, -0.3f, 0.0f },
        { 0.3f, 0.3f, 0.0f },
        { -0.3f, 0.3f, 0.0f }
    };
}

// Function to define a shape by name
void Shapes::DefineShape(const std::string& name, const std::vector<Vertex>& vertices) {
    shapes_[name] = vertices;
}

// Function to get a shape by name
std::vector<Vertex> Shapes::GetShape(const std::string& name) const {
    auto it = shapes_.find(name);
    if (it != shapes_.end()) {
        return it->second;
    }

    return {};
}
