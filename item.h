#pragma once
#include<stdio.h>
#pragma warning(disable:4996)
#include <limits.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>


//분할 작업을 위해 각자 독립된 헤더파일을 사용
#include "container.h"//기본적인 window.h 함수들을 넣어두는 곳(ex. getcurrentcursorpos...)
#include "define.h"//전역 변수 및 정의들을 모아두는 곳
#include "visible.h"//기본적으로 출력만 실행하는 함수들만 모아두는 곳(유진 담당)
#include "StockMarket.h"//거래소 관련 함수들만 모아두는 곳(재용 담당)
#include "item.h"//아이템 관련 함수들만 모아두는 곳(언약 담당)
#include "status.h"//상태창 관련 함수들만 모아두는 곳(제우 담당)


char cashModel[][3][7] =
{
	// 10원 2 : 테두리, 9 : 공백 7: 물음표
	{
		{2,2,2,2,2,2,2},
		{2,9,1,9,0,9,2},
		{2,2,2,2,2,2,2}
	},
	//100원
	{
		{2,2,2,2,2,2,2},
		{2,9,1,0,0,9,2},
		{2,2,2,2,2,2,2}
	},
	//500원
	{
		{2,2,2,2,2,2,2},
		{2,9,5,0,0,9,2},
		{2,2,2,2,2,2,2}
	},
	//??? 랜덤
	{
		{2,2,2,2,2,2,2},
		{2,9,7,7,7,9,2},
		{2,2,2,2,2,2,2}
	}
};

char bombModel[][5][5] =
{
	{
		{0,0,0,1,0},
		{0,0,1,0,0},
		{0,1,1,1,0},
		{1,1,1,1,1},
		{0,1,1,1,0}
	}
};


void ShowCash(char cashInfo[3][7])
{
	int x, y;
	COORD curPos = GetCurrentCursorPos();

	for (y = 0; y < 3; y++)
		for (x = 0; x < 7; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);

			if (cashInfo[y][x] == 2) printf("*");
			else if (cashInfo[y][x] == 1) printf("1");
			else if (cashInfo[y][x] == 0) printf("0");
			else if (cashInfo[y][x] == 5) printf("5");
			else if (cashInfo[y][x] == 7) printf("?");
			else if (cashInfo[y][x] == 9) printf("  ");
		}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

void DeleteCash(char cashInfo[3][7])
{
	int x, y;
	COORD curPos = GetCurrentCursorPos();

	for (y = 0; y < 3; y++)
		for (x = 0; x < 7; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);

			if (cashInfo[y][x] == 1 || cashInfo[y][x] == 0 || cashInfo[y][x] == 5 || cashInfo[y][x] == 2 || cashInfo[y][x] == 7) printf("  ");
		}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

void ShiftLeft(void)
{
	COORD curPos = GetCurrentCursorPos();
	
	DeleteCash(cashModel[cash_id]);
	curPos.X -= 2;
	SetCurrentCursorPos(curPos.X, curPos.Y);
	ShowCash(cashModel[cash_id]);
}

void makeCash(void)
{
	gotoxy(cashX, cashY);
	if (cash_id == 3) textcolor(cashColor);
	else textcolor(10);//10 : green
	ShiftLeft(cashModel[cash_id]);
	cashX -= 1;

	//왼쪽 벽에 닿았을 때
	if (cashX < 0)
	{
		cash_id = (rand() % 4);
		gotoxy(cashX, cashY);
		cashX = 60;
		cashY = rand() % 19 + 13;
		DeleteCash(cashModel[cash_id]);
	}

	if (cash_id == 3)
	{
		cashColor += 1;
		if (cashColor > 15) cashColor = 1;
		textcolor(cashColor);
	}
	textcolor(15);//15 : white
}

void ShowBomb(char bombInfo[5][5])
{
	int x, y;
	COORD curPos = GetCurrentCursorPos();

	for (y = 0; y < 5; y++)
		for (x = 0; x < 5; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);

			if (bombInfo[y][x] == 1) printf("●");
			
		}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

void DeleteBomb(char bombInfo[5][5])
{
	int x, y;
	COORD curPos = GetCurrentCursorPos();

	for (y = 0; y < 5; y++)
		for (x = 0; x < 5; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);

			if (bombInfo[y][x] == 1) printf("  ");

		}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

void ShiftLeftBomb(void)
{
	COORD curPos = GetCurrentCursorPos();

	DeleteBomb(bombModel[bomb_id]);
	curPos.X -= 2;
	SetCurrentCursorPos(curPos.X, curPos.Y);
	ShowBomb(bombModel[bomb_id]);
}

void makeBomb(void)
{
	gotoxy(bombX, bombY);

	textcolor(12);//10 : red

	ShiftLeftBomb(bombModel[bomb_id]);
	bombX -= 1;

	//왼쪽 벽에 닿았을 때
	if (bombX < 0)
	{
		//bomb_id = (rand() % 1);
		gotoxy(bombX, bombY);
		bombX = 60;
		bombY = rand() % 19 + 13;
		DeleteBomb(bombModel[bomb_id]);
	}


	textcolor(15);//15 : white
}