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

char EventList1[40][60];
char EventList2[30][30];
char StockList[30][30];

void Stock()
{
	//정수 입력받고 그 선택의 번호 반환
	strcpy(StockList[0], "바이오");//0, 1
	strcpy(StockList[1], "방산");//2, 3
	strcpy(StockList[2], "반도체");
	strcpy(StockList[3], "조선");
	strcpy(StockList[4], "자동차");

}

void Event()
{
	//짝수번째 --> 주가하락 사유,  홀수번째 --> 주가상승 사유
	// 상황을 2개로 분류
	// 특정 종목에 영향을 미치는 이벤트와 전체적인 종목에 영향을 미치는 이벤트를 구분 
	//StockList 0:제약, 1:방산, 2:반도체, 3:조선, 4:제철

	//EventList1 --> 특정 종목 관련
	//EventList2 --> 전체 주가 관련


	strcpy(EventList1[0], "백신 부작용 발생");//바이오회사 주가 하락
	strcpy(EventList1[1], "전염병 발생");//바이오회사 주가 상승
	strcpy(EventList1[2], "미국의 자국기업 보호를 위한 국내기업 진단키트 수출규제");//바이오회사 주가 하락
	strcpy(EventList1[3], "미국의 국내기업 진단키트 수출승인");//바이오회사 주가 상승
	strcpy(EventList1[4], "탈모약 치료제 부작용 발생");//바이오회사 주가 하락
	strcpy(EventList1[5], "탈모 치료제 개발 성공!!!");//바이오회사 주가 상승

	strcpy(EventList1[6], "방산업체에서 비리 발생");//방산 관련 주가 하락
	strcpy(EventList1[7], "북한이 동해안으로 미사일 발사");//방상 관련 주가 상승
	strcpy(EventList1[8], "정부의 군관련 예산 감축");//방산 관련 주가 하락
	strcpy(EventList1[9], "대한민국, 폴란드에 K9 자주포 수출");//방상 관련 주가 상승
	strcpy(EventList1[10], "중국과 미국의 군비 경쟁 완화 협정 체결 ");//방산 관련 주가 하락
	strcpy(EventList1[11], "러시아와 우크라이나의 전쟁발발");//방상 관련 주가 상승

	strcpy(EventList1[12], "미국 한파로 인한 삼성전자 오스틴 공장 생산 중단");//반도체 관련 주가 하락
	strcpy(EventList1[13], "반도체 공급난으로 인한 미국의 반도체 사업 지원 강화");//반도체 관련 주가
	strcpy(EventList1[14], "코인 산업 관련 규제 증가");//반도체 관련 주가 하락
	strcpy(EventList1[15], "비트코인의 채굴 수요 급증");//반도체 관련 주가
	strcpy(EventList1[16], "지진으로 인한 반도체 공장 가동 중단");//반도체 관련 주가 하락
	strcpy(EventList1[17], "클라우드 산업의 확장으로 인한 서버용 D램 수요 폭발");//반도체 관련 주가

	strcpy(EventList1[18], "후판 가격의 급등");//조선 관련 주가 하락(선박의 주요 원자재)
	strcpy(EventList1[19], "반도체 공급난으로 인한 미국의 반도체 사업 지원 강화");//조선 관련 주가 상승
	strcpy(EventList1[20], "카타르와의 LNG 운반선 비용문제를 두고 갈등 발생");//조선 관련 주가 하락(선박의 주요 원자재)
	strcpy(EventList1[21], "카타르와의 LNG 운반선 관련 최종 계약 도달");//조선 관련 주가 상승

	strcpy(EventList1[22], "자율 주행 자동차 기능 오류로 인한 인명피해 발생");//자동차 관련 주가 하락
	strcpy(EventList1[23], "현대차와 기아차의 중고차 시장 진출");//자동차 관련 주가 상승
	strcpy(EventList1[24], "정부의 한 가정 당 보유 차의 수에 대한 규제 시작");//자동차 관련 주가 하락
	strcpy(EventList1[25], "현대차가 장기간 개발한 SUV 출시");//자동차 관련 주가 상승
	strcpy(EventList1[26], "환경오염을 막기 위한 정부의 대중교통 가격 완화");//자동차 관련 주가 하락
	strcpy(EventList1[27], "역사에 기록될 폭우로 인한 다수 차 침수");//자동차 관련 주가 상승

	//==================================================================================================================
	strcpy(EventList2[0], "전체적인 원자재 가격의 상승");//주가 하락
	strcpy(EventList2[1], "전체적인 원자재 가격의 인하");//주가 상승
	strcpy(EventList2[2], "원화의 환율이 상승하였다");//주가 하락 -->대한민국 원화의 가치가 휴지 조각이 되기 때문
	strcpy(EventList2[3], "원화의 환율이 하락하였다");//주가 상승
	strcpy(EventList2[4], "고금리의 시대가 도래하였다");//주가 하락 -->채권의 수요가 증가하고 주식의 수요는 감소
	strcpy(EventList2[5], "저금리의 시대가 도래하였다");//주가상승 -->채권의 수요가 감소하고 주식 수요 증가
	strcpy(EventList2[6], "금리가 하락 추세로 돌아섰다");//주가하락 -->채권매수로 인한 채권 가격 증가, 주식 매도
	strcpy(EventList2[7], "금리가 상승 추세로 돌아섰다");//주가상승 -->채권매도로 인한 채권 가격 하락, 주식 매수
	strcpy(EventList2[8], "경상수지가 적자를 기록했다");//주가하락 --> 해외자금 유출 --> 기업실적 악화
	strcpy(EventList2[9], "경상수지가 흑자를 기록했다");//주가상승 --> 해외자금 유입 --> 기업실적 호전
	strcpy(EventList2[10], "유가가 상승하였다");//주가하락 -->경상수지가 악화되고 기업실적이 악화(원자재값과 관련)
	strcpy(EventList2[11], "유가가 하락하였다");//주가상승 -->경상수지가 호전되고 기업실적이 호전(원자재값과 관련)



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
	
	*random1 = Random(0, 21);//이벤트가 추가되는 만큼 오른쪽 파라미터를 늘려줄 것
	textcolor(10);
	gotoxy(32, 10);
	printf("News: %s", EventList1[*random1]);
	Sleep(1000);
	*random2 = Random(0, 11);//이벤트가 추가되는만큼 오른쪽 파라미터를 늘려줄 것
	gotoxy(32, 12);
	printf("News: %s", EventList2[*random2]);
	Sleep(1000);

	textcolor(13);
	gotoxy(32, 16);
	printf("투자상품 목록");
	textcolor(15);
	gotoxy(32, 18);
	Sleep(1000);
	printf("1.%s, 2.%s, 3.%s, 4.%s, 5.%s", StockList[0], StockList[1], StockList[2], StockList[3], StockList[4]);
	
	gotoxy(32, 19);
	printf("------------------------------------------------------------------");

	gotoxy(32, 21);
	Sleep(100);
	textcolor(14);
	printf("상품에 투자하고 싶으시면 Y를, 아니라면 N을 입력해주세요: ");
	scanf("%c", YorN);
	getchar();
	Sleep(50);
	if (*YorN == 'N') return;

	textcolor(12);
	gotoxy(32, 23);
	printf("(Hint: 보통 종목별 호재가 주식시장에서 파워가 강합니다.");//다음부터 작업할 부분
	gotoxy(32, 24);
	printf(" 몇가지 사례를 제외한다면 말이죠.)");
	gotoxy(32, 26);
	textcolor(14);
	printf("투자하고 싶은 상품의 번호를 입력하세요: ");//다음부터 작업할 부분
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

int Result(char YorN, int Choice, int RandEvent1, int RandEvent2)//왼쪽부터 차례대로 투자여부, 종목 선택, 랜덤 이벤트
{
	int revenue = 0;
	if (YorN == 'N') return 0;
	
	//EventList2에서 각 종목에서 짝수번째는 악재, 홀수번째는 호재임
	//0~21 
	else {
		if (RandEvent2 % 2 == 0)
			revenue -= gold * 0.2;
		else
			revenue += gold * 0.1;
	}



	//EventList1에서 각 종목에서 짝수번째는 악재, 홀수번째는 호재임
	//0~5는 바이오 관련, // 6~11은 방산 관련 // 12~17은 반도체 관련 // 18~21은 조선 관련

	if (RandEvent1 % 2 == 0)//악재일 때
	{
		if (RandEvent1 >= 0 && RandEvent1 <= 5)//바이오 관련 주라면
		{
			if (Choice == 1) revenue -= gold * 0.4;
		}
		if (RandEvent1 >= 6 && RandEvent1 <= 11)//방산 관련 주라면
		{
			if (Choice == 2) revenue -= gold * 0.4;
		}
		if (RandEvent1 >= 12 && RandEvent1 <= 17)//반도체 관련 주라면
		{
			if (Choice == 3) revenue -= gold * 0.4;
		}
		if (RandEvent1 >= 18 && RandEvent1 <= 21)//반도체 관련 주라면
		{
			if (Choice == 4) revenue -= gold * 0.4;
		}
		if (RandEvent1 >= 22 && RandEvent1 <= 27)//자동차 관련 주라면
		{
			if (Choice == 5) revenue -= gold * 0.4;
		}
	}

	else//호재일 때
	{
		if (RandEvent1 >= 0 && RandEvent1 <= 5)//바이오 관련 주라면
		{
			if (Choice == 1) revenue += gold * 0.2;
		}
		if (RandEvent1 >= 6 && RandEvent1 <= 11)//방산 관련 주라면
		{
			if (Choice == 2) revenue += gold * 0.2;
		}
		if (RandEvent1 >= 12 && RandEvent1 <= 17)//반도체 관련 주라면
		{
			if (Choice == 3) revenue += gold * 0.2;
		}
		if (RandEvent1 >= 18 && RandEvent1 <= 21)//반도체 관련 주라면
		{
			if (Choice == 4) revenue += gold * 0.2;
		}
		if (RandEvent1 >= 22 && RandEvent1 <= 27)//자동차 관련 주라면
		{
			if (Choice == 5) revenue += gold * 0.2;
		}
	}


	//우선 각 종목 관련 수익률 기준을 정해야 함
	//EventList2에서 발생하는 사건들 중 주가에 크게 영향을 미치는 부분과 그렇지 않은 부분을 나눠야 함

	return revenue;
}

void StockMarket()
{
	int Choice, random1, random2, revenue = 0;
	char YORN;

	Drawingmarket();//거래소 형태 그려주기
	Opinion(&YORN, &Choice, &random1, &random2);//플레이어의 선택 수용
	Sleep(600);


	revenue = Result(YORN, Choice, random1, random2);//수익률 반환
	//그러면 전역변수로 선언한 Gold에 + - revenue를 해줌

	gold += revenue;//골드에 수익률 반환해줌


	//이 밑으로는 모든 작업이 끝난 후에 실행
	EraseMarket();//맨 마지막 달리기 화면으로 전환하기 전 거래소를 지워줌
	EraseOpinion();
}

