#include "Game_End.h"
#include "computer.h"
void Game_End(char who){
	if(who) {
		system("cls");
		gotoxy(8,8);
		printf("�Բ��� �̱�˽��ϴ�");
		gotoxy(8,9);
		printf("������ �����մϴ� \n");
		getch();
		exit(1);
	}
	else{
		system("cls");
		gotoxy(8,8);
		printf("��ǻ�Ͱ� �̰���ϴ�");
		gotoxy(8,9);
		printf("������ �����մϴ� \n");
		getch();  
		exit(1);
	}
}