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
}
void Background()
{
    gotoxy(0, 35);
    for (int i = 0; i < 15; i++)
        printf("───────────");
}
// 키보드 입력된 값을 반환하는 함수
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

        // z키를 누르고, 바닥일 때만 점프가능
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
        printf("      ■■  \n");
        printf("      ■    \n");
        printf("    ■■■■\n");
        printf("    ■■  ■\n");
        printf("    ■■■■\n");
        printf("      ■■  \n");
        printf("■■■■■  \n");
        printf("■■■■  \n");
        if (leg == 0)
        {
            printf(" /＼ /＼\n");
            leg = 1;
        }
        else
        {
            printf(" ＼/ ＼/\n");
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
        distance++;
       
        if (distance != 0 && distance % 100 == 0)//거래소 입장 위해
        {
            StockMarket();
        }
        
    }

}

