#include "Game_End.h"
#include "computer.h"
void Game_End(char who){
	if(who) {
		system("cls");
		gotoxy(8,8);
		printf("님께서 이기셧습니다");
		gotoxy(8,9);
		printf("오목을 종료합니다 \n");
		getch();
		exit(1);
	}
	else{
		system("cls");
		gotoxy(8,8);
		printf("컴퓨터가 이겻습니다");
		gotoxy(8,9);
		printf("오목을 종료합니다 \n");
		getch();  
		exit(1);
	}
}