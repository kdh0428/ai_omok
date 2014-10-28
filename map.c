#include "computer.h"
void Map_set(Map *Board){
	int i,j;

	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			Board->arrBoard[i][j] = 0;
			Board->arrDanger[i][j] = 0;
			Board->arrFavor[i][j] = 0;
			Board->arrTotal[i][j] = 0;
		}
	}

	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			printf("¦«");
		}
		printf("\n");
	}
}

void gotoxy(int x,int y)
{	
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
 }
