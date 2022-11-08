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
#include "StockMarket.h"

int main()
{
	RemoveCursor();
	system("mode con cols=130 lines=38");
	//cols = 칸/행 (가로)  lines = 줄/열 (세로)
	//Title();
	//Event();//초기에 이벤트 리스트 삽입 위해 실행 필요
	//Stock();//초기 투자종목 리스트 삽입 위해 실행 필요

	//StockMarket();

	Ant();
   

	return 0;
}


