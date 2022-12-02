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


// 개미 배열 (다리위치까지 포함됨.)
char antModel[9][6] =
{
    {0,0,0,1,1,0},
    {0,0,0,1,0,0},
    {0,0,1,1,1,1},
    {0,0,1,1,0,1},
    {0,0,1,1,1,1},
    {0,0,0,1,1,0},
    {1,1,1,1,1,0},
    {1,1,1,1,0,0},
    {1,1,0,1,1,0}
};

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

    while (1)
    {
        if (level == 0) // 난이도 쉬움
        {
            coin = 30000;
            //speed = 15;
            break; 
        }
        else if (level == 1) // 난이도 보통
        {
            coin = 10000;
            //speed = 10;
            break;
        }
     
        else if (level == 2) // 난이도 어려움
        {
            coin = 5000;
            //speed = 5;
            break;
        }
        else
        {
            gotoxy(20, 24);
            printf("                        ");
            Sleep(700);

            textcolor(5);
            gotoxy(20, 24);
            printf("다시 선택하십시오 !");

            
            gotoxy(20, 24);
            printf("                        ");

            textcolor(15);
            Sleep(700);
            gotoxy(20, 24);
            printf(" 선택 : ");
            scanf("%d", &level);
        }

    }
        

    //printf("%d", level);
    //system("PAUSE");
}

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
    printf("                                                                                                    \n");
    gotoxy(5, 6);
    printf("                                                                                                   ■■■\n");
    gotoxy(5, 7);
    printf("                    ■■      ■        ■■■                    ■■■■■                      ■    ■  ■\n");
    gotoxy(5, 8);
    printf("                  ■    ■    ■      ■      ■                  ■                              ■    ■  ■\n");
    gotoxy(5, 9);
    printf("■        ■  ■  ■    ■    ■      ■      ■                  ■■■■■    ■■■■    ■     ■■■   ■■■\n");
    gotoxy(5, 10);
    printf("■        ■  ■    ■■      ■        ■■■                    ■                  ■    ■      ■      ■\n");
    gotoxy(5, 11);
    printf("■        ■■■                                                  ■■■■■        ■      ■■    ■      ■    \n");
    gotoxy(5, 12);
    printf("■        ■  ■        ■■■■    ■■■■■■■                                ■■      ■    ■■■■    \n");
    gotoxy(5, 13);
    printf("■■■■  ■  ■              ■                                ■■■■■■■   ■   ■    ■            ■■ \n");
    gotoxy(5, 14);
    printf("                        ■■■■      ■                              ■       ■      ■   ■           ■  ■\n");
    gotoxy(5, 15);
    printf("                        ■            ■                              ■                    ■           ■  ■\n");
    gotoxy(5, 16);
    printf("                        ■■■■      ■■■■■                      ■                                  ■■ \n");
    textcolor(15);
    gotoxy(7, 22);
    printf("                                  ┌────────────── 사용 키  ──────────────┐");
    gotoxy(7, 23);
    printf("                                  │                                      │");
    gotoxy(7, 24);
    printf("                                  │     ┌──────┐                         │");
    gotoxy(7, 25);
    printf("                                  │     └──────┘   :   점프              │");
    gotoxy(7, 26);
    printf("                                  │    스베이스 바                       │");
    gotoxy(7, 27);
    printf("                                  │                                      │");
    gotoxy(7, 28);
    printf("                                  │       ┌──┐                           │");
    gotoxy(7, 29);
    printf("                                  │       │ P│     :   생명력 구매       │");
    gotoxy(7, 30);
    printf("                                  │       └──┘                           │");
    gotoxy(7, 31);
    printf("                                  └──────────────────────────────────────┘");
    

    gotoxy(25, 35);
    printf("시작하려면 Enter 키를 눌러주세요.");
    Sleep(500);

    int on_off = 0;
    while (1)
    {
        gotoxy(25, 35);
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

    setName();
    setLevel();
    system("cls");
    
}

// 바닥
void Background()
{
    gotoxy(0, 35);
    for (int i = 0; i < 13; i++)
        printf("────────────");
    
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
    const int gravity = 2; // 늘리면 점프 속도 증가, 줄이면 감소

    antY = 26;


    int leg = 0;
    Background();
    
    
    // 돈 만들기위함
    //gotoxy(cashX, cashY);
    //ShowCash(cashModel[cash_id]);

    //gotoxy(bombX, bombY);
    //ShowBomb(bombModel[bomb_id]);
    srand((unsigned int)time(NULL));

    //gotoxy(hurdleX, hurdleY);
    //ShowHurdle(cashModel[cash_id]);

    start = 0.0;
    int delay = 0;
    while (1)
    {
        makeCash();
        if (cashX < 30) delay = 1;
        if (delay == 1) makeHurdle();
        //makeBomb();
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

        if (antY <= 10) // 개미의 최대점프 높이
        {
            isJumping = 0;
        }

        Background();
        
        
        // 개미 흔적 지우기
        gotoxy(0, pre_ant);
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");

        
        pre_ant = antY;
       
        int i, j;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                gotoxy(j+1, antY+i);
                if (antModel[i][j] == 1)
                    printf("■");
            }
        }

        gotoxy(1, antY + 8);
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
        
        Sleep(speed);
        
        distance++;
        DetectCashCollision(antY, cashModel[cash_id], cash_id);
        DetectCashCollision_hurdle(antY, hurdleModel[hurdle_id]);
       
      
        LeftTime();//거래소 입장 판정
        

        DrawingList(76, 3);

        //system("cls"); // 주식 거래소와 별개로 필요
        gettingOld();
        isGoal();

        if (isEnd() == 1) {
            break;
        }

        
        


    }

    

}


