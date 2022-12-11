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


#define SPACE 32
#define UP 72

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
    {1,1,1,1,1,0}
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
            seed = 30000;
            speed = 100;
            break; 
        }
        else if (level == 1) // 난이도 보통
        {
            coin = 10000;
            seed = 10000;
            speed = 50;
            break;
        }
     
        else if (level == 2) // 난이도 어려움
        {
            coin = 5000;
            seed = 5000;
            speed = 10;
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
    gotoxy(1, 22);
    printf("                ┌────────────── 사용 키  ──────────────┐");
    gotoxy(1, 23);
    printf("                │                                      │");
    gotoxy(1, 24);
    printf("                │     ┌──────┐                         │");
    gotoxy(1, 25);
    printf("                │     └──────┘   :   점프              │");
    gotoxy(1, 26);
    printf("                │    스베이스 바                       │");
    gotoxy(1, 27);
    printf("                │                                      │");
    gotoxy(1, 28);
    printf("                │       ┌──┐                           │");
    gotoxy(1, 29);
    printf("                │       │ P│     :   생명력 구매       │");
    gotoxy(1, 30);
    printf("                │       └──┘                           │");
    gotoxy(1, 31);
    printf("                └──────────────────────────────────────┘");
    
    // 아이템 설명
    gotoxy(30, 22);
    printf("┌────────────────────────────  아이템 설명  ────────────────────────────┐");
    gotoxy(30, 23);
    printf("│                                                                       │");
    gotoxy(30, 24);
    printf("│               ■                      ");
    textcolor(10);
    printf("* * * * * * *");
    textcolor(15);
    printf("                   │");
    gotoxy(30, 25);
    printf("│           ■  ■      :   방해물      ");
    textcolor(10);
    printf("*   1 0 0   *");
    textcolor(15);
    printf("   :   코인UP      │");
    gotoxy(30, 26);
    printf("│       ■, ■, ■                      ");
    textcolor(10);
    printf("* * * * * * *");
    textcolor(15);
    printf("                   │");
    gotoxy(30, 27);
    printf("│                                                                       │");
    gotoxy(30, 28);
    printf("│       ");
    textcolor(12);
    printf("* * * * * * *                   ");
    textcolor(9);
    printf("* * * * * * *");
    textcolor(15);
    printf("                   │");
    gotoxy(30, 29);
    printf("│       ");
    textcolor(12);
    printf("*   ♥♥♥  *");
    textcolor(15);
    printf("   :   생명력UP    ");
    textcolor(9);
    printf("*   ? ? ?   *");
    textcolor(15);
    printf("   :   랜덤코인    │");
    gotoxy(30, 30);
    printf("│       ");
    textcolor(12);
    printf("* * * * * * *                   ");
    textcolor(9);
    printf("* * * * * * *");
    textcolor(15);
    printf("                   │");
    gotoxy(30, 31);
    printf("└───────────────────────────────────────────────────────────────────────┘");
 

    // 개미
    textcolor(7);
    gotoxy(65, 8);
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 6; j++) {
            gotoxy(65 + j, 8 + i);
            if (antModel[i][j] == 1)
                printf("■");
        }
    }
    gotoxy(65, 16);
    printf(" /＼ /＼\n");
    textcolor(15);



    gotoxy(30, 35);
    printf("시작하려면 Enter 키를 눌러주세요.");
    Sleep(500);

    int on_off = 0;
    while (1)
    {
        gotoxy(30, 35);
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
        if (cashX == 45) DeleteText();
        if (cashX < 30) delay = 1;
        if (delay == 1) makeHurdle();
        if (hurdleX == 45) DeleteHurdleText();


        for (int i = 0; i < 20; i++)
        {
            if (_kbhit() != 0)
            {
                int key = _getch();
                switch (key)
                {
                    case SPACE:
                        if (isBottom)
                        {
                            isJumping = 1;
                            isBottom = 0;
                        }

                        
                        
                        break;
                    case 'p':
                        if (coin >= pur_heart)
                        {
                            coin -= pur_heart;
                            life += 20;
                            pur_heart += 5000;
                        }
                        break;
                    case 'P':
                        if (coin >= pur_heart)
                        {
                            coin -= pur_heart;
                            life += 20;
                            pur_heart += 5000;
                        }
                        break;

              
                        

                }
            }
            
            
        }
    
        Sleep(speed);
        /*
        if (GetKeyDown() == 'p' || GetKeyDown() == 'P' || GetKeyDown() == 'ㅔ' || GetKeyDown() == 'ㅖ')
        {
            coin -= pur_heart;
            life += 30;
            pur_heart += 5000;
        }
        */
        
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
                gotoxy(j + 1, antY + i);
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
    
        distance++;
        DetectCashCollision(antY, cashModel[cash_id], cash_id);
        DetectHurdleCollision(antY, hurdleModel[hurdle_id]);
        
       
        total = coin;
        for (int a = 0; a < 5; a++)
            total += QuantityList[a] * PriceList[a];
        rate = ((double)total - (double)seed) / (double)seed * 100.0;
        gotoxy(60, 37);
        textcolor(14);
        printf("현재 수익률 : %.1f %%", rate);
        gotoxy(60, 38);
        time_s = (distance / 1000.0) * 3 * speed;
        printf("현재 생존시간 : %.1f 초", time_s);
        textcolor(15);

        

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


