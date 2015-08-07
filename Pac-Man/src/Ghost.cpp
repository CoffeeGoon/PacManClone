#include "Ghost.h"

/*
ghost class that has 4 subclasses for each type
target tile logic remains the same for each ghost
unique aspects added progressively
*/

Ghost::Ghost()
{
    //the coordinate location of the collision point
    //representation * 16
    pos = make_pair(13,17);
    reset = 150;
    //most likely useless variable
    seek = make_pair(0, 0);
      twe = false;
    //checks for ajacent walls
    version = 0;
    //Global pellet counter
    GP = 0;

    nextMove = new bool[4];
    for(int i = 0; i < 4; i++){
        nextMove[i] = false;
    }
    stutter = 0;
    //determines inaction in the AI function
    pelletcount = 0;
    falter = 0;
    //the update factor of falter
    rate = 2;
    //chase and scatter modes
    mode = true;
    //lets ghost's out of the box
    active = false;
    //determines which direction is being faced
    curDir = 0;
    proto = sf::CircleShape(8);

    flee = false;
    //ctor

    dead = false;
}

void Ghost::res(int n = 0){
 active = false;
 pos.first = 13;
pos.second = 17;
pelletcount = 0;
if(n == 0){
dead = true;
}
if(n == 1){
    dead = false;
    flee = false;
    mode = true;
}

switch(version){
    case 1:
pos.first = 14;
if(n == 1){
    pelletcount = 0;
    GP = 20;
}
    break;
    case 2:
if(n == 1){
  pelletcount = 4;
   GP = 9;
   }
pos.first = 15;
    break;
    case 3:
 if(n == 1){
    pelletcount = 30;
    GP = 30;
 }
pos.first = 12;
    break;
    case 4:
    if(n == 1){
        pelletcount = 60;
        GP = 32;
    }
    break;
}

}

//function call to update wall collision
void Ghost::options(bool l, bool d, bool r, bool u){
  nextMove[0] = l;
  nextMove[1] = d;
  nextMove[2] = r;
  nextMove[3] = u;

}
/*unigue constructors for each class */
Pinky::Pinky():Ghost(){
proto.setFillColor(sf::Color( 255, 69 , 36));
pos.first += 2;
pelletcount = 4;
GP = 9;
version = 2;
}

Blinky::Blinky():Ghost(){
    proto.setFillColor(sf::Color::Red);
    pos.first += 1;
    pelletcount = 0;
    GP = 20;
    version = 1;
}

Inky::Inky():Ghost(){
proto.setFillColor(sf::Color::Cyan);
pos.first -= 1;
pelletcount = 30;
GP = 30;
version = 3;
}

Clyde::Clyde():Ghost(){
proto.setFillColor(sf::Color(255, 80, 0));
pelletcount = 60;
GP = 32;
version = 4;
}


//the control function
void Ghost::AI(int time, Coord& target, bool ch){
    if(flee){
            //logic related to flee mode
             reset--;
             if(reset == 0){
                reset = 150;
                 if(twe){
                    reset = 100;
                 }
                rate = 2;
                falter = 0;
                blank = false;
                flee = false;
             }

           }
    if(!active && pelletcount == 0){
            if(!dead){
            //activates maze release
        active = true;
        pos.first = 13;
        pos.second = 19;
            }
            else{
                rate = 2;
                reset = 150;
                if(twe){ reset = 150; }
                falter = 0;
                blank = false;
                flee = false;
                if(GP <= 0){
                    //global pellet reactivation
                    dead = false;
                    active = true;
                    pos.first = 13;
                    pos.second = 19;
                    switch(version){
                case 1:
                    GP = 4;
                    break;
                case 2:
                    GP = 7;
                    break;
                case 3:
                    GP = 17;
                    break;
                case 4:
                    GP = 32;
                    break;
                default:
                    break;
                    }
                }

            }
    }
    else if(active){
           // blank = false;
           seek.first = target.first;
           seek.second = target.second;
            //halves flee speed
           if(flee){ rate = 1;}

           //passage logic
if(curDir == 0 && pos.first <= 5 &&  pos.second == 17){
    rate = 1;
}
if(curDir == 2 && pos.first >= 20.5 && pos.second == 17){
    rate = 1;

}

             falter += rate;
              if(falter % 2 == 0){
                    rate = 2;
                    int paths = 0;
  for(int i = 0; i < 4; i++){
            if(nextMove[i]){ paths++;}
           // else if(curDir == i){ blank = true;}
  }

                     //angling slow
          if(paths < 3 && nextMove[curDir] == false){
            if(stutter % 2 == 0 && !twe){
            rate = 1;
          }
          else if(stutter % 3 == 0){
            rate = 1;
          }
          stutter++;
          }
            //counts all options



            bool subroutine = false;
            //only turns on whole numbers..
            if( pos.first == floor(pos.first) && pos.second == floor(pos.second)){
                subroutine = true;
            }
                 //reverses direction
                  if(nextMove[ ((curDir + 2) % 4)] == true){
                  if(ch){curDir = (curDir + 2) % 4;}
                  }

                 //makes reversing impossible
                nextMove[(curDir + 2) % 4] = false;

                if(dead && pos.first == 13 && pos.second  == 19){
                     //nextMove[(curDir + 2) % 4] = true;
                    // GP--;
                     active = false;
                     pos.first = 13;
                     pos.second = 17;
                     switch( version ){
                 case 1:
                     pos.first = 14;
                     break;
                 case 2:
                    pos.first = 15;
                    break;
                 case 3:
                    pos.first = 12;
                    break;
                     }
                }

                 //up barrier
                if( pos.first > 9 && pos.first < 19 && !dead ){
                    if( floor(pos.second) == 14 || floor(pos.second)  == 19){
                        nextMove[3] = false;
                    }
                }
                //spot to go back
                Coord respawn = make_pair(13, 19);


                 if( dead ){
                    target = respawn;
                 seek.first = target.first;
                 seek.second = target.second;
                 flee = false;
                 reset = 300;
                rate = 2;
                falter = 0;
                blank = false;
                 }
              //distance values that are past a feasible limit for each adjacent tile
            double du = 900;
            double dd = 900;
            double dl = 900;
            double dr = 900;
            double least = 900;
            //picks shortest path to target
           if( subroutine && !flee){
                if(nextMove[3]){
            Coord upper = make_pair(pos.first, pos.second + 1);
            du = floor(distance(upper, target));
            if(du < least){
                least = du;
                curDir = 3;
            }
        }
         if(nextMove[1]){
        Coord downer = make_pair(pos.first , pos.second - 1);
        dd  = floor(distance(downer, target));
        if(dd < least){
            least = dd;
            curDir = 1;
        }
        }
        if(nextMove[0]){
        Coord lefter = make_pair(pos.first - 1 , pos.second);
        dl = floor(distance(lefter, target));
        if(dl < least){
            least = dl;
            curDir = 0;
        }
        }
        if(nextMove[2]){
            Coord righter = make_pair(pos.first + 1, pos.second);
            dr = floor(distance(righter, target));
            if(dr < least){
                least = dr;
                curDir = 2;
            }
        }


           }
           if( flee && pos.first == floor(pos.first) && pos.second == floor(pos.second) && ((paths > 2) || nextMove[curDir] == false) ){
            int possible = rand() % 4;
            while(!nextMove[possible]){
                possible = (possible + 1) % 4;
            }
            curDir = possible;
           }




         if(falter % 2 == 0 && !blank){
      switch(curDir){
  case 0:
    pos.first -= .50;
    break;
  case 1:
    pos.second -= .5;
    break;
  case 2:
    pos.first += .5;
    break;
  case 3:
    pos.second += .5;
    break;
  default:
    break;
      }

    }


blank = false;



if(curDir == 0 && pos.first <= 1.5 &&  pos.second == 17){
        blank = true;
        rate = 1;
    pos.first = 25.5;
    pos.second = 17;
}
if(curDir == 2 && pos.first >= 25.5 && pos.second == 17){
    blank = true;
    rate = 1;
    pos.first = 2;

}
}
    }
}




Ghost::~Ghost()
{
    //dtor
}


