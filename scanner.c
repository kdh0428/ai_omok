#include "Scanner.h"
#include "Counter.h"
int Scanner(int _x,int _y,Map *Board){
	Danger_Counter(_x,_y,-1,0,Board);//°¡·Î
	Danger_Counter(_x,_y,0,-1,Board);//¼¼·Î
	Danger_Counter(_x,_y,1,1,Board);//ºÏµ¿
	Danger_Counter(_x,_y,1,-1,Board);//ºÏ¼­
	return 0;
}

int Scanner_Com(int _x,int _y,Map* Board){
	Favor_Counter(_x,_y,-1,0,Board);//°¡·Î
	Favor_Counter(_x,_y,0,-1,Board);//¼¼·Î
	Favor_Counter(_x,_y,1,1,Board);//ºÏµ¿
	Favor_Counter(_x,_y,1,-1,Board);//ºÏ¼­
	return 0;
}

int ReScanner(int _x,int _y,Map* Board){
	ReCount(_x,_y,-1,0,Board);
	ReCount(_x,_y,0,-1,Board);
	ReCount(_x,_y,1,1,Board);
	ReCount(_x,_y,1,-1,Board);
	ReCount(_x,_y,1,0,Board);
	ReCount(_x,_y,0,1,Board);
	ReCount(_x,_y,-1,-1,Board);
	ReCount(_x,_y,-1,1,Board);
	return 0;

}
int ReScanner_Com(int _x,int _y,Map* Board){
	ReCount_Com(_x,_y,-1,0,Board);
	ReCount_Com(_x,_y,0,-1,Board);
	ReCount_Com(_x,_y,1,1,Board);
	ReCount_Com(_x,_y,1,-1,Board);
	ReCount_Com(_x,_y,1,0,Board);
	ReCount_Com(_x,_y,0,1,Board);
	ReCount_Com(_x,_y,-1,-1,Board);
	ReCount_Com(_x,_y,-1,1,Board);
	return 0;

}
