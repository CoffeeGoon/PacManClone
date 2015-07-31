#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class player
{
    public:
        player();
        void setDir(int n){if(stagger % 2 == 0){ direction = n; }}
        void traverse();
        sf::CircleShape getPac(){ return Pacio;}
        virtual ~player();
        int getDir(){ return direction;}
        void die();
        pair<int, int> getPos(){ return  make_pair(int(gridx), int(gridy));}
        int getL(){ return lives;}
        pair<double, double> getGrid(){ return make_pair(gridx, gridy);}
        void setPos(double x, double y){ gridx = x; gridy = y; }
    protected:
    private:
        double gridx;
        double gridy;
        int lives;
        int stagger;
        //0 stop
        //1 left
        //2 down
        //3 right
        //4 up
        int direction;
        sf::CircleShape Pacio;
};

#endif // PLAYER_H
