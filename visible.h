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
	//�ֽ����� 5��� ���ּ���

	curPos.X = 60; curPos.Y = 15;
	SetCurrentCursorPos(curPos.X, curPos.Y);

    textcolor(14);
	printf("������ �ֽĿ�!!!\n");
	getchar();
	textcolor(15);
}
void Background()
{
    gotoxy(0, 35);
    for (int i = 0; i < 15; i++)
        printf("����������������");
}
// Ű���� �Էµ� ���� ��ȯ�ϴ� �Լ�
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}

void Ant()
{


    int isJumping = 0;
    int isBottom = 1;
    const int gravity = 3;

    int antY = 26;


    int leg = 0;
    Background();
    //int idx = 1;
    while (1)
    {

        // zŰ�� ������, �ٴ��� ���� ��������
        if (GetKeyDown() == ' ' && isBottom)
        {
            isJumping = 1;
            isBottom = 0;
        }

        if (isJumping)
        {
            antY -= gravity;
        }
        else
        {
            antY += gravity;
        }

        if (antY >= 26)
        {
            antY = 26;
            isBottom = 1;
        }

        if (antY <= 3)
        {
            isJumping = 0;
        }

        Background();
        gotoxy(0, antY);

        //textcolor(idx++);
        //if (idx > 15) idx = 1;
        printf("      ���  \n");
        printf("      ��    \n");
        printf("    �����\n");
        printf("    ���  ��\n");
        printf("    �����\n");
        printf("      ���  \n");
        printf("������  \n");
        printf("�����  \n");
        if (leg == 0)
        {
            printf(" /�� /��\n");
            leg = 1;
        }
        else
        {
            printf(" ��/ ��/\n");
            leg = 0;
        }

        gotoxy(40, 20);
        printf("********\n");
        gotoxy(40, 21);
        printf("*  100 *\n");
        gotoxy(40, 22);
        printf("********\n");

        Sleep(10);
        system("cls");
    }

}

