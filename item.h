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
	// 10�� 2 : �׵θ�, 9 : ���� 7: ����ǥ
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
			else if (cashInfo[y][x] == 9) printf(" ");
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
	if (cashX < 0)
	{
		cash_id = (rand() % 4);
		gotoxy(cashX, cashY);
		cashX = 60;
		cashY = rand() % 19 + 13;
	}

	if (cash_id == 3)
	{
		cashColor += 1;
		if (cashColor > 15) cashColor = 1;
		textcolor(cashColor);
	}
	textcolor(15);//15 : white
}