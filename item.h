#pragma once
#include<stdio.h>
#pragma warning(disable:4996)
#include <limits.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>


//���� �۾��� ���� ���� ������ ��������� ���
#include "container.h"//�⺻���� window.h �Լ����� �־�δ� ��(ex. getcurrentcursorpos...)
#include "define.h"//���� ���� �� ���ǵ��� ��Ƶδ� ��
#include "visible.h"//�⺻������ ��¸� �����ϴ� �Լ��鸸 ��Ƶδ� ��(���� ���)
#include "StockMarket.h"//�ŷ��� ���� �Լ��鸸 ��Ƶδ� ��(��� ���)
#include "item.h"//������ ���� �Լ��鸸 ��Ƶδ� ��(��� ���)
#include "status.h"//����â ���� �Լ��鸸 ��Ƶδ� ��(���� ���)

char cashModel[][3][7] =
{
	// 10�� 2 : �׵θ�, 9 : ���� 7: ����ǥ 8 : heart
	{
		{2,2,2,2,2,2,2},
		{2,9,1,9,0,9,2},
		{2,2,2,2,2,2,2}
	},
	//100��
	{
		{2,2,2,2,2,2,2},
		{2,9,1,0,0,9,2},
		{2,2,2,2,2,2,2}
	},
	//500��
	{
		{2,2,2,2,2,2,2},
		{2,9,5,0,0,9,2},
		{2,2,2,2,2,2,2}
	},
	//??? ����
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


//���Ƿ� �߰�

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


int DetectCashCollision(int posY, char cashModel[3][7], int cash_id) // �浹 �� 1, �ƴϸ� 0
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
								//�� �����
								gotoxy(cashX, cashY);
								DeleteCash(cashModel[cash_id]);
								cashX = -1; // ���� ���� ���� ���� ������ �������� �� �̵��ϰ� �س��Ƽ� ���������� ��ǥ �ٲٱ�

								// �����ʿ�
								//10��
								if (cash_id == 0) {
									coin += 10;
									amount = 10;
									ShowText(amount);
									return ;
								}
								//100��
								else if (cash_id == 1) {
									coin += 100;
									amount = 100;
									ShowText(amount);
									return;
								}
								//500��
								else if (cash_id == 2) {
									coin += 500;
									amount = 500;
									ShowText(amount);
									return;
								}
								//����
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
								// ��Ʈ
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
			else if (cashInfo[y][x] == 8) printf("��");
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

	//���� ���� ����� ��
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

			if (hurdleInfo[y][x] == 1) printf("��");

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

	//���� ���� ����� ��
	if (hurdleX < 0)
	{
		hurdle_id = (rand() % 3);
		gotoxy(hurdleX, hurdleY);
		hurdleX = 60;
		DeleteHurdle(hurdleModel[hurdle_id]);
	}


	//textcolor(15);//15 : white
}

// ��ֹ� �浿�˻�
int DetectHurdleCollision(int posY, char hurdleModel[4][1]) // �浹 �� 1, �ƴϸ� 0
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
								//��ֹ� �����
								//gotoxy(cashX, cashY);
								//DeleteCash(cashModel[cash_id]);
								hurdleX = -1; // ���� ���� ���� ���� ������ �������� �� �̵��ϰ� �س��Ƽ� ���������� ��ǥ �ٲٱ�

								// �����ʿ�
								//10��
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

