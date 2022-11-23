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

int main()
{
	RemoveCursor();
	system("mode con cols=180 lines=44 | title 내일은 투자왕!");
	//cols = 칸/행 (가로)  lines = 줄/열 (세로)
	//Title();
	
	Event();//초기에 이벤트 리스트 삽입 위해 실행 필요
	Stock();//초기 투자종목 리스트 삽입 위해 실행 필요

	movingAnt();
	gameOver();

	return 0;
}


