#include "Grid.h"

Grid::Grid()
{
    grid = new vector<tile>[28];
    chase = false;
    flee = false;
    pellets = 0;
//32 long
for(int i = 0; i < 28; i++){
	vector<tile> temp;
	grid[i] = temp;
}
int row = 0;
while(row < 33){
	for(int i =0; i < 28; i++){
      tile blank = tile();
      grid[i].push_back(blank);
	}
	row++;
}
for(int i = 2; i < 14; i++){
	grid[i].at(3).wall();
	grid[i].at(29).wall();
}
grid[2].at(4).wall();
grid[25].at(4).wall();
grid[2].at(5).wall();
grid[2].at(6).wall();
for(int i = 4; i < 12; i++){
grid[i].at(5).wall();
grid[i].at(6).wall();
}
grid[13].at(5).wall();
grid[13].at(6).wall();
grid[2].at(7).wall();
grid[8].at(7).wall();
grid[9].at(7).wall();
grid[13].at(7).wall();
for(int i = 2; i < 5; i++){
grid[i].at(8).wall();
}

grid[6].at(8).wall();
grid[6].at(9).wall();
grid[8].at(8).wall();
grid[9].at(8).wall();
for(int i = 11; i < 14; i++){
	grid[i].at(8).wall();
	grid[i].at(18).wall();
}
grid[2].at(9).wall();
grid[6].at(9).wall();
grid[2].at(10).wall();
for(int i = 4; i < 7; i++){
	grid[i].at(10).wall();
	grid[i].at(11).wall();
}
for(int i = 8; i < 12; i++){
	grid[i].at(10).wall();
	grid[i].at(11).wall();
}
grid[13].at(10).wall();
grid[13].at(11).wall();
grid[2].at(12).wall();
grid[13].at(12).wall();
for(int i = 2; i < 7; i++){
	grid[i].at(13).wall();
	grid[i].at(16).wall();
	grid[i].at(18).wall();
	grid[i].at(21).wall();

}
for(int k = 13; k < 17; k++){
grid[8].at(k).wall();
grid[9].at(k).wall();
}

for(int i = 11; i < 14; i++){
	grid[i].at(13).wall();
	grid[i].at(15).wall();
	grid[i].at(16).wall();
	grid[i].at(23).wall();
	grid[i].at(24).wall();
	}
grid[6].at(14).wall();
grid[6].at(15).wall();
grid[6].at(19).wall();
grid[6].at(20).wall();
grid[11].at(17).wall();

for(int i = 18; i < 25; i++){
	grid[8].at(i).wall();
	grid[9].at(i).wall();
}
for(int i = 10; i < 12; i++){
	grid[i].at(20).wall();
	grid[i].at(21).wall();
}
for(int i = 20; i < 25; i++){
	grid[13].at(i).wall();
}

for(int i = 22; i < 30; i++){
	grid[2].at(i).wall();
}
grid[2].at(12).wall();
grid[2].at(11).wall();
for(int k = 4; k < 7; k++){
grid[k].at(23).wall();
grid[k].at(24).wall();
grid[k].at(26).wall();
grid[k].at(27).wall();
}
for(int k = 8; k < 12; k++){
grid[k].at(26).wall();
grid[k].at(27).wall();
}
for(int i = 26; i < 29; i++){
	grid[13].at(i).wall();
}

for(int i = 14; i < 28; i++){
	for(int k = 2; k < 31; k++){
	if(grid[27 - i].at(k).getWall()){
	grid[i].at(k).wall();
	}
}
}

for(int i = 2; i < 26; i++){
    for(int k = 3; k < 30; k++){
        if(!grid[i].at(k).getWall()){
            grid[i].at(k).setPellet(true);
            pellets++;
        }
    }
}
grid[3].at(9).setPow(true);
grid[24].at(9).setPow(true);
grid[3].at(26).setPow(true);
grid[24].at(26).setPow(true);

for(int i = 16; i < 18; i++){
    for(int k = 12; k < 16; k++){
        grid[k].at(i).setPellet(false);
        pellets--;
        grid[k].at(i).DeW();
    }
}

for(int i = 0; i < 5; i++){
    grid[i + 1].at(19).setPellet(false);
    grid[i + 1].at(20).setPellet(false);
    grid[22 + i].at(19).setPellet(false);
    grid[22 + i].at(20).setPellet(false);
    grid[i + 1].at(15).setPellet(false);
    grid[i + 1].at(14).setPellet(false);
    grid[22 + i].at(15).setPellet(false);
    grid[22 + i].at(14).setPellet(false);
}

pellets -= 29;
cout << pellets << endl;

grid[24].at(30).setPow(true);
grid[24].at(2).setPow(true);
grid[3].at(2).setPow(true);
grid[3].at(30).setPow(true);
    //ctor
}

Grid::~Grid()
{
    //dtor
}
