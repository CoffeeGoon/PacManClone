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

Grid::Grid(int n){
if(n == 1){
  grid = new vector<tile>[65];
    chase = false;
    flee = false;
    pellets = 0;
    for(int i = 0; i < 65; i++){
        vector<tile> temp;
        grid[i] = temp;
        for(int k = 0; k < 67; k++){
            tile temp;
            grid[i].push_back(temp);
        }
    }

    for(int k = 19; k < 23; k++){
        grid[1].at(k).wall();
    }
    for(int k = 29; k < 39; k++){
        grid[1].at(k).wall();
    }
    grid[2].at(19).wall();
    grid[2].at(22).wall();
    grid[2].at(29).wall();
    for(int k = 39; k < 48; k++){
        grid[2].at(k).wall();
    }
    for(int i = 17; i < 19; i++){
        grid[3].at(i).wall();
    }
    grid[3].at(21).wall();
    grid[3].at(23).wall();
    grid[3].at(29).wall();
    grid[3].at(31).wall();
    for(int i = 33; i < 38; i++){
        grid[3].at(i).wall();
    }

    for(int i = 48; i < 53; i++){
        grid[3].at(i).wall();
    }

    grid[4].at(17).wall();
    grid[4].at(21).wall();
    for(int i = 23; i < 30; i++){
        grid[4].at(i).wall();
    }
    grid[4].at(31).wall();
    for(int i = 33; i < 42; i++){

    }
    for(int i = 43; i < 47; i++){
        grid[4].at(i).wall();
    }


    grid[4].at(48).wall();
    grid[4].at(52).wall();
    grid[5].at(17).wall();
    grid[5].at(19).wall();
    grid[5].at(23).wall();
    grid[5].at(25).wall();
    grid[5].at(27).wall();
    for(int i = 29; i < 31; i++){
         grid[5].at(i).wall();
    }
    grid[5].at(40).wall();
    grid[5].at(41).wall();
    for(int i = 43; i < 47; i++){
        grid[5].at(i).wall();
        grid[6].at(i).wall();
    }
    for(int i = 48; i < 50; i++){
      grid[5].at(i).wall();
    }
    grid[5].at(52).wall();
    for(int i = 6; i < 15; i++){
      grid[i].at(17).wall();
      if(i < 13){
        grid[i].at(19).wall();
    }
    }

    for(int i = 21; i < 23; i++){
       grid[6].at(i).wall();
    }

    grid[6].at(25).wall();
    grid[6].at(27).wall();
    for(int i = 29; i < 33; i++){
        grid[6].at(i).wall();
    }
    grid[6].at(35).wall();
    grid[6].at(37).wall();
    grid[6].at(39).wall();
    grid[6].at(40).wall();
    grid[6].at(41).wall();
    for(int i = 6; i < 12; i++){
      grid[i].at(50).wall();
      grid[i].at(52).wall();
    }
    grid[7].at(25).wall();
    grid[7].at(27).wall();
    for(int i = 29; i < 33; i++){
        grid[7].at(i).wall();
    }
    grid[7].at(35).wall();
    for(int i = 7; i < 35; i++){
       grid[i].at(37).wall();
       grid[i].at(38).wall();
    }
    grid[7].at(40).wall();
    grid[7].at(41).wall();
    grid[7].at(48).wall();
    for(int i = 21; i < 25; i++){
        grid[8].at(i).wall();
        grid[9].at(i).wall();
        if(i > 21){ grid[10].at(i).wall(); }
    }

    grid[8].at(27).wall();
    for(int i = 31; i < 33; i++){
     grid[8].at(i).wall();
     grid[9].at(i).wall();
     grid[10].at(i).wall();
    }
    for(int i = 8; i < 13; i++){
      grid[35].at(i).wall();
    }
    grid[8].at(41).wall();
    grid[8].at(42).wall();

    for(int i = 44; i < 46; i++){
     grid[8].at(i).wall();
     grid[10].at(i).wall();
    }
    for(int i = 22; i < 25; i++){
     grid[10].at(i).wall();
     grid[12].at(i).wall();
     grid[25].at(i).wall();
     for(int k = 18; k < 24; k++){
      grid[k].at(i).wall();
    }

    }

for(int i = 27; i < 29; i++){
   grid[9].at(i).wall();
   grid[14].at(i).wall();
   grid[15].at(i).wall();
   grid[28].at(i).wall();
   grid[33].at(i).wall();
   for(int k = 21; k < 27; k++){
    grid[k].at(i).wall();
   }

}
grid[9].at(39).wall();
grid[9].at(48).wall();
for(int i = 58; i < 61; i++){
 grid[9].at(i).wall();
 grid[10].at(i).wall();
 grid[11].at(i).wall();
 grid[18].at(i).wall();
}
for(int i = 39; i < 42; i++){
   grid[10].at(i).wall();
   grid[11].at(i).wall();
   grid[12].at(i).wall();
   grid[14].at(i).wall();
   grid[15].at(i).wall();
}

grid[10].at(48).wall();
for(int i = 11; i < 18; i++){
    grid[i].at(20).wall();
}
grid[11].at(27).wall();
grid[11].at(29).wall();
grid[11].at(44).wall();
for(int i = 52; i < 57; i++){
    grid[11].at(i).wall();
    grid[13].at(i).wall();
    grid[14].at(i).wall();
    grid[15].at(i).wall();
}

for( int i = 4; i < 15; i++){
  grid[12].at(i).wall();
}
grid[12].at(26).wall();
grid[12].at(27).wall();

for( int i = 29; i <  32; i++){
  grid[12].at(i).wall();
}
grid[12].at(36).wall();
grid[12].at(37).wall();
grid[12].at(44).wall();
grid[12].at(46).wall();
grid[12].at(48).wall();
grid[12].at(61).wall();
grid[13].at(4).wall();
for(int i = 15; i < 18; i++){
 grid[13].at(i).wall();
 grid[15].at(i).wall();
 grid[16].at(i).wall();
 grid[19].at(i).wall();
 grid[25].at(i).wall();
}
grid[13].at(46).wall();
grid[14].at(46).wall();
for(int i = 13; i < 16; i++){
 grid[i].at(48).wall();
 grid[i].at(50).wall();
 grid[i].at(51).wall();
 grid[i].at(59).wall();
 grid[i].at(61).wall();
}
for(int i = 14; i <  17; i++){
 grid[i].at(4).wall();

}
for( int i = 8; i < 13; i++){
 grid[14].at(i).wall();
 grid[15].at(i).wall();
 grid[16].at(i).wall();
}
for(int i = 14; i < 17; i++){
 grid[i].at(22).wall();
 grid[i].at(24).wall();
 grid[i].at(25).wall();
 grid[i].at(26).wall();
}

for(int i = 30; i <  32; i++){
  grid[14].at(i).wall();
}

for(int i = 14; i < 21; i++){
    grid[34].at(i).wall();
    grid[35].at(i).wall();
    grid[36].at(i).wall();
    grid[37].at(i).wall();
}

for(int i = 14; i < 21; i++){
 grid[i].at(44).wall();
 grid[i].at(45).wall();
}
for(int i = 15; i < 19; i++){
 grid[i].at(6).wall();
 if(i != 18){
    grid[i].at(19).wall();
 }
}

for(int i = 16; i < 21; i++){
 grid[i].at(3).wall();
}
grid[18].at(5).wall();

for(int i = 18; i < 21; i++){
 grid[i].at(12).wall();
 grid[i + 3].at(12).wall();
 grid[i + 3].at(13).wall();
  grid[i + 3].at(14).wall();
}
grid[18].at(14).wall();
grid[19].at(14).wall();
grid[18].at(15).wall();
grid[19].at(16).wall();
grid[17].at(18).wall();
for(int i = 16; i < 22; i++){
for(int j = 19; j < 24; j++){
 grid[j].at(i).wall();
}
}
for(int i = 24; i < 26; i++){
    grid[17].at(i).wall();
}
for(int i = 16; i < 20; i++){
  grid[i].at(31).wall();
  grid[i].at(32).wall();
  grid[i].at(33).wall();
}

for(int i =17; i < 21; i++){
 grid[i].at(38).wall();
 grid[i].at(39).wall();
 grid[i].at(40).wall();
 grid[i].at(42).wall();
 grid[i].at(43).wall();
}

for(int i = 16; i < 20; i++){
grid[54].at(i).wall();
}

grid[16].at(47).wall();
grid[16].at(48).wall();
grid[16].at(59).wall();
grid[16].at(61).wall();
grid[17].at(61).wall();
grid[19].at(26).wall();
grid[18].at(26).wall();

for(int i = 17; i < 20; i++){
 grid[i].at(28).wall();
 grid[i].at(29).wall();
 grid[i].at(30).wall();
}

for(int i = 17; i < 19; i++){
 grid[i].at(47).wall();
 grid[i].at(50).wall();
 grid[i].at(52).wall();
 grid[i].at(56).wall();
 grid[i].at(57).wall();
}
grid[18].at(8).wall();
grid[18].at(9).wall();
grid[18].at(10).wall();
grid[18].at(26).wall();
grid[19].at(26).wall();
grid[20].at(33).wall();
grid[19].at(50).wall();
grid[20].at(50).wall();
grid[19].at(52).wall();
grid[20].at(52).wall();
grid[19].at(56).wall();
for(int i = 56; i < 60; i++){
 grid[20].at(i).wall();
 grid[24].at(i).wall();
}

for(int i = 22; i < 25; i++){
 grid[i].at(60).wall();
 grid[i].at(54).wall();
 grid[i].at(52).wall();
 grid[i].at(10).wall();
 for(int k = 42; k < 49; k++){
  grid[i].at(k).wall();
 }
}

for(int i = 56; i < 58; i++){
 grid[22].at(i).wall();
}
for(int i = 47; i < 49; i++){
 grid[20].at(i).wall();
}

for(int i = 3; i < 8; i++){
 grid[20].at(i).wall();
}

grid[19].at(8).wall();
grid[19].at(10).wall();
grid[20].at(11).wall();
grid[21].at(12).wall();
grid[25].at(10).wall();
grid[25].at(11).wall();
grid[25].at(13).wall();
grid[25].at(14).wall();
grid[25].at(19).wall();
for(int i = 21; i < 27; i++){
 grid[i].at(30).wall();
 grid[i].at(31).wall();
}
for(int i = 33; i < 37; i++){
 grid[21].at(i).wall();
 grid[22].at(i).wall();
}
for(int i = 32; i < 36; i++){
 grid[24].at(i).wall();
 grid[25].at(i).wall();
 grid[26].at(i).wall();
}
for(int i = 22; i < 27; i++){
    grid[i].at(38).wall();
}
grid[22].at(39).wall();
grid[23].at(40).wall();
grid[25].at(10).wall();
grid[25].at(11).wall();
grid[25].at(13).wall();
grid[25].at(14).wall();
grid[25].at(19).wall();
grid[24].at(40).wall();
grid[24].at(41).wall();
for(int i = 40; i < 50; i++){
 for(int j = 25; j < 29; j++){
  grid[j].at(i).wall();
 }
}
for(int i = 26; i <  31; i++){
 grid[i].at(11).wall();
 if(i > 27){ grid[i].at(13).wall(); }
}
for(int i = 26; i < 28; i++){
   grid[i].at(15).wall();
   grid[i].at(16).wall();
}
for(int i = 27; i < 31; i++){
for(int k = 18; k < 21; k++){
 grid[i].at(k).wall();
}
grid[i].at(24).wall();
grid[i].at(25).wall();
}
grid[26].at(24).wall();
grid[26].at(25).wall();
grid[26].at(54).wall();
grid[27].at(55).wall();
grid[28].at(56).wall();
for(int i = 25; i < 29; i++){
 grid[i].at(56).wall();
}
grid[30].at(14).wall();
grid[30].at(15).wall();
grid[30].at(16).wall();
grid[29].at(27).wall();
grid[30].at(27).wall();
grid[28].at(30).wall();
grid[29].at(30).wall();
grid[30].at(30).wall();
grid[29].at(32).wall();
grid[30].at(32).wall();
for(int i = 32; i < 38; i++){
    grid[28].at(i).wall();
}
grid[30].at(14).wall();
grid[30].at(15).wall();
grid[31].at(16).wall();
grid[29].at(27).wall();
grid[30].at(28).wall();
grid[29].at(32).wall();
grid[30].at(32).wall();
for(int i = 34; i < 49; i++){
 if(i % 3 == 0){

 }
 else{
   grid[30].at(i).wall();
 }
}
for(int i = 49; i < 52; i++){
 grid[30].at(i).wall();
}
grid[30].at(54).wall();
grid[31].at(54).wall();
grid[30].at(55).wall();
grid[31].at(55).wall();
for(int i = 28; i < 30; i++){
 grid[i].at(57).wall();
}
for(int i = 31; i < 61; i++){
 for(int j = 0; j < 62; j++){
    if(grid[61 - i].at(j).getWall()){
     grid[i].at(j).wall();
    }
    else{
     //grid[i].at(j).setPellet(true);
     //grid[61 - i].at(j).setPellet(true);
    }
 }
}

}
}

void Grid::reset(){
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

}
Grid::~Grid()
{
    for(int i = 0; i < 28; i++){
        grid[i].clear();
    }
    delete grid;
    //dtor
}
