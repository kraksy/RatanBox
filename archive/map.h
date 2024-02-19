#pragma once
#ifndef MAP_H
#define MAP_H
class map
{
    private:
        int width;
        int height; 

        int xTiles;
        int yTiles;

        float rotation;
    public:
        map();
        ~map();
        int getWidth();
        int getHeight();
        int getXTiles();
        int getYTiles();
        float getRotation();
        int setWidth(int width);
        int setHeight(int height);
        int setXTiles(int xTiles);
        int setYTiles(int yTiles);
        float setRotation(float rotation);
        void drawMap();
};

map::map()
{
}

map::~map()
{
}

int map::getWidth()
{
    return width;
}

int map::getHeight()
{
    return height;
}

int map::getXTiles()
{
    return xTiles;
}

int map::getYTiles()
{
    return yTiles;
}

float map::getRotation()
{
    return rotation;
}

int map::setWidth(int width)
{
    width = width;
}

int map::setHeight(int height)
{
    height = height;
}

int map::setXTiles(int xTiles)
{
    xTiles = xTiles;
}

int map::setYTiles(int yTiles)
{
    yTiles = yTiles;
}

float map::setRotation(float rotation)
{
    rotation = rotation;
}

void map::drawMap()
{
    // draw the map
}

#endif // MAP_H