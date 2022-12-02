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

void gameOver() 
{
	while (!(_kbhit())) {
		SetCurrentCursorPos(50, 25);
		
		textcolor(14);
		gotoxy(5, 5);
		//printf("내일은 주식왕!!!\n");
		printf("    $           ■■■■■■■■          $     ■            ■      $      ■■■■■■■      \n");
		gotoxy(5, 6);
		printf("                       ■                       ■            ■             ■         \n");
		gotoxy(5, 7);
		printf("                $      ■           $$          ■            ■             ■       $     \n");
		gotoxy(5, 8);
		printf("                       ■      $                ■ ■ ■■■■■             ■■■■■■■             \n");
		gotoxy(5, 9);
		printf("       $               ■        $$             ■        $$   ■            ■         \n");
		gotoxy(5, 10);
		printf("                       ■                $      ■             ■      $     ■            \n");
		gotoxy(5, 11);
		printf("                  $    ■                       ■             ■   $        ■■■■■■■\n");
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