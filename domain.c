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
	//cols = ĭ/�� (����)  lines = ��/�� (����)
	//Title();
	//Event();//�ʱ⿡ �̺�Ʈ ����Ʈ ���� ���� ���� �ʿ�
	//Stock();//�ʱ� �������� ����Ʈ ���� ���� ���� �ʿ�

	//StockMarket();

	Ant();
   

	return 0;
}


