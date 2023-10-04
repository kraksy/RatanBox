#pragma once

#include <glm/glm.hpp>
#include <iostream>


class RElements
{
	public:
		struct Vertex
		{
			std::array<float, 4> color;
			std::array<float, 3> position;
		};

		static std::array<Vertex, 6> challenge1Square = {
			//      Color                         Position
			Vertex{{0.9f,  0.1f, 0.12f, 1.0f},   {-0.5f, -0.5f, 0.0f}},
			Vertex{{0.1f,  0.9f, 0.12f, 1.0f},   {-0.5f,  0.5f, 0.0f}},
			Vertex{{0.12f, 0.9f, 0.1f,  1.0f},   { 0.5f,  0.5f, 0.0f}},

			Vertex{{0.9f,  0.1f, 0.12f, 1.0f},   {-0.5f, -0.5f, 0.0f}},
			Vertex{{0.12f, 0.9f, 0.1f,  1.0f},   { 0.5f,  0.5f, 0.0f}},
			Vertex{{0.12f, 0.1f, 0.9f,  1.0f},   { 0.5f, -0.5f, 0.0f}}
		};
		
};







