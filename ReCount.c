#include "Counter.h"

void ReCount(int _x,int _y,int w,int s,Map* Board){
	int x,y,tmp_x,tmp_y,Danger1,Danger2;
	char space,count;
	space = count = 0;
	Danger1 = Danger2 = 0;

	for(x=_x+w,y=_y+s;Board->arrBoard[x][y] == USER && x>=0 && y>=0 && x<=19 && y<=19 ;x+=w,y+=s) count++;
	Del_Danger_Rate(x,y,Board,count);

}

void Del_Danger_Rate(int _x,int _y,Map* Board,char count)
{
	if(Board->arrDanger[_x][_y] != -1 && count < 3)Board->arrDanger[_x][_y]  = 2*count+1;
	else if(Board->arrDanger[_x][_y] != -1 && count >= 3)Board->arrDanger[_x][_y] -=1; 
}

void ReCount_Com(int _x,int _y,int w,int s,Map* Board){
	int x,y,tmp_x,tmp_y,Danger1,Danger2;
	char space,count;
	space = count = 0;
	Danger1 = Danger2 = 0;

	for(x=_x+w,y=_y+s;Board->arrBoard[x][y] == COM && x>=0 && y>=0 && x<=19 && y<=19 ;x+=w,y+=s) count++;
	Del_Favor_Rate(x,y,Board,count);

}

void Del_Favor_Rate(int _x,int _y,Map* Board,char count)
{
	if(Board->arrFavor[_x][_y] != -1 && count < 3)Board->arrFavor[_x][_y]  = 2*count+1;
	else if(Board->arrFavor[_x][_y] != -1 && count >= 3)Board->arrFavor[_x][_y] -=1; 
}