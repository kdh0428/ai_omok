#include <stdio.h>
#include <Windows.h>
#include "Data.h"

void Map_set(Map *Board);
void gotoxy(int x,int y);
int User_mv(int*,int*,Map*);
void Com_Turn(Map*);