#pragma once
#include <glm/glm.hpp>

class RColour 
{
	public:
		Colour color;
		glm::vec3 getColour() 
		{
			switch (color)
			{
			case BLACK:
				return glm::vec3(0, 0, 0);
			case WHITE:
				return glm::vec3(1, 1, 1);
			case RED:
				return glm::vec3(1, 0, 0);
			case BLUE:
				return glm::vec3(0, 0, 1);
			case GREEN:
				return glm::vec3(0, 1, 0);
			}
		}
		
};

enum Colour {
	BLACK,
	WHITE,
	RED,
	BLUE,
	GREEN,
};
