#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

struct Map {int wid, height,fruitx,fruity ;};
struct snake{int headx ,heady,tail_n, Dir;};
struct player{int score; bool lose;};
//-------------------------------------------//
Map map1 ;snake snake1 ;player player1;

void fruit(){

    srand(time(NULL));
    map1.fruitx=(rand()%(map1.wid-2)+1);
    map1.fruity=(rand()%(map1.height-2)+1);

}
void setup()
{

    srand(time(NULL));
    map1.wid=40;
    map1.height=20;
    snake1.headx=10;
    snake1.heady=10;
    player1.score=0;
    player1.lose=false;
    fruit();

}


void drawMap()
{
    system("cls");


  for(int i =0;i<map1.height;i++)
{
    for(int j=0;j<map1.wid;j++)
       {
        if(i==0||i==map1.height-1)
             cout<<"-";
        else if (j==0||j==map1.wid-1)
            cout<<"|";

        else if (i==snake1.heady&&j==snake1.headx)
        cout<<"C";
        else if (i==snake1.heady&&j==snake1.headx+1)
            cout<<":";
        else if (i==map1.fruity&&j==map1.fruitx)
        cout<<"o";
        else
            cout<<" ";

       }
     cout<<endl;

}



}

void DIR()
{
    if(_kbhit())
    {
        char d=_getch();



            if (d=='w')
            {
                snake1.Dir=1;
            }
            else if (d=='s')
            {
                snake1.Dir=2;
            }
            else if (d=='d')
            {
                snake1.Dir=3;
            }
            else if (d=='a')
            {
                snake1.Dir=4;
            }



}
}

void MOVE(){
switch(snake1.Dir)
{
    case 1: snake1.heady--;break;
    case 2: snake1.heady++;break;
    case 3:snake1.headx++;break;
    case 4 :snake1.headx--;break;

}


 if(snake1.headx==map1.fruitx&&snake1.heady==map1.fruity)
   {
      fruit();
      player1.score++;
   }

}


int main()
{

    setup();

  while(!player1.lose)
  {
      if(map1.wid-1==snake1.headx||snake1.heady+1==0||snake1.heady==20||snake1.headx+1==0)
        player1.lose=true;

      drawMap();
      DIR();
      MOVE();
      cout<<"score"<<player1.score<<endl;

  }


cout<<"loser";
    return 0;
}
