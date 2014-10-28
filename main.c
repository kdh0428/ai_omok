#include "Data.h"
#include "computer.h"
#include "Counter.h"
#include "Scanner.h"
int main(int argc,char *argv[]){
	Map Board;
	char *intro[] = {"○ : 사용자","● : 컴퓨터","방향키 : 이동","스페이스바 : 돌 놓기"};
	int _x,_y,position,i,j;
	system("mode con:cols=60 lines=20");
	system("cls");
	Map_set(&Board);
	for(i=0;i<4;i++){
		gotoxy(40,i);
		printf("%s",intro[i]);
	}
	_x = 16;
	_y = 8;
	gotoxy(_x,_y);
	while(1){
		if(User_mv(&_x,&_y,&Board)){
			Board.arrBoard[_y][_x/2] = USER;
			Board.arrDanger[_y][_x/2] = -1;
			Board.arrFavor[_y][_x/2] = -1;
			Scanner(_y,_x/2,&Board);
			Com_Turn(&Board);

		}

	}
	return 0;
}