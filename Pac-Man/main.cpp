
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
int gtime = 0;
sf::Font font;
font.loadFromFile("impact.ttf");
sf::Text message;
sf::Text title;
sf::Text taine;
taine.setFont(font);
taine.setCharacterSize(40);
taine.setColor(sf::Color::White);
taine.setString("PAC-CLONE-MK.C");
taine.setPosition(100, 100);
int score = 0;
int level = 1;
bool snack = false;
bool intro = true;
bool zistion = false;
message.setFont(font);
message.setString("Game Over");
message.setCharacterSize(50);
message.setColor(sf::Color::White);
message.setPosition(300, 50);

//sounds
sf::Sound sounds[6];
sf::SoundBuffer sn;
sf::SoundBuffer sa;
sf::SoundBuffer sq;
sf::SoundBuffer sw;
sf::SoundBuffer sr;
sn.loadFromFile("SFX_Pacman/Pacman_Opening_Song.wav");
sounds[0] = sf::Sound(sn);
sa.loadFromFile("SFX_Pacman/Pacman_Waka_Waka.wav");
sounds[1] = sf::Sound(sa);
sq.loadFromFile("SFX_Pacman/Pacman_Eating_Ghost.wav");
sounds[2] = sf::Sound(sq);
sw.loadFromFile("SFX_Pacman/Pacman_Dies.wav");
sounds[3] = sf::Sound(sw);
sr.loadFromFile("SFX_Pacman/Intermission.wav");
sounds[4] = sf::Sound(sr);
sf::SoundBuffer dr;
dr.loadFromFile("SFX_Pacman/Pacman_Siren.wav");
sounds[5] = sf::Sound(dr);

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

//4 sec ghost release
int autorelease = 50;
int nog = 100;
//sound offset
int deli = 13;
Grid mapper = Grid();
Ghost ghosts[4];
int section = 0;
ghosts[0] = Blinky();
ghosts[1] = Pinky();
ghosts[2] = Inky();
ghosts[3] = Clyde();
 int xp = 200;
 int dx = 0;
 int yp = 200;
 int dy = 0;
//using coors = pair<double, double>;
vector<tile>* matrix = mapper.getMap();
int nextdir = 0;
player Yow = player();
sounds[5].play();
sounds[5].setLoop(true);
sounds[0].play();
while(window.isOpen()){
sf::Event event;
       while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        }
       if(!intro){
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
       if(intro && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        intro = false;
        level = 1;
        sounds[0].play();
       }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && level == 2){
            zistion = true;
            Yow.setPos(13, 18);
            Yow.setDir(0);
            nextdir = 0;

        }
}
if(zistion && level == 2){
 pair<int, int> cor = Yow.getPos();
 //reversed direction logic for walls
  switch(nextdir){
    case 1:
      if(!matrix[cor.first].at(32 - cor.second + 1).getWall()){
        Yow.setDir(4);
      }
      else{
       // Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 2:
      if(!matrix[cor.first + 1].at(32 - cor.second).getWall()){
        Yow.setDir(3);
      }
      else{
        //Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 3:
    if(!matrix[cor.first].at(32 - cor.second - 1).getWall()){
        Yow.setDir(2);
      }
      else{
        //Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 4:
    if(!matrix[cor.first - 1].at( 32 - cor.second).getWall()){
        Yow.setDir(1);
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
  if(curdir == 4){
    curdir = 1;
  }
  else if(curdir == 3){
    curdir = 2;
  }
  else if(curdir == 2){
    curdir = 3;
  }
  else if(curdir == 1){
    curdir = 4;
  }


//more ajacent wall blocking in reverse

switch(curdir){

  case 1:
      if(matrix[cor.first].at(32 - cor.second + 1).getWall()){
       Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 2:
      if(matrix[cor.first + 1].at(32 - cor.second).getWall()){

        Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 3:
    if(matrix[cor.first].at(32 - cor.second - 1).getWall()){
        Yow.setDir(0);
        //nextdir = 0;
      }
      break;
  case 4:
    if(matrix[cor.first - 1].at(32 - cor.second ).getWall()){
        Yow.setDir(0);
        nextdir = 0;
      }
      break;
  default:
    //Yow.setDir(0);
    //nextdir = 0;
    break;
  }


 runtime++;

 if(matrix[cor.first].at( 32 - cor.second).getPellet()){
    matrix[cor.first].at(32 - cor.second).setPellet(false);
}

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

pair<int, int> po = Yow.getPos();
if(matrix[po.first].at(32 - po.second).getPow()){
matrix[po.first].at(32 - po.second).setPow(false);
 for(int i = 0; i < 4; i++){
   ghosts[i].setFlee(true);
 }
sw = true;
}

//not altered yet
//for determining inky loc
pair<double, double> red = ghosts[0].getLoc();

bool reset = false;
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

if( floor(carts.first) == floor(Yow.getPos().first) &&  floor((32 - carts.second)) == floor(Yow.getPos().second) ||
    ( abs(carts.first - Yow.getPos().first) < 1 && abs((32 - carts.second) - Yow.getPos().second) < 1 ) ){
    if(ghosts[k].getFlee() || ghosts[k].getDead()){
    ghosts[k].die();
    score += 50;
    sounds[2].play();
}
else{
reset = true;
    sounds[3].play();
    Yow.die();
}
}
//prevent from going up

if(k == 0){
pair<double, double> argy = make_pair(2, 27);
if(ghosts[0].getM() && section == 1 || mapper.amount() < 20){
argy.first = Yow.getGrid().first;
argy.second = 32 - Yow.getGrid().second;
}
else{
argy.second = 30;
}
ghosts[0].AI(200,argy, sw );
}

else if(k == 1){
    pair<double, double> argy = make_pair(2, 1);
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
        ychange = - 4;
        break;
     case 3:
        xchange = 4;
        break;
     case 4:
        ychange = 4;
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
    pair<double, double> scat = make_pair(30, 27);
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
if(reset){
     for(int i = 0; i < 4; i++){
        ghosts[i].res(0);

    }
}

}
if(!intro && level == 1){

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

bool reset = false;
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

if( floor(carts.first) == floor(Yow.getPos().first) &&  floor((32 - carts.second)) == floor(Yow.getPos().second) ||
    ( abs(carts.first - Yow.getPos().first) < 1 && abs((32 - carts.second) - Yow.getPos().second) < 1 ) ){
    if(ghosts[k].getFlee() || ghosts[k].getDead()){
    ghosts[k].die();
    score += 50;
    sounds[2].play();
}
else{
reset = true;
    sounds[3].play();
    Yow.die();
}
}
//prevent from going up

if(k == 0){
pair<double, double> argy = make_pair(27, 2);
if(ghosts[0].getM() && section == 1 || mapper.amount() < 20){
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
        ychange = - 4;
        break;
     case 3:
        xchange = 4;
        break;
     case 4:
        ychange = 4;
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
if(reset){
     for(int i = 0; i < 4; i++){
        ghosts[i].res(0);

    }
}
}
window.clear();
if(Yow.getL() > 0 && level == 1 && !intro){
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
    sprites[row].at(frame).setPosition(carte.first * 16 -4, (32 - carte.second) * 16 -4);
   // bon.setPosition(carte.first * 16, (32 - carte.second) * 16);
    window.draw(sprites[row].at(frame));
    }
    else{
    sprites[row].at(frame).setPosition(carte.first * 16 - 4, (32 - carte.second) * 16 - 4);
    sprites[0].at(3).setPosition(carte.first * 16 - 4, (32 - carte.second) * 16 - 4);
   // bon.setPosition(carte.first * 16, (32 - carte.second) * 16);
     if(carte.second != 17 || carte.first < 11 || carte.first > 16){
    window.draw(sprites[0].at(3));
     }
     else{
         window.draw(sprites[row].at(frame));
     }
    }
    }
     sf::CircleShape lon = ghosts[i].getIm();
    pair<double, double> targ = ghosts[i].getSeek();
    lon.scale(.5, .5);
    lon.setPosition(targ.first * 16 - 4, (32 - targ.second) * 16 - 4);
   // window.draw(lon);
}

pair<int, int> posse = Yow.getPos();

//power pellet logic


//pellet decrement
if(matrix[posse.first].at(32 - posse.second).getPellet()){
    matrix[posse.first].at(32 - posse.second).setPellet(false);
    mapper.eat();
    //if(sounds[1].Stopped ){
      //  snack = false;
    //}
        if(!snack){
        sounds[1].play();
        sounds[1].setLoop(true);
        snack = true;
        }
        deli = 13;

    score += 10;
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
    deli--;
    if(deli <= 0){
    sounds[1].stop();
    snack = false;
    deli = 13;
    }
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

if(Yow.getDir() == 1 &&  posse.first <= 2 && 32 - posse.second == 17){
    Yow.setPos(25, posse.second);
}
if(Yow.getDir() == 3 && posse.first >= 25 && 32 - posse.second == 17){
    Yow.setPos(2, posse.second);
}
sf::CircleShape blah = sf::CircleShape(4);
blah.setFillColor(sf::Color::Yellow);
for(int i = 0; i < Yow.getL(); ++i){
    blah.setPosition( i*10 + 80, 20);
    window.draw(blah);
}
stringstream sr;
sr << score;
sf::Text sc;
sc.setFont(font);
sc.setString(sr.str());
sc.setCharacterSize(20);
sc.setColor(sf::Color::White);
sc.setPosition(150, 10);
window.draw(sc);


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
}
else if( Yow.getL() < 1 && level > 0){
level = -1;
runtime = 0;
score = 0;
 snack = false;
 intro = true;
zistion = false;
for(int i = 0; i < 28; i++){
        matrix[i].clear();
}
      //delete matrix;
      mapper.reset();
     matrix = mapper.getMap();
//array determining time shifts
benches[0] = 100;
benches[1] = 250;
benches[2] = 100;
benches[3] = 250;
benches[4] = 100;
benches[5] = 850;
benches[6] = 4;
//4 sec ghost release
autorelease = 50;
nog = 100;
//sound offset
deli = 13;
Yow.rehash();
for(int i = 0; i < 4; i++){
    ghosts[i].res(1);
    ghosts[i].detw();
}

}

if(level == -1){
    window.draw(message);
}
if(mapper.amount() < 2 && level == 1){
  level = 2;
  sounds[4].play();
}
if(mapper.amount() < 2 && level == 2 && zistion){
    level = 1;
    zistion = false;
    intro = true;
    benches[0] = 70;
     benches[1] = 250;
     benches[2] = 70;
     benches[3] = 250;
     benches[4] = 70;
     benches[5] = 850;
     benches[6] = 4;
     autorelease = 50;
     deli = 13;
     Yow.setPos(13, 18);
    Yow.setDir(0);
    nextdir = 0;
    runtime = 0;
    deli = 13;
    autorelease = 50;
     for(int i = 0; i < 4; i++){
            ghosts[i].res(1);
            ghosts[i].tweak();
     }
     for(int i = 0; i < 28; i++){
        matrix[i].clear();
     }
     mapper.reset();
     matrix = mapper.getMap();

}
if((level == 2 && !zistion) || intro){

//level 2 view output
    if(level == 2){
     benches[0] = 70;
     benches[1] = 250;
     benches[2] = 70;
     benches[3] = 250;
     benches[4] = 70;
     benches[5] = 850;
     benches[6] = 4;
     autorelease = 50;
     deli = 13;
     Yow.setPos(13, 18);
    Yow.setDir(0);
    nextdir = 0;
    runtime = 0;
    deli = 13;
    autorelease = 50;
     for(int i = 0; i < 4; i++){
            ghosts[i].res(1);
            ghosts[i].tweak();
     }
     for(int i = 0; i < 28; i++){
        matrix[i].clear();
     }
     mapper.reset();
     matrix = mapper.getMap();
    }

    window.draw(taine);
    int ref = gtime % 182;
    int r;
    if(ref < 65){
        dx++;
        r = 3;
    }
    if(ref >= 65 && ref < 84 ){
        dy++;
        r = 2;
    }
    if(ref >= 84 && ref < 149){
        dx--;
        r = 1;
    }
    if(ref >= 149){
        dy--;
        r = 4;
    }
    for(int i = 1; i < 5; i++){
     int frame = (gtime % 6)/2;
    int row = i - 1;
    int sett = 10;
    if(i > 2){
        sett = -10;
    }
    sprites[row].at(frame).setPosition(xp - (i * sett) + dx, yp  +  dy);
    window.draw( sprites[row].at(frame) );
    }

int frame = (runtime % 4)/ 2;
if(frame == 0){
sprites[4].at(3).setPosition(dx + xp + 10, dy + yp);
window.draw(sprites[4].at(3));
}
else{
switch(r){
case 1:
sprites[5].at(1).setPosition(dx + xp + 10, dy + yp);
window.draw(sprites[5].at(1));
break;
case 2:
sprites[5].at(3).setPosition(dx + xp + 10, dy + yp);
window.draw(sprites[5].at(3));
break;
case 3:
sprites[5].at(0).setPosition(dx + xp + 10, dy + yp);
window.draw(sprites[5].at(0));
break;
case 4:
sprites[5].at(2).setPosition(dx + xp + 10, dy + yp);
window.draw(sprites[5].at(2));
break;
default:
sprites[4].at(3).setPosition(dx + xp + 10, dy + yp);
window.draw(sprites[4].at(3));
break;
    }
}


}
if(level == 2 && zistion && Yow.getL() > 0){
  for(int i = 0; i < 28; i++){
        int basey = 32;
    for(vector<tile>::iterator itor = matrix[i].begin(); itor != matrix[i].end(); ++itor){
        tile temp = *itor;
        sf::RectangleShape dot = temp.getIm();
        dot.setPosition((basey * 16) + 4, (i * 16) + 4);
        window.draw(dot);
        basey--;
    }
}


pair<int, int> posse = Yow.getPos();

//power pellet logic


//pellet decrement
if(matrix[posse.first].at(32 - posse.second).getPellet()){
    matrix[posse.first].at(32 - posse.second).setPellet(false);
    mapper.eat();
    //if(sounds[1].Stopped ){
      //  snack = false;
    //}
        if(!snack){
        sounds[1].play();
        sounds[1].setLoop(true);
        snack = true;
        }
        deli = 13;

    score += 10;
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
    deli--;
    if(deli <= 0){
    sounds[1].stop();
    snack = false;
    deli = 13;
    }
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

if(Yow.getDir() == 1 &&  posse.first <= 2 && 32 - posse.second == 17){
    Yow.setPos(25, posse.second);
}
if(Yow.getDir() == 3 && posse.first >= 25 && 32 - posse.second == 17){
   Yow.setPos(2, posse.second);
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
    sprites[row].at(frame).setPosition( (32 - carte.second) * 16 - 4, carte.first * 16 - 4 );
   // bon.setPosition(carte.first * 16, (32 - carte.second) * 16);
    window.draw(sprites[row].at(frame));
    }
    else{
        sprites[row].at(frame).setPosition( (32 - carte.second) * 16 - 4, carte.first * 16 - 4);
   // sprites[row].at(frame).setPosition(carte.first * 16 - 4, (32 - carte.second) * 16 - 4);
   sprites[0].at(3).setPosition( (32 - carte.second) * 16 - 4, carte.first * 16 - 4);
//sprites[0].at(3).setPosition(carte.first * 16 - 4, (32 - carte.second) * 16 - 4);
   // bon.setPosition(carte.first * 16, (32 - carte.second) * 16);
     if(carte.second != 17 || carte.first < 11 || carte.first > 16){
    window.draw(sprites[0].at(3));
     }
     else{
         window.draw(sprites[row].at(frame));
     }
    }
    }
     sf::CircleShape lon = ghosts[i].getIm();
    pair<double, double> targ = ghosts[i].getSeek();
    lon.scale(.5, .5);
    lon.setPosition( (32 - targ.second) * 16 - 4, targ.first * 16 - 4);
//    window.draw(lon);
}

sf::CircleShape blah = sf::CircleShape(4);
blah.setFillColor(sf::Color::Yellow);
for(int i = 0; i < Yow.getL(); ++i){
    blah.setPosition( i*10 + 80, 20);
    window.draw(blah);
}
stringstream sr;
sr << score;
sf::Text sc;
sc.setFont(font);
sc.setString(sr.str());
sc.setCharacterSize(20);
sc.setColor(sf::Color::White);
sc.setPosition(150, 10);
window.draw(sc);

sf::Vector2f location = Yow.getPac().getPosition();
float swx = location.x;
float swy = location.y;

int frame = (runtime % 4)/ 2;
if(frame == 0){
sprites[4].at(3).setPosition(swy, swx);
sprites[4].at(3).move(-4, -10);
window.draw(sprites[4].at(3));
}
else{
switch(Yow.getDir()){
case 2:
sprites[5].at(1).setPosition(swy, swx);
sprites[5].at(1).move(-4, -10);
window.draw(sprites[5].at(1));
break;
case 3:
    sprites[5].at(3).setPosition(swy, swx);
sprites[5].at(3).move(-4, -10);
window.draw(sprites[5].at(3));
break;
case 4:
sprites[5].at(0).setPosition(swy, swx);
sprites[5].at(0).move(-4, -10);
window.draw(sprites[5].at(0));
break;
case 1:
sprites[5].at(2).setPosition(swy, swx);
sprites[5].at(2).move(-4, -10);
window.draw(sprites[5].at(2));
break;
default:
sprites[4].at(3).setPosition(swy, swx);
sprites[4].at(3).move(-4, -10);
window.draw(sprites[4].at(3));
break;
    }
}



}



cout << mapper.amount() << endl;
//window.draw(sprites[5].at(frame));
 sf::sleep(sf::milliseconds(80));
 gtime++;

window.display();
}


return 0;
}
