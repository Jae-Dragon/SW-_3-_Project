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

void Title();

void EVENT();

int main()
{
	RemoveCursor();
	system("mode con cols=130 lines=34");
	//cols = 칸/행 (가로)  lines = 줄/열 (세로)

	Title();
	EVENT();

	return 0;
}

void EVENT()
{

	strcpy(EventList[0], "전염병 발생");//제약회사 주가 상승
	strcpy(EventList[1], "백신 부작용 발생");//제약회사 주가 하락

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


	gotoxy(5, 3);
	printf("%s\n", EventList[0]);
	gotoxy(5, 4);
	printf("%s\n", EventList[1]);
	gotoxy(5, 5);
	printf("%s\n", EventList[2]);
}

