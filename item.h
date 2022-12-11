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
	// 10원 2 : 테두리, 9 : 공백 7: 물음표 8 : heart
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
	},
	//heart
	{
		{2,2,2,2,2,2,2},
		{2,9,8,8,8,9,2},
		{2,2,2,2,2,2,2}
	}
};

char hurdleModel[][4][1] =
{
	{
		{0},
		{0},
		{1},
		{1}
	},
	{
		{0},
		{1},
		{1},
		{1}
	},
	{
		{1},
		{1},
		{1},
		{1}
	}
};


//임의로 추가

char antModel1[9][6] =
{
   {0,0,0,1,1,0},
   {0,0,0,1,0,0},
   {0,0,1,1,1,1},
   {0,0,1,1,0,1},
   {0,0,1,1,1,1},
   {0,0,0,1,1,0},
   {1,1,1,1,1,0},
   {1,1,1,1,0,0},
   {1,1,1,1,1,0}
};


void DeleteCash(char cashInfo[3][7])
{
	int x, y;
	COORD curPos = GetCurrentCursorPos();

	for (y = 0; y < 3; y++)
		for (x = 0; x < 7; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);

			//if (cashInfo[y][x] == 1 || cashInfo[y][x] == 0 || cashInfo[y][x] == 5 || cashInfo[y][x] == 2 || cashInfo[y][x] == 7) printf("  ");
			printf("  ");
		}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}


void ShowText(int amount)
{
	gotoxy(8, antY);
	COORD curPos = GetCurrentCursorPos();
	text_x = curPos.X;
	text_y = curPos.Y;

	SetCurrentCursorPos(curPos.X, curPos.Y);

	if (cash_id == 4) textcolor(12); // red
	else textcolor(10);//10 : green
	printf("+%d up", amount);

	textcolor(15);//15 : white

}

void DeleteText(void)
{
	SetCurrentCursorPos(text_x, text_y);
	printf("        ");
	SetCurrentCursorPos(text_x, text_y - 1);
	printf("        ");
}


void ShowHurdleText(int amount)
{
	gotoxy(8, antY);
	COORD curPos = GetCurrentCursorPos();
	htext_x = curPos.X;
	htext_y = curPos.Y;

	SetCurrentCursorPos(curPos.X, curPos.Y);

	textcolor(12); // red

	printf("-%d hp", amount);

	textcolor(15);//15 : white

}

void DeleteHurdleText(void)
{
	SetCurrentCursorPos(htext_x, htext_y);
	printf("        ");
}


int DetectCashCollision(int posY, char cashModel[3][7], int cash_id) // 충돌 시 1, 아니면 0
{
	int x, y, a, b;
	int arrX = 2;
	int arrY = posY;

	int amount;
	for (x = 0; x < 6; x++)
	{
		for (y = 0; y < 9; y++)
		{
			if (antModel1[y][x] == 1)
			{
				for (a = 0; a < 7; a++)
				{
					for (b = 0; b < 3; b++)
					{
						if (cashModel[b][a] == 2)
						{
							if ((arrX + x * 2 == cashX * 2 + a * 2) && (arrY + y == cashY + b))
							{
								//돈 지우기
								gotoxy(cashX, cashY);
								DeleteCash(cashModel[cash_id]);
								cashX = -1; // 현재 왼쪽 벽에 닿을 때까지 왼쪽으로 돈 이동하게 해놓아서 임의적으로 좌표 바꾸기

								// 수정필요
								//10원
								if (cash_id == 0) {
									coin += 10;
									amount = 10;
									ShowText(amount);
									return ;
								}
								//100원
								else if (cash_id == 1) {
									coin += 100;
									amount = 100;
									ShowText(amount);
									return;
								}
								//500원
								else if (cash_id == 2) {
									coin += 500;
									amount = 500;
									ShowText(amount);
									return;
								}
								//랜덤
								else if (cash_id == 3)
								{
									int key = rand() % 10 + 1;
									switch (key)
									{
										case 1 :
											coin += 10;
											amount = 10;
											ShowText(amount);
											break;

										case 2:
											coin += 100;
											amount = 100;
											ShowText(amount);
											break;

										case 3:
											coin += 100;
											amount = 100;
											ShowText(amount);
											break;

										case 4:
											coin += 100;
											amount = 100;
											ShowText(amount);
											break;

										case 5:
											coin += 500;
											amount = 500;
											ShowText(amount);
											break;

										case 6:
											coin += 500;
											amount = 500;
											ShowText(amount);
											break;

										case 7:
											coin += 500;
											amount = 500;
											ShowText(amount);
											break;

										case 8:
											coin += 1000;
											amount = 1000;
											ShowText(amount);
											break;

										case 9:
											coin += 1000;
											amount = 1000;
											ShowText(amount);
											break;

										case 10:
											coin += 2000;
											amount = 2000;
											ShowText(amount);
											break;

										default:
											break;
									}
								}
								// 하트
								else if (cash_id == 4)
								{
									life += 5;
									amount = 5;
									ShowText(amount);
									return;
								}
								

								//return 1;
							}
						}
					}
				}
			}

		}
	}
	//return 0;
}


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
			else if (cashInfo[y][x] == 8) printf("♥");
			else if (cashInfo[y][x] == 9) printf("  ");
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
	else if (cash_id == 4) textcolor(4); // red
	else textcolor(10);//10 : green
	ShiftLeft(cashModel[cash_id]);
	cashX -= 1;

	//왼쪽 벽에 닿았을 때
	if (cashX < 0)
	{
		cash_id = (rand() % 5);
		gotoxy(cashX, cashY);
		cashX = 60;
		cashY = rand() % 17 + 13;
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


void ShowHurdle(char hurdleInfo[4][1])
{
	int x, y;
	COORD curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
		for (x = 0; x < 1; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);

			if (hurdleInfo[y][x] == 1) printf("■");

		}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}


void DeleteHurdle(char hurdleInfo[4][1])
{
	int x, y;
	COORD curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
		for (x = 0; x < 1; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);

			if (hurdleInfo[y][x] == 1) printf("  ");

		}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

void ShiftLeftHurdle(void)
{
	COORD curPos = GetCurrentCursorPos();

	DeleteHurdle(hurdleModel[hurdle_id]);
	curPos.X -= 2;
	SetCurrentCursorPos(curPos.X, curPos.Y);
	ShowHurdle(hurdleModel[hurdle_id]);
}

void makeHurdle(void)
{
	gotoxy(hurdleX, hurdleY);

	//textcolor(12);//10 : red

	ShiftLeftHurdle(hurdleModel[hurdle_id]);
	hurdleX -= 1;

	//왼쪽 벽에 닿았을 때
	if (hurdleX < 0)
	{
		hurdle_id = (rand() % 3);
		gotoxy(hurdleX, hurdleY);
		hurdleX = 60;
		DeleteHurdle(hurdleModel[hurdle_id]);
	}


	//textcolor(15);//15 : white
}

// 장애물 충동검사
int DetectHurdleCollision(int posY, char hurdleModel[4][1]) // 충돌 시 1, 아니면 0
{
	int x, y, a, b;
	int arrX = 2;
	int arrY = posY;
	int amount;
	for (x = 0; x < 6; x++)
	{
		for (y = 0; y < 9; y++)
		{
			if (antModel1[y][x] == 1)
			{
				for (a = 0; a < 1; a++)
				{
					for (b = 0; b < 4; b++)
					{
						if (hurdleModel[b][a] == 1)
						{
							if ((arrX + x * 2 == hurdleX * 2 + a * 2) && (arrY + y == hurdleY + b))
							{
								//장애물 지우기
								//gotoxy(cashX, cashY);
								//DeleteCash(cashModel[cash_id]);
								hurdleX = -1; // 현재 왼쪽 벽에 닿을 때까지 왼쪽으로 돈 이동하게 해놓아서 임의적으로 좌표 바꾸기

								// 수정필요
								//10원
								life -= 10;
								amount = 10;
								ShowHurdleText(amount);
								return;
								


								//return 1;
							}
						}
					}
				}
			}

		}
	}
	//return 0;
}

