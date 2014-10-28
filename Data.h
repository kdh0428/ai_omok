#ifndef __COMPUTER_H__
#define __COMPUTER_H__
typedef struct Map{
	char arrBoard[19][19];
	char arrDanger[19][19];
	char arrFavor[19][19];
	char arrTotal[19][19];
}Map;
#define USER 1
#define COM 2
#endif