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
	//cols = ĭ/�� (����)  lines = ��/�� (����)

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
	printf("������ �ֽĿ�!!!\n 3���׽�Ʈ, 3���׽�Ʈ");
	getchar();
	textcolor(15);
}

