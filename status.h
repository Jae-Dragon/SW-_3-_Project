#pragma once
#include<stdio.h>
#pragma warning(disable:4996)
#include <limits.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>


//���� �۾��� ���� ���� ������ ��������� ���
#include "container.h"//�⺻���� window.h �Լ����� �־�δ� ��(ex. getcurrentcursorpos...)
#include "define.h"//���� ���� �� ���ǵ��� ��Ƶδ� ��
#include "visible.h"//�⺻������ ��¸� �����ϴ� �Լ��鸸 ��Ƶδ� ��
#include "StockMarket.h"//�ŷ��� ���� �Լ��鸸 ��Ƶδ� ��(��� ���)
#include "item.h"//������ ���� �Լ��鸸 ��Ƶδ� ��(�����)

int life = 100;
clock_t start;

void statInfo() 
{
	int i;

	SetCurrentCursorPos(5, 2);

	printf("COIN : %d", coin);

	SetCurrentCursorPos(25, 2);

	printf("�� : ");
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
	if (DetectCollision()) { // �̺�Ʈ�� �߻��ߴٸ� 
		life += lifePlus;
		coin += coinPlus;
		if (life > 100) {
			life = 100;
		}
	}
}//�浹���� �Լ�(�浹 �߻� : return 1)�� ȣ���Ͽ� �浹 ���� Ȯ�� �� �������� ���ȿ� �ݿ�
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