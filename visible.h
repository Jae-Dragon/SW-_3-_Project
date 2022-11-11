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
    gotoxy(5, 5);
	//printf("내일은 주식왕!!!\n");
    printf("                              ■                                                                   ■■■ \n");
    gotoxy(5, 6);
    printf("                    ■■      ■                                                                  ■    ■  ■\n");
    gotoxy(5, 7);
    printf("                  ■    ■    ■        ■■■                    ■■■■■                      ■    ■  ■\n");
    gotoxy(5, 8);
    printf("■        ■  ■  ■    ■    ■      ■      ■                  ■                               ■■■   ■■■\n");
    gotoxy(5, 9);
    printf("■        ■  ■    ■■      ■      ■      ■                  ■■■■■    ■■■■    ■      ■      ■\n");
    gotoxy(5, 10);
    printf("■        ■■■              ■        ■■■                    ■                  ■    ■      ■      ■\n");
    gotoxy(5, 11);
    printf("■        ■  ■                                                  ■■■■■        ■      ■■  ■■■■\n");
    gotoxy(5, 12);
    printf("■        ■  ■        ■■■■    ■■■■■■■                                ■■      ■            ■■\n");
    gotoxy(5, 13);
    printf("■■■■  ■  ■              ■                                ■■■■■■■   ■   ■    ■           ■  ■\n");
    gotoxy(5, 14);
    printf("                        ■■■■      ■                              ■       ■      ■   ■           ■  ■\n");
    gotoxy(5, 15);
    printf("                        ■            ■                              ■                    ■            ■■ \n");
    gotoxy(5, 16);
    printf("                        ■■■■      ■■■■■                      ■\n");
    textcolor(15);
    gotoxy(7, 23);
    printf("                                  ┌────────────── 사용 키  ──────────────┐");
    gotoxy(7, 24);
    printf("                                  │                                      │");
    gotoxy(7, 25);
    printf("                                  │     ┌──────┐                         │");
    gotoxy(7, 26);
    printf("                                  │     └──────┘   :   점프              │");
    gotoxy(7, 27);
    printf("                                  │    스베이스 바                       │");
    gotoxy(7, 28);
    printf("                                  └──────────────────────────────────────┘");
    

    gotoxy(25, 31);
    printf("시작하려면 Enter 키를 눌러주세요.");
    Sleep(500);

    int on_off = 0;
    while (1)
    {
        gotoxy(25, 31);
        if (_kbhit())
        {
            break;
        }
        if (on_off % 2 == 0)
        {
            printf("시작하려면 Enter 키를 눌러주세요.");
        }
        else {
            printf("                                                            ");

        }
        RemoveCursor();
        Sleep(300);
        on_off += 1;
    }
	getchar();
    
}
void Background()
{
    gotoxy(0, 35);
    for (int i = 0; i < 13; i++)
        printf("───────────");
    
    statInfo();
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

void movingAnt()
{
    int isJumping = 0;
    int isBottom = 1;
    const int gravity = 3;

    int antY = 26;


    int leg = 0;
    Background();
    //int idx = 1;

    start = 0.0;
   
    while (1)
    {

        // 스페이스 키를 누르고, 바닥일 때만 점프가능
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

        if (antY <= 10) // 개미의 점프 높이
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
        /*
        gotoxy(40, 20);
        printf("********\n");
        gotoxy(40, 21);
        printf("*  100 *\n");
        gotoxy(40, 22);
        printf("********\n");
        */
        Sleep(10);
        system("cls");
        distance++;
       
      
        if (distance != 0 && distance % 100 == 0)//거래소 입장 위해
        {
            StockMarket();
        }
    
        gettingOld();

        if (isEnd() == 1) {
            break;
        }

    }

    

}

void setName()
{
    system("cls");
    gotoxy(20, 10);
    printf("이름을 입력해주세요 : ");
    scanf("%s", name);
    //printf(name);
    //system("PAUSE");
}


void setLevel()
{
    //system("cls");
    textcolor(10);
    gotoxy(20, 15);
    printf("┌──────── 난이도 ────────┐ ");
    gotoxy(20, 16);
    printf("│                        │");
    gotoxy(20, 17);
    printf("│   쉬움 ( Easy ) : 0    │");
    gotoxy(20, 18);
    printf("│                        │");
    gotoxy(20, 19);
    printf("│   보통 ( Normal ) : 1  │");
    gotoxy(20, 20);
    printf("│                        │");
    gotoxy(20, 21);
    printf("│   어려움 ( Hard ) : 2  │");
    gotoxy(20, 22);
    printf("│                        │");
    gotoxy(20, 23);
    printf("└────────────────────────┘");

    textcolor(15);
    gotoxy(20, 24);
    printf(" 선택 : ");
    scanf("%d", &level);
    //printf("%d", level);
    //system("PAUSE");
}
