#include "computer.h"
#include "Scanner.h"
void Com_Turn(Map* Board){
	int Max_x,Max_y,tmp_x,tmp_y,i,j,Danger,Favor,Mode =0;
	Danger = Favor = tmp_x = tmp_y = Max_x = Max_y = 0;
	for(i=0;i<19;i++)
		for(j=0;j<19;j++)
			Board->arrTotal[i][j] = Board->arrDanger[i][j] + Board->arrFavor[i][j];
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			if(Board->arrDanger[tmp_x][tmp_y] < Board->arrDanger[j][i] && Board->arrBoard[j][i] == 0 && Board->arrDanger[j][i] >= Board->arrFavor[tmp_x][tmp_y]){
				tmp_x = j;
				tmp_y = i;
				Danger++;
			}
			else if(Board->arrFavor[tmp_x][tmp_y] < Board->arrFavor[j][i] && Board->arrBoard[j][i] == 0 && Board->arrDanger[tmp_x][tmp_y] < Board->arrFavor[j][i] ){
				tmp_x = j;
				tmp_y = i;
				Favor++;
			}
			
			else if(Board->arrTotal[tmp_x][tmp_y] < Board->arrTotal[j][i] && Board->arrBoard[j][i] == 0){
				tmp_x = j;
				tmp_y = i;
			}
			
			
		}
	}


	Max_x = tmp_x;
	Max_y = tmp_y;

	Board->arrBoard[Max_x][Max_y] = COM;
	Board->arrFavor[Max_x][Max_y] = Board->arrDanger[Max_x][Max_y] = Board->arrFavor[Max_x][Max_y] = -1;
	Scanner_Com(Max_x,Max_y,Board);
	ReScanner(Max_x,Max_y,Board);
	gotoxy(Max_y*2,Max_x);
	printf("¡Ü");
}

