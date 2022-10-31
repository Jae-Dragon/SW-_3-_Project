#include<stdio.h>
#pragma warning(disable:4996)
#include <limits.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "container.h"

void Title();

int main()
{
	RemoveCursor();
	system("mode con cols=130 lines=34");
	//cols = 칸/행 (가로)  lines = 줄/열 (세로)

	Title();

	return 0;
}

void Title()
{
	COORD curPos;
	//curPos = GetCurrentCursorPos();
	curPos.X = 60; curPos.Y = 15;
	SetCurrentCursorPos(curPos.X, curPos.Y);
	textcolor(14);
	printf("내일은 주식왕!!!\n 3차테스트, 3차테스트");
	getchar();
	textcolor(15);
}

