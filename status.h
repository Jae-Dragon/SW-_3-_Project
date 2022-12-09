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
#include "visible.h"//기본적으로 출력만 실행하는 함수들만 모아두는 곳
#include "StockMarket.h"//거래소 관련 함수들만 모아두는 곳(재용 담당)
#include "item.h"//아이템 관련 함수들만 모아두는 곳(언약담당)

void statInfo() 
{
	int i;

	SetCurrentCursorPos(5, 4);

	printf("COIN : %d", coin);

	SetCurrentCursorPos(25, 4);

	textcolor(12);
	printf("♥ : ");
	for (i = 0; i < life; i++) {
		printf("/");
	}
	textcolor(15);
	// 라이프바 cls 실행안될때도 빠르게 업데이트를 위함.
	for (i = 0; i < 100 - life; i++) {
		printf(" ");
	}

	SetCurrentCursorPos(5, 2);
	printf("NAME : ");
	for (i = 0; i < 10; i++) {
		printf("%c", name[i]);
	}
	SetCurrentCursorPos(25, 2);
	printf("LEVEL : %d", level);
}

//수정 전
/*
void gettingOld() 
{
	clock_t now = clock();
	double result = (double)(now - start);
	
	if (result > 990.0) {
		life--;
		start = now;
	}
}*/


void gettingOld()
{
	clock_t now = clock();
	double result = (double)(now - start);

	if (result > 990.0) {
		// 난이도에 따른 차감속도 조정
		switch (level) {
		case 0 :
			life -= 1;
			break;
		case 1 :
			life -= 2;
			break;
		case 2 :
			life -= 3;
			break;
		default :
			life -= 1;
			break;
		}
		start = now;
	}
}

/*
	30초 후 남은 생명(거래소 없애고 쟀을 때)
	/////////////////////////////////////////////////////////////////////// : 쉬움
	//////////////////////////////////////////// : 보통
	//////////////// : 어려움

	*/

/*
void afterEvent(int lifePlus, int coinPlus)
{
	if (DetectCollision()) { // 이벤트가 발생했다면 
		life += lifePlus;
		coin += coinPlus;
		if (life > 100) {
			life = 100;
		}
	}
}
*/


int isEnd() {
	if (life < 0) {
		return 1;
	}

	else {
		return 0;
	}
}

char antModel2[9][6] =
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

char crown[3][7] = {
	{0,1,0,1,1,0,1},
	{0,0,1,1,1,1,0},
	{0,0,1,1,1,1,0}
};

char neckTie[4][6] = {
	{0,0,0,1,1,0},
	{0,0,0,0,1,0},
	{0,0,0,0,1,0},
	{0,0,0,0,0,0}
};

void gameOver() 
{
	RemoveCursor();
	system("cls");
	while (!(_kbhit())) {
		SetCurrentCursorPos(50, 25);
		
		textcolor(14);
		gotoxy(5, 5);
		//THE END
		printf("    $           ■■■■■■■■          $     ■            ■      $      ■■■■■■■      \n");
		gotoxy(5, 6);
		printf("                       ■                       ■            ■             ■         \n");
		gotoxy(5, 7);
		printf("                $      ■           $$          ■            ■             ■       $     \n");
		gotoxy(5, 8);
		printf("                       ■      $                ■ ■ ■■■■■             ■■■■■■■             \n");
		gotoxy(5, 9);
		printf("       $               ■        $$             ■       $$   ■             ■         \n");
		gotoxy(5, 10);
		printf("                       ■                $      ■            ■      $      ■            \n");
		gotoxy(5, 11);
		printf("                  $    ■                       ■            ■   $         ■■■■■■■\n");
		gotoxy(5, 12);
		printf("\n");
		gotoxy(5, 13);
		printf("       $                ■■■■■■■              ■         $    ■                ■■■■■■■ \n");
		gotoxy(5, 14);
		printf("                        ■               $          ■ ■           ■                ■            ■■\n");
		gotoxy(5, 15);
		printf("                        ■         $                ■   ■         ■     $$         ■               ■ \n");
		gotoxy(5, 16);
		printf("                        ■■■■■■■              ■      ■      ■                ■       $$       ■\n");
		gotoxy(5, 17); 
		printf("                        ■               $          ■         ■   ■                ■                ■\n");
		gotoxy(5, 18);
		printf("                        ■                          ■   $$      ■ ■      $$        ■            ■■ \n");
		gotoxy(5, 19);
		printf("                        ■■■■■■■              ■              ■                ■■■■■■■\n");


		// 팀원들 이름
		textcolor(14);
		gotoxy(55, 40);
		printf("게임 제작 - 정재용, 소유진, 조언약, 채제우");

		// 개미 - 달성 업적 갯수마다 다르게?
		textcolor(7);
		gotoxy(65, 10);
		int i, j;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 6; j++) {
				gotoxy(65+j, 10 + i);
				if (antModel2[i][j] == 1)
					printf("■");
			}
		}

		textcolor(14);
		gotoxy(65, 18);
		printf(" /＼ /＼\n");

		Sleep(400);

		// 이름, 골드, 자산, 환산값, 생존시간 점차적으로 표시
		textcolor(15);
		gotoxy(10, 25);
		printf("이 름 : ");
		for (i = 0; i < 10; i++) {
			printf("%c", name[i]);
		}
		Sleep(300);
		gotoxy(10, 27);
		printf("보유골드 : %d", coin);
		Sleep(300);
		gotoxy(10, 29);
		printf("보유자산 : ");
		Sleep(300);
		gotoxy(17, 29);
		textcolor(7);
		printf("바이오 - %d 주", QuantityList[0]);
		Sleep(300);
		gotoxy(17, 30);
		printf("방  산 - %d 주", QuantityList[1]);
		Sleep(300);
		gotoxy(17, 31);
		printf("반도체 - %d 주", QuantityList[2]);
		Sleep(300);
		gotoxy(17, 32);
		printf("조  선 - %d 주", QuantityList[3]);
		Sleep(300);
		gotoxy(17, 33);
		printf("자동차 - %d 주", QuantityList[4]);
		Sleep(300);
		gotoxy(10, 35);
		textcolor(15);
		/*
		total = coin;
		for (int a = 0; a < 5; a++)
			total += QuantityList[a] * PriceList[a];
			*/
		printf("총 환산액 : %d", total);
		Sleep(300);
		gotoxy(10, 37);
		//rate = ((double)total - (double)seed) / (double)seed * 100.0;
		printf("수익률 : %.1f %%", rate);
		gotoxy(10, 39);
		Sleep(300);
		printf("생존시간 : %.1f 초", time_s);


		// 업적 표시
		Sleep(300);
		gotoxy(27, 27);
		printf("업적");
		gotoxy(27, 29);
		printf("○ 보유 투자 종목 5개 이상");
		gotoxy(27, 30);
		printf("○ 보유 투자 종목 15개 이상");
		gotoxy(27, 31);
		printf("○ 보유 투자 종목 30개 이상");
		gotoxy(27, 33);
		printf("○ 수익률 10%% 이상");
		gotoxy(27, 34);
		printf("○ 수익률 50%% 이상");
		gotoxy(27, 35);
		printf("○ 수익률 100%% 이상");
		gotoxy(27, 37);
		printf("○ 생존 시간 30초 이상");
		gotoxy(27, 38);
		printf("○ 생존 시간 60초 이상");
		gotoxy(27, 39);
		printf("○ 생존 시간 90초 이상");
		Sleep(600);

		// 달성 업적 확인
		// 총 보유 투자종목 갯수
		int property = 0; 
		for (int b = 0; b < 5; b++)
			property += QuantityList[b];

		if (property >= 5) {
			//achievement[0] == 1;
			achieve++;
			textcolor(11);
			gotoxy(27, 29);
			printf("● 보유 투자 종목 5개 이상");
			Sleep(300);
			textcolor(15);
		}
			
		if (property >= 15) {
			//achievement[1] == 1;
			achieve++;
			textcolor(11);
			gotoxy(27, 30);
			printf("● 보유 투자 종목 15개 이상");
			Sleep(300);
			textcolor(15);
		}
			
		if (property >= 30) {
			//achievement[2] == 1;
			achieve++;
			textcolor(11);
			gotoxy(27, 31);
			printf("● 보유 투자 종목 30개 이상");
			Sleep(300);
			textcolor(15);
		}
			
		// 수익률 확인
		if (rate >= 10) {
			achieve++;
			textcolor(11);
			gotoxy(27, 33);
			printf("● 수익률 10%% 이상");
			Sleep(300);
			textcolor(15);
		}
			
		if (rate >= 50) {
			achieve++;
			textcolor(11);
			gotoxy(27, 34);
			printf("● 수익률 50%% 이상");
			Sleep(300);
			textcolor(15);
		}
			
		if (rate >= 100) {
			achieve++;
			textcolor(11);
			gotoxy(27, 35);
			printf("● 수익률 100%% 이상");
			Sleep(300);
			textcolor(15);
		}
			
		// 생존 시간 확인
		if (time_s >= 30) {
			achieve++;
			textcolor(11);
			gotoxy(27, 37);
			printf("● 생존 시간 30초 이상");
			Sleep(300);
			textcolor(15);
		}
			
		if (time_s >= 60) {
			achieve++;
			textcolor(11);
			gotoxy(27, 38);
			printf("● 생존 시간 60초 이상");
			Sleep(300);
			textcolor(15);
		}
			
		if (time_s >= 90) {
			achieve++;
			textcolor(11);
			gotoxy(27, 39);
			printf("● 생존 시간 90초 이상");
			Sleep(300);
			textcolor(15);
		}
			

		// 업적에 따른 호칭 부여
		Sleep(300);
		gotoxy(55, 27);
		printf("업적    개 달성!");
		textcolor(14);
		gotoxy(58, 27);
		printf("%d", achieve);
		textcolor(15);
		gotoxy(55, 29);
		printf("당신은               입니다! ");
		textcolor(14);
		gotoxy(59, 29);

		if (achieve <= 3)
			printf("평범한 개미");
		else if (achieve <= 5) {
			printf("슈퍼개미");
			gotoxy(65 + 4, 10 + 3);
			textcolor(4);
			printf("＠");
		}
		else if (achieve <= 8) {
			printf("투자왕 개미");
			gotoxy(65, 10);
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 7; j++) {
					if (crown[i][j] == 1) {
						gotoxy(65 + j, 10 + i);
						textcolor(6);
						printf("■");
					}
				}
			}
		}
		else if (achieve == 9) {
			printf("워렌버핏 개미");
			gotoxy(65, 15);
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 6; j++) {
					if (neckTie[i][j] == 1) {
						gotoxy(65 + j, 15 + i);
						textcolor(9);
						printf("■");
					}
				}
			}

		}


		getch();


		
	}
}


void isGoal() {
	if (coin > seed * 2) {
		switch (level) {
		case 0 :
			level++;
			seed = coin;
			break;
		case 1:
			level++;
			seed = coin;
			break;
		default :
			break;
		}
	}
}