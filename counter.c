#include "Counter.h"
#include "Game_End.h"
void Add_Danger_Rate(int _x,int _y,Map* Board,char count,char Space,char Danger)
{
	if((count+Danger) == 5 && Space==1) Space+=10;
	if(count == 4) count+=5;
	if(Board->arrDanger[_x][_y] == -1);
	else if(count >=3 ) Board->arrDanger[_x][_y] +=(2*count+Space+Danger);
	else Board->arrDanger[_x][_y] = (2*count+Space+Danger);
}


void Favor_Rate(int _x,int _y,Map* Board,char count,char Space,char Favor){
	if(count+Favor == 5 && Space) Space+=10;
	if(Board->arrFavor[_x][_y] == -1);
	else if(count >=3) Board->arrFavor[_x][_y] +=(2*count+Space+Favor);
	else Board->arrFavor[_x][_y] = (2*count+Space+Favor);
}
void Danger_Counter(int _x,int _y,int w,int s,Map* Board){
	int x,y,tmp_x,tmp_y,Danger1,Danger2;
	char space,count;
	space = count = 0;
	Danger1 = Danger2 = 0;
	for(x=_x,y=_y;Board->arrBoard[x][y] == USER && x>=0 && y>=0 && x<=19 && y<=19 ;x+=w,y+=s){
		if(Board->arrBoard[x+w][y+s] == 0 && Board->arrBoard[x+w+w][y+s+s] == USER){
			x+=w;
			y+=s;
		}
	}
	if(Board->arrBoard[x][y] == 0) Danger1++;

	for(x-=w,y-=s;Board->arrBoard[x][y] == USER;x-=w,y-=s){
		count++;
		if(Board->arrBoard[x-w][y-s] == 0 && Board->arrBoard[x-w-w][y-s-s] == USER){
			tmp_x = x-w;
			tmp_y = y-s;
			count++;
			space++;
			x-=w;
			y-=s;
		}

	}
	if(count-space == 5) Game_End(1);
	if(Board->arrBoard[x][y] == 0) Danger2++;
	if(Danger1)
		Add_Danger_Rate(x+(w*(count+1)),y+(s*(count+1)),Board,count-space,0,2*(Danger1+Danger2));
	if(Danger2)
		Add_Danger_Rate(x,y,Board,count-space,0,Danger1+Danger2);
	if(space)
		Add_Danger_Rate(tmp_x,tmp_y,Board,count-space,1,1);
}

void Favor_Counter(int _x,int _y,int w,int s,Map* Board){
	int x,y,tmp_x,tmp_y,Favor1,Favor2;
	char space,count;
	space = count = 0;
	Favor1 = Favor2 = 0;
	for(x=_x,y=_y;Board->arrBoard[x][y] == COM && x>=0 && y>=0 && x<=19 && y<=19 ;x+=w,y+=s){
		if(Board->arrBoard[x+w][y+s] == 0 && Board->arrBoard[x+w+w][y+s+s] == COM){
			x+=w;
			y+=s;
		}
	}
	if(Board->arrBoard[x][y] == 0) Favor1++;

	for(x-=w,y-=s;Board->arrBoard[x][y] == COM;x-=w,y-=s){
		count++;
		if(Board->arrBoard[x-w][y-s] == 0 && Board->arrBoard[x-w-w][y-s-s] == COM){
			tmp_x = x-w;
			tmp_y = y-s;
			count++;
			space++;
			x-=w;
			y-=s;
		}

	}
	if(count-space  == 5) Game_End(0);
	if(Board->arrBoard[x][y] == 0) Favor2++;
	if(Favor1)
		Favor_Rate(x+(w*(count+1)),y+(s*(count+1)),Board,count-space,0,Favor1+Favor2);
	if(Favor2){
		Favor_Rate(x,y,Board,count-space,0,Favor1+Favor2);
		//if(count == 3 && !space && Favor1)
			//Favor_Rate(x-w,y-s,Board,count+1,space,Favor1+Favor2);
	}
	if(space)
		Favor_Rate(tmp_x,tmp_y,Board,count-space,1,0);
}