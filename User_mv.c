#include "computer.h"
#include <conio.h>
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
int User_mv(int *x,int *y,Map* Board){
	char Mv,select=0;
	Mv = getch();
	if(Mv == -32) Mv = getch();
	switch(Mv){
	case LEFT:
		if( (*x) > 0)
			(*x) -= 2;
		break;
	case RIGHT :
		if((*x) < 36)
			*x += 2;
		break;
	case UP :
		if((*y) > 0)
			(*y)--;
		break;
	case DOWN :
		if((*y) < 18)
			(*y)++;
		break;
	case VK_SPACE :
		if(!Board->arrBoard[*y][*x/2]){
			Board->arrBoard[*y][*x/2] = USER;
			printf("¡Û");
			select++;
		}
	}
	gotoxy(*x,*y);
	return select;
}