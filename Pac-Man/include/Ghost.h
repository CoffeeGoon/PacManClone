#include <cmath>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef GHOST_H
#define GHOST_H

using namespace std;
//game map location macro


//distance between target and reference object
typedef std::pair<double, double> Coord;

class Ghost
{

    public:
        Ghost();
        virtual ~Ghost();
        void options(bool l, bool d, bool r, bool u);
        void AI(int time, Coord& target, bool ch);
        void setFlee(bool k){flee = k;}
        bool getFlee(){return flee;}
        bool getAc(){return active;}
        bool getM(){return mode;}
        void die(){dead = true;}
        void res(int n);
        bool getDead(){ return dead;}
        bool getBlank(){ return blank;}
        void setDir(int n){ curDir = n;}
        int getDir(){ return curDir;}
        void decGP(){ if(!active){GP--;} }
        int getGP(){ return GP;}
        int getPcount(){ return pelletcount;}
        int setPcount(int n){ pelletcount = n;}
        void setRate(int n){ rate = n;}
        sf::CircleShape getIm(){ return proto;}
        Coord getLoc(){ return pos;}
        Coord getSeek(){ return seek;}


    protected:
        int falter;
        int rate;
        int pelletcount;
        int stutter;
        int reset;
        int GP;
        int version;
        double distance(Coord& a, Coord& b){
        double intermediate = ((b.first - a.first) *(b.first - a.first) + (b.second - a.second)*(b.second - a.second));
        intermediate = sqrt(intermediate);
        return intermediate;
}
      Coord pos;
      Coord seek;
      int curDir;
      bool flee;
      bool dead;
      bool* nextMove;
      bool active;
      bool mode;
      bool blank;
      sf::CircleShape proto;
      private:


};

class Blinky: public Ghost {
 public:
 Blinky();
 // void AI(int time, Coord& target, bool ch);
 private:

};

class Pinky: public Ghost {
  public:
      Pinky();
      //void AI(int time, Coord& target, bool ch){};
  private:
};

class Inky: public Ghost {
  public:
      Inky();
       // void AI(int time, Coord& target, bool ch) {};
  private:
};

class Clyde: public Ghost {
 public:
     Clyde();
     // void AI(int time, Coord& target, bool ch) {};
 private:

};

#endif // GHOST_H
