#pragma once
#include<stdio.h>
#pragma warning(disable:4996)
#include <limits.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "container.h"
#include <string.h>


void Title()
{
	COORD curPos;
	//curPos = GetCurrentCursorPos();
	//주식투자 5계명도 써주세용

	curPos.X = 60; curPos.Y = 15;
	SetCurrentCursorPos(curPos.X, curPos.Y);
	textcolor(14);
	printf("내일은 주식왕!!!\n");
	getchar();
	textcolor(15);