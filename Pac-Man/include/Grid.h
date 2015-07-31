#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "tile.h"


class Grid
{
    public:
        Grid();
        virtual ~Grid();
        vector<tile>* getMap(){ return grid;}
        void eat(){ pellets--;}
        void modeshift(int time);
        bool getCh(){ return chase;}
        bool getFl(){ return flee;}
        int amount(){ return pellets;}
    protected:
    private:
        vector<tile>* grid;
        bool chase;
        bool flee;
        int pellets;
};

#endif // GRID_H
