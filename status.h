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

int life = 100;
clock_t start;

void statInfo() 
{
	int i;

	SetCurrentCursorPos(5, 2);

	printf("COIN : %d", coin);

	SetCurrentCursorPos(25, 2);

	printf("♥ : ");
	for (i = 0; i < life; i++) {
		printf("/");
	};
}

void gettingOld() 
{
	clock_t now = clock();
	double result = (double)(now - start);
	
	if (result > 990.0) {
		life--;
		start = now;
	}
}

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
}//충돌감지 함수(충돌 발생 : return 1)를 호출하여 충돌 여부 확인 후 전역변수 스탯에 반영
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
		printf("GAME OVER");
		Sleep(500);
	}
}