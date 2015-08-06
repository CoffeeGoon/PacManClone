#ifndef TILE_H
#define TILE_H

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
class tile
{
    public:
        tile();
        void wall(){ img.setFillColor( sf::Color(29,32,161) );
            blocked = true;}
        void DeW(){
           blocked = false;
           img.setFillColor(sf::Color(0,0,0));
        }
        void warp(bool b){ port = b;}
        bool getWarp(){ return port;}
        bool getWall(){ return blocked;}
        bool getPellet(){ return pellet;}
        void setPellet(bool b){
             pellet = b;
             if(b){
          img.scale(.50, .50);
         img.setFillColor( sf::Color(255,255,255) );
             }
             else{
                img.setFillColor(sf::Color( 0 , 0 , 0 ) );
             }
        }
        bool getPow(){ return Ppellet;}
        void setPow(bool b){ Ppellet = b;
           if(b){
         img.setFillColor( sf::Color(0,255,0) );
             }}
        bool getF(){ return fruit;}
        void setF(bool b){ fruit = b;}
        sf::RectangleShape getIm(){ return img;}
        virtual ~tile();
    protected:
    private:
        sf::RectangleShape img;
        bool blocked;
        bool port;
        bool pellet;
        bool Ppellet;
        bool fruit;
};

#endif // TILE_H
