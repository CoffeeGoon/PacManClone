
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cmath>
#include <sstream>
#include <vector>
#include "tile.h";
#include "Grid.h";
#include "player.h";
#include "Ghost.h";

using namespace std;

//game map location macro




int main(){
  sf::Texture sheet;
if(! sheet.loadFromFile("src/gamesheet.png")){ cout << " failed! " << endl;}
sf::RenderWindow window(sf::VideoMode(600, 600), "Pac-Man");
int value = 16;
int runtime = 0;
vector<sf::Sprite> sprites[6];
for(int i = 0; i < 6; i++ ){
         vector<sf::Sprite> foo;
      sprites[i] = foo;
    for(int k = 0; k < 5; k++){
        sf::Sprite sprite;
        sprite.setTexture(sheet);
        sprite.setTextureRect(sf::IntRect(k * 24, i * 24, 24, 24));
        sprites[i].push_back(sprite);

    }

}
//array determining time shifts
int benches[7] = {
100, 250, 100, 250, 100, 850, 4};
int autorelease = 50;
int nog = 100;
Grid mapper = Grid();
Ghost ghosts[4];
int section = 0;
ghosts[0] = Blinky();
ghosts[1] = Pinky();
ghosts[2] = Inky();
ghosts[3] = Clyde();
//using coors = pair<double, double>;
vector<tile>* matrix = mapper.getMap();
int nextdir = 0;
player Yow = player();
while(window.isOpen()){
sf::Event event;
       while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
           nextdir = 1;
           }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            nextdir = 2;
           }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            nextdir = 3;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            nextdir = 4;
        }
}

//checks if ajacent tiles are safe
  pair<int, int> cor = Yow.getPos();
  switch(nextdir){

  case 1:
      if(!matrix[cor.first - 1].at(32 - cor.second).getWall()){
        Yow.setDir(1);
      }
      else{
       // Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 2:
      if(!matrix[cor.first].at(32 - cor.second - 1).getWall()){
        Yow.setDir(2);
      }
      else{
        //Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 3:
    if(!matrix[cor.first + 1].at(32 - cor.second).getWall()){
        Yow.setDir(3);
      }
      else{
        //Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 4:
    if(!matrix[cor.first].at(32 - cor.second + 1).getWall()){
        Yow.setDir(4);
      }
      else{
        //Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  default:
    //Yow.setDir(0);
    //nextdir = 0;
    break;
  }

int curdir = Yow.getDir();

//stops player
 switch(curdir){

  case 1:
      if(matrix[cor.first - 1].at(32 - cor.second).getWall()){
       Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 2:
      if(matrix[cor.first].at(32 - cor.second - 1).getWall()){

        Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 3:
    if(matrix[cor.first + 1].at(32 - cor.second).getWall()){
        Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 4:
    if(matrix[cor.first].at(32 - cor.second + 1).getWall()){
        Yow.setDir(0);
        nextdir = 0;
      }
      break;
  default:
    //Yow.setDir(0);
    //nextdir = 0;
    break;
  }

//removes somekind of pellet
if(matrix[cor.first].at( 32 - cor.second).getPellet()){
    matrix[cor.first].at(32 - cor.second).setPellet(false);
}

runtime++;
//mode logic switch at time intervals
bool sw = false;
for(int i = 0; i < 7; i++){
    if(benches[i] != 0){
        if(benches[i] == runtime){
         runtime = 0;
         benches[i] = 0;
         bool sw = true;

    }
    section =  (i + 2) % 2;
    break;
}
else if(i == 6){

section = 1;

}
}

//Power pellet collision
pair<int, int> po = Yow.getPos();
if(matrix[po.first].at(32 - po.second).getPow()){
matrix[po.first].at(32 - po.second).setPow(false);
 for(int i = 0; i < 4; i++){
   ghosts[i].setFlee(true);
 }
sw = true;
}

//for determining inky loc
pair<double, double> red = ghosts[0].getLoc();

//code block determines ajacent boundaries of Ghost objevt
for(int k =0; k < 4; k++){
pair<double, double> carts = ghosts[k].getLoc();
bool safe[4];
for(int i = 0; i < 4; i++){
    safe[i] = false;
    int fi = round(carts.first);
    int si = round(carts.second);
switch(i){
case 0:
    if(matrix[fi - 1].at(si).getWall()){
        safe[i] = false;
       // cout << "blocked " << i << endl;
    }
    else { safe[i] = true; }
     break;
case 1:
      if(matrix[fi].at( si - 1 ).getWall()){
        safe[i] = false;
       // cout << "blocked " << i << endl;
    }
    else { safe[i] = true; }
    break;
case 2:
     if(matrix[fi + 1].at(si).getWall()){
        safe[i] = false;
       // cout << "blocked " << i << endl;
    }
    else { safe[i] = true; }
    break;
case 3:
     if(matrix[fi].at(si + 1).getWall()){
        safe[i] = false;
      //  cout << "blocked " << i << endl;
    }
    else { safe[i] = true; }
    break;
default:
    break;

}


}

ghosts[k].options(safe[0], safe[1], safe[2], safe[3]);

if( floor(carts.first) == floor(Yow.getPos().first) &&  floor((32 - carts.second)) == floor(Yow.getPos().second)){
    if(ghosts[k].getFlee() || ghosts[k].getDead()){
    ghosts[k].die();
}
else{
    for(int i = 0; i < 4; i++){
        ghosts[i].res();

    }
    Yow.die();
}
}
//prevent from going up

if(k == 0){
pair<double, double> argy = make_pair(27, 2);
if(ghosts[0].getM() && section == 1){
argy.first = Yow.getGrid().first;
argy.second = 32 - Yow.getGrid().second;
}
else{
argy.second = 30;
}
ghosts[0].AI(200,argy, sw );
}

else if(k == 1){
    pair<double, double> argy = make_pair(1, 2);
    if(ghosts[1].getM() && section == 1){
        double xchange = 0;
         double ychange = 0;
         int welp = Yow.getDir();
         switch(welp){
     case 0:
        ychange = -4;
        break;
     case 1:
        xchange =  - 4;
        break;
     case 2:
        ychange = 4;
        break;
     case 3:
        xchange = 4;
        break;
     case 4:
        ychange = -4;
        break;
     default:
        break;
        }
        argy.first =  Yow.getGrid().first + xchange;
        argy.second = 32 - Yow.getGrid().second + ychange;
        ghosts[1].AI( 200 , argy , sw );
    }
    else{
            argy.second = 30;
     ghosts[1].AI(200,argy, sw );
    }

}

 if(k == 2){
    pair<double, double> scat = make_pair(27, 30);
    if(ghosts[k].getM() && section == 1){
        double xchange = 0;
        double ychange = 0;
        int welp = Yow.getDir();
        pair<double, double> pac = Yow.getGrid();
         switch(welp){
       case 1:
        pac.first -= 2;
        break;
       case 2:
        pac.second -= 2;
        break;
       case 3:
        pac.first += 2;
        break;
       case 4:
        pac.second += 2;
        break;
       default:
        break;
         }
         xchange = pac.first - red.first;
         ychange = ( 32 - pac.second ) - red.second;
         pair<double, double> targ = make_pair(xchange + pac.first, 32 - pac.second  + ychange);
         ghosts[k].AI(200, targ, sw);

    }else{
        scat.second =  2;
      ghosts[k].AI(200, scat, sw);
    }
}
else if(k == 3){
 pair<double, double> def = make_pair(3, 30);
 if(ghosts[k].getM() && section == 1){
    pair<double, double> pac = Yow.getGrid();
    pair<double, double> gho = ghosts[k].getLoc();
    double detx = abs(gho.first - (pac.first));
    double dety = abs(gho.second - (32 - pac.second));
    double det = sqrt((detx * detx) + (dety * dety));
    if(det > 8){
           // cout << "orange dist" << det << endl;
        pac.second = 32 - pac.second;
        ghosts[k].AI(200, pac, sw);
    }
    else{
     def.second = 2;
    ghosts[k].AI(200, def, sw);
    }
 }
 else{
        def.second = 2;
    ghosts[k].AI(200, def, sw);
 }




}


}
Yow.traverse();
//Yow.setDir(0);
    //nextdir = 0;


window.clear();

for(int i = 0; i < 28; i++){
        int basey = 32;
    for(vector<tile>::iterator itor = matrix[i].begin(); itor != matrix[i].end(); ++itor){
        tile temp = *itor;
        sf::RectangleShape dot = temp.getIm();
        dot.setPosition((i * 16) + 4, (basey * 16) + 4);
        window.draw(dot);
        basey--;
    }
}
for(int i = 0; i < 4; i++){
    if(!ghosts[i].getBlank()){
    pair<double, double> carte = ghosts[i].getLoc();
    sf::CircleShape bon = ghosts[i].getIm();
    int frame = (runtime % 6)/2;
    int row = i;
    if(ghosts[i].getFlee()){
        row = 4;
    }
    if(!ghosts[i].getDead()){
    sprites[row].at(frame).setPosition(carte.first * 16, (32 - carte.second) * 16);
   // bon.setPosition(carte.first * 16, (32 - carte.second) * 16);
    window.draw(sprites[row].at(frame));
    }
    else{
          sprites[0].at(4).setPosition(carte.first * 16, (32 - carte.second) * 16);
   // bon.setPosition(carte.first * 16, (32 - carte.second) * 16);
    window.draw(sprites[0].at(4));
    }
    }
     sf::CircleShape lon = ghosts[i].getIm();
    pair<double, double> targ = ghosts[i].getSeek();
    lon.scale(.5, .5);
    lon.setPosition(targ.first * 16, (32 - targ.second) * 16);
    window.draw(lon);
}

pair<int, int> posse = Yow.getPos();

//power pellet logic


//pellet decrement
if(matrix[posse.first].at(32 - posse.second).getPellet()){
    matrix[posse.first].at(32 - posse.second).setPellet(false);
    mapper.eat();
   for(int n = 0; n < 4; n++){
      if(ghosts[n].getDead()){

        ghosts[n].decGP();

    }

   }
    for(int i = 1; i < 4; i++){

        if(ghosts[i].getPcount() > 0){
            ghosts[i].setPcount( (ghosts[i].getPcount() - 1));
            break;
        }

    }
   // cout << mapper.amount() << endl;
}
else{
    autorelease--;
    if(autorelease <= 0){
        autorelease = 50;
        for(int k = 0; k < 4; k++){
            if(!ghosts[k].getAc()){
                ghosts[k].setPcount(0);
                if(ghosts[k].getDead()){
                    while(ghosts[k].getGP() > 0){
                        ghosts[k].decGP();
                    }
                }
                break;
            }
        }
    }
}

if(Yow.getDir() == 1 &&  posse.first <= 2.5 && 32 - posse.second == 17){
    Yow.setPos(25.5, posse.second);
}
if(Yow.getDir() == 3 && posse.first >= 26.5 && 32 - posse.second == 17){
    Yow.setPos(2, posse.second);
}
sf::CircleShape blah = sf::CircleShape(4);
blah.setFillColor(sf::Color::Yellow);
for(int i = 0; i < Yow.getL(); ++i){
    blah.setPosition( i*10 + 80, 20);
    window.draw(blah);
}


int frame = (runtime % 4)/ 2;
if(frame == 0){
sprites[4].at(3).setPosition((Yow.getPac().getPosition()));
sprites[4].at(3).move(-10, -4);
window.draw(sprites[4].at(3));
}
else{
switch(Yow.getDir()){
case 1:
sprites[5].at(1).setPosition((Yow.getPac().getPosition()));
sprites[5].at(1).move(-10, -4);
window.draw(sprites[5].at(1));
break;
case 2:
    sprites[5].at(3).setPosition((Yow.getPac().getPosition()));
sprites[5].at(3).move(-10, -4);
window.draw(sprites[5].at(3));
break;
case 3:
sprites[5].at(0).setPosition((Yow.getPac().getPosition()));
sprites[5].at(0).move(-10, -4);
window.draw(sprites[5].at(0));
break;
case 4:
sprites[5].at(2).setPosition((Yow.getPac().getPosition()));
sprites[5].at(2).move(-10, -4);
window.draw(sprites[5].at(2));
break;
default:
sprites[4].at(3).setPosition((Yow.getPac().getPosition()));
sprites[4].at(3).move(-10, -4);
window.draw(sprites[4].at(3));
break;
    }
}
//window.draw(sprites[5].at(frame));
 sf::sleep(sf::milliseconds(80));
window.display();
}


return 0;
}
