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

void statInfo() 
{
	int i;

	SetCurrentCursorPos(5, 4);

	printf("COIN : %d", coin);

	SetCurrentCursorPos(25, 4);

	textcolor(12);
	printf("�� : ");
	for (i = 0; i < life; i++) {
		printf("/");
	}
	textcolor(15);
	// �������� cls ����ȵɶ��� ������ ������Ʈ�� ����.
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

//���� ��
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
		// ���̵��� ���� �����ӵ� ����
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
	30�� �� ���� ����(�ŷ��� ���ְ� ���� ��)
	/////////////////////////////////////////////////////////////////////// : ����
	//////////////////////////////////////////// : ����
	//////////////// : �����

	*/

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
		//printf("������ �ֽĿ�!!!\n");
		printf("    $           ���������          $     ��            ��      $      ��������      \n");
		gotoxy(5, 6);
		printf("                       ��                       ��            ��             ��         \n");
		gotoxy(5, 7);
		printf("                $      ��           $$          ��            ��             ��       $     \n");
		gotoxy(5, 8);
		printf("                       ��      $                �� �� ������             ��������             \n");
		gotoxy(5, 9);
		printf("       $               ��        $$             ��        $$   ��            ��         \n");
		gotoxy(5, 10);
		printf("                       ��                $      ��             ��      $     ��            \n");
		gotoxy(5, 11);
		printf("                  $    ��                       ��             ��   $        ��������\n");
		gotoxy(5, 12);
		printf("\n");
		gotoxy(5, 13);
		printf("       $                ��������              ��         $    ��                �������� \n");
		gotoxy(5, 14);
		printf("                        ��               $          �� ��           ��                ��            ���\n");
		gotoxy(5, 15);
		printf("                        ��         $                ��   ��         ��     $$         ��               �� \n");
		gotoxy(5, 16);
		printf("                        ��������              ��      ��      ��                ��       $$       ��\n");
		gotoxy(5, 17); 
		printf("                        ��               $          ��         ��   ��                ��                ��\n");
		gotoxy(5, 18);
		printf("                        ��                          ��   $$      �� ��      $$        ��            ��� \n");
		gotoxy(5, 19);
		printf("                        ��������              ��              ��                ��������\n");
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