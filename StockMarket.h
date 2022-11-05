#pragma once
#include<stdio.h>
#pragma warning(disable:4996)
#include <limits.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "container.h"
#include "define.h"
#include "visible.h"

char EventList[30][30];
char StockList[30][30];

void Stock()
{
	//정수 입력받고 그 선택의 번호 반환

	strcpy(StockList[0], "투자 X");
	strcpy(StockList[1], "방산");//2, 3
	strcpy(StockList[2], "반도체");
	strcpy(StockList[3], "조선");
	strcpy(StockList[4], "제철");
	strcpy(StockList[5], "제약");//0, 1
}

void Event()
{
	//짝수번째 --> 주가하락 사유,  홀수번째 --> 주가상승 사유
	//StockList 0:제약, 1:방산, 2:반도체, 3:조선, 4:제철
	
	strcpy(EventList[0], "백신 부작용 발생");//제약회사 주가 하락
	strcpy(EventList[1], "전염병 발생");//제약회사 주가 상승

	strcpy(EventList[2], "방산업체에서 비리 발생");//방산 관련 주가 하락
	strcpy(EventList[3], "북한이 동해안으로 미사일 발사");//방상 관련 주가 상승

	strcpy(EventList[4], "전체적인 원자재 가격의 상승");//주가 하락
	strcpy(EventList[5], "전체적인 원자재 가격의 인하");//주가 상승
	strcpy(EventList[6], "원화의 환율이 상승하였다");//주가 하락 -->대한민국 원화의 가치가 휴지 조각이 되기 때문
	strcpy(EventList[7], "원화의 환율이 하락하였다");//주가 상승
	strcpy(EventList[8], "고금리의 시대가 도래하였다");//주가 하락 -->채권의 수요가 증가하고 주식의 수요는 감소
	strcpy(EventList[9], "저금리의 시대가 도래하였다");//주가상승 -->채권의 수요가 감소하고 주식 수요 증가
	strcpy(EventList[10], "금리가 하락 추세로 돌아섰다");//주가하락 -->채권매수로 인한 채권 가격 증가, 주식 매도
	strcpy(EventList[11], "금리가 상승 추세로 돌아섰다");//주가상승 -->채권매도로 인한 채권 가격 하락, 주식 매수
	strcpy(EventList[12], "경상수지가 적자를 기록했다");//주가하락 --> 해외자금 유출 --> 기업실적 악화
	strcpy(EventList[13], "경상수지가 흑자를 기록했다");//주가상승 --> 해외자금 유입 --> 기업실적 호전
	strcpy(EventList[14], "유가가 상승하였다");//주가하락 -->경상수지가 악화되고 기업실적이 악화(원자재값과 관련)
	strcpy(EventList[15], "유가가 하락하였다");//주가상승 -->경상수지가 호전되고 기업실적이 호전(원자재값과 관련)



	//추가되면  Random에 들어가는 변수도 조절을 해줘야함
}

int Random(int min, int max)
{
	srand(time(NULL));
	int random = 0;
	random = rand() % (max - min) + min;

	return random;
}

void Opinion(char* YorN, int* Choice, int* random1, int* random2)
{
	
	*random1 = Random(0, 15);//이벤트가 추가되는 만큼 오른쪽 파라미터를 늘려줄 것
	textcolor(10);
	gotoxy(13, 3);
	printf("News: %s", EventList[*random1]);
	Sleep(1000);
	*random2 = Random(0, 15);//이벤트가 추가되는만큼 오른쪽 파라미터를 늘려줄 것
	gotoxy(13, 5);
	printf("News: %s", EventList[*random2]);
	Sleep(1000);

	textcolor(13);
	gotoxy(14, 8);
	printf("투자상품 목록");
	textcolor(15);
	gotoxy(14, 10);
	Sleep(1000);
	printf("1.%s, 2.%s, 3.%s, 4.%s, 5.%s", StockList[0], StockList[1], StockList[2], StockList[3], StockList[4]);

	gotoxy(14, 12);
	Sleep(100);
	printf("상품에 투자하고 싶으시면 Y를, 아니라면 N을 입력해주세요: ");
	scanf("%c", YorN);
	getchar();
	Sleep(50);
	if (*YorN == 'N') return;

	gotoxy(14, 14);
	printf("투자하고 싶은 상품의 번호를 입력하세요: ");

	gotoxy(14, 16);
	printf("최대 2개까지 가능, 2개 중 1개에만 투자 가능");//다음부터 작업할 부분
	scanf("%d", Choice);


	getchar();
}

void Drawingmarket()
{
	int x, y;

	for (x = 2; x <= 2 * Market_WIDTH + 16; x++) {
		SetCurrentCursorPos(Market_ORIGIN_X + x - 8, Market_ORIGIN_Y);

		printf("─");
	}
	x = 0; y = 0;
	for (int i = 0; i < 7; i++)
	{
		SetCurrentCursorPos(Market_ORIGIN_X + x - 6, Market_ORIGIN_Y - y);
		printf("\\");
		x++; y++;
	}
	x = 0; y = 0;
	for (int i = 0; i < 7; i++)
	{
		SetCurrentCursorPos(Market_ORIGIN_X + x + Market_WIDTH * 2 + 4, Market_ORIGIN_Y + y - 6);
		printf("\\");
		x++; y++;
	}
	for (x = 2; x <= 2 * Market_WIDTH + 6; x++) {
		SetCurrentCursorPos(Market_ORIGIN_X + x - 2, Market_ORIGIN_Y - 6);

		printf("\\");
	}
	//===============================

	for (y = 0; y <= Market_HEIGHT; y++) {
		SetCurrentCursorPos(Market_ORIGIN_X, Market_ORIGIN_Y + y);

		if (y == Market_HEIGHT) {
			printf("┖");//└ ┗ ┗
		}

		else {
			printf("┃");
		}
	}


	for (x = 2; x <= 2 * Market_WIDTH; x++) {
		SetCurrentCursorPos(Market_ORIGIN_X + x, Market_ORIGIN_Y + Market_HEIGHT);

		printf("─");
	}

	for (y = 0; y <= Market_HEIGHT; y++) {
		SetCurrentCursorPos(Market_ORIGIN_X + 2 * Market_WIDTH + 2, Market_ORIGIN_Y + y);//

		if (y == Market_HEIGHT) {
			printf("┚");//┘┚
		}

		else {
			printf("┃");
		}
	}


}

void EraseMarket()
{
	int x, y;

	for (x = 2; x <= 2 * Market_WIDTH + 16; x++) {
		SetCurrentCursorPos(Market_ORIGIN_X + x - 8, Market_ORIGIN_Y);

		printf("  ");
	}
	x = 0; y = 0;
	for (int i = 0; i < 7; i++)
	{
		SetCurrentCursorPos(Market_ORIGIN_X + x - 6, Market_ORIGIN_Y - y);
		printf("  ");
		x++; y++;
	}
	x = 0; y = 0;
	for (int i = 0; i < 7; i++)
	{
		SetCurrentCursorPos(Market_ORIGIN_X + x + Market_WIDTH * 2 + 4, Market_ORIGIN_Y + y - 6);
		printf("  ");
		x++; y++;
	}
	for (x = 2; x <= 2 * Market_WIDTH + 6; x++) {
		SetCurrentCursorPos(Market_ORIGIN_X + x - 2, Market_ORIGIN_Y - 6);

		printf("  ");
	}
	//===============================

	for (y = 0; y <= Market_HEIGHT; y++) {
		SetCurrentCursorPos(Market_ORIGIN_X, Market_ORIGIN_Y + y);

		if (y == Market_HEIGHT) {
			printf("  ");
		}

		else {
			printf("  ");
		}
	}


	for (x = 2; x <= 2 * Market_WIDTH; x++) {
		SetCurrentCursorPos(Market_ORIGIN_X + x, Market_ORIGIN_Y + Market_HEIGHT);

		printf("  ");
	}

	for (y = 0; y <= Market_HEIGHT; y++) {
		SetCurrentCursorPos(Market_ORIGIN_X + 2 * Market_WIDTH + 2, Market_ORIGIN_Y + y);//

		if (y == Market_HEIGHT) {
			printf("  ");
		}

		else {
			printf("  ");
		}
	}

}

void EraseOpinion()
{

	gotoxy(13, 3);
	printf("                                                               ");

	gotoxy(13, 5);
	printf("                                                               ");
	
	gotoxy(14, 8);
	printf("                                                               ");

	gotoxy(14, 10);
	printf("                                                               ");

	gotoxy(14, 12);
	printf("                                                               ");

	gotoxy(14, 14);
	printf("                                                               ");

}

void StockMarket()
{
	int Choice, random1, random2, revenue;
	char YORN;

	Drawingmarket();//거래소 형태 그려주기
	Opinion(&YORN, &Choice, &random1, &random2);//플레이어의 선택 수용
	Sleep(600);


	revenue = Result(YORN, Choice, random1, random2);//수익률 반환
	//그러면 전역변수로 선언한 Gold에 +- revenue를 해줌




	//이 밑으로는 모든 작업이 끝난 후에 실행
	EraseMarket();//맨 마지막 달리기 화면으로 전환하기 전 거래소를 지워줌
	EraseOpinion();
}

int Result(char YorN, int Choice, int RandEvent1, int RandEvent2)//왼쪽부터 차례대로 투자여부, 종목 선택, 랜덤 이벤트
{
	if (YorN == 'N') return 0;

	//0, 1은 제약 관련, // 2, 3은 방산 관련 // 나머지는 전부 해당됨

	
}