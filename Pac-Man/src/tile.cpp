#include "tile.h"

tile::tile()
{
    img = sf::RectangleShape(sf::Vector2f(4, 4));
    img.setFillColor( sf::Color(0,0,0) );
    blocked = false;
    port = false;
    pellet = false;
    Ppellet = false;
    fruit = false;
}

tile::~tile()
{
    //dtor
}
