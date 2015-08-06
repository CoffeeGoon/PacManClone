#include "player.h"

player::player()
{
    gridy = 18;
    gridx = 13;
    Pacio = sf::CircleShape(8);
    Pacio.setPosition( (gridx * 16) , (gridy * 16));
    direction = 0;
    stagger = 0;
    Pacio.setFillColor(sf::Color::Yellow);
    lives = 3;

    //ctor
}

void player::rehash(){
gridy = 18;
gridx = 13;
direction = 0;
stagger = 0;
lives = 3;
}

void player::die(){
 gridy = 18;
 gridx = 13;
   direction = 0;
   stagger = 0;
 Pacio.setPosition((gridx * 16), (gridy * 16));
 lives--;
 if(lives < 0){ lives = 0;}

}

void player::traverse(){
 stagger++;
  switch(direction){
  case 0:
    stagger--;
    break;
  case 1:
      gridx-= .5;
      break;
  case 2:
    gridy+= .5;
    break;
  case 3:
    gridx+= .5;
    break;
  case 4:
    gridy-= .5;
    break;
  default:
    break;
  }
 Pacio.setPosition( (gridx * 16), (gridy * 16));

  }


player::~player()
{
    //dtor
}
