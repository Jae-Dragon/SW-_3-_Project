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

char **EVENT_LIST;

void Title();

void EVENT();

int main()
{
	RemoveCursor();
	system("mode con cols=130 lines=34");
	//cols = 칸/행 (가로)  lines = 줄/열 (세로)

	Title();

	gotoxy(10, 3);
	EVENT();

	return 0;
}

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

void EVENT()
{
	EVENT_LIST = (char**)malloc(sizeof(char*)*20);

	EVENT_LIST[0] = "전염병 발생";//제약회사 주가 상승
	EVENT_LIST[1] = "백신 부작용 발생";//제약회사 주가 하락

	EVENT_LIST[2] = "방산업체에서 비리 발생";//방산 관련 주가 하락
	EVENT_LIST[3] = "북한이 동해안으로 미사일 발사";//방상 관련 주가 상승

	EVENT_LIST[4] = "전체적인 원자재 가격의 상승";//주가 하락
	EVENT_LIST[5] = "전체적인 원자재 가격의 인하";//주가 상승
	EVENT_LIST[6] = "원화의 환율이 상승하였다";//주가 하락 -->대한민국 원화의 가치가 휴지 조각이 되기 때문
	EVENT_LIST[7] = "원화의 환율이 하락하였다";//주가 상승
	EVENT_LIST[8] = "고금리의 시대가 도래하였다";//주가 하락 -->채권의 수요가 증가하고 주식의 수요는 감소
	EVENT_LIST[9] = "저금리의 시대가 도래하였다";//주가상승 -->채권의 수요가 감소하고 주식 수요 증가
	EVENT_LIST[10] = "금리가 하락 추세로 돌아섰다";//주가하락 -->채권매수로 인한 채권 가격 증가, 주식 매도
	EVENT_LIST[11] = "금리가 상승 추세로 돌아섰다";//주가상승 -->채권매도로 인한 채권 가격 하락, 주식 매수
	EVENT_LIST[12] = "경상수지가 적자를 기록했다";//주가하락 --> 해외자금 유출 --> 기업실적 악화
	EVENT_LIST[13] = "경상수지가 흑자를 기록했다";//주가상승 --> 해외자금 유입 --> 기업실적 호전
	EVENT_LIST[14] = "유가가 상승하였다";//주가하락 -->경상수지가 악화되고 기업실적이 악화(원자재값과 관련)
	EVENT_LIST[15] = "유가가 하락하였다";//주가상승 -->경상수지가 호전되고 기업실적이 호전(원자재값과 관련)

}

