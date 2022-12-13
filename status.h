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

	printf("COIN : %5d", coin);

	SetCurrentCursorPos(25, 4);

	textcolor(12);
	printf("�� : ");
	if (life <= 100) {
		for (i = 0; i < life; i++) {
			printf("/");
		}
		// �������� cls ����ȵɶ��� ������ ������Ʈ�� ����.
		for (i = 0; i < 100 - life; i++) {
			printf(" ");
		}
	}
	else { // life�� ��ġ�� ���
		for (i = 0; i < 100; i++) {
			printf("/");
		}
		SetCurrentCursorPos(30, 5);
		for (i = 100; i < life; i++) {
			printf("/");
		}
		for (i = 0; i < 100 - (life-100); i++) {
			printf(" ");
		}
	}
	textcolor(15);
	
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
			life -= 0.5;
			break;
		case 1 :
			life -= 1;
			break;
		case 2 :
			life -= 1.5;
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

char antModel2[9][6] =
{
	{0,0,0,1,1,0},
	{0,0,0,1,0,0},
	{0,0,1,1,1,1},
	{0,0,1,1,0,1},
	{0,0,1,1,1,1},
	{0,0,0,1,1,0},
	{1,1,1,1,1,0},
	{1,1,1,1,0,0},
	{1,1,1,1,1,0}
};
char antFace[20][20] =
{
	{0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0},
	{1,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,0,1},
	{0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
	{0,0,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,0,0},
	{0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0},
	{0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0},
	{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

char crown[3][7] = {
	{0,1,0,1,1,0,1},
	{0,0,1,1,1,1,0},
	{0,0,1,1,1,1,0}
};

char neckTie[4][6] = {
	{0,0,0,1,1,0},
	{0,0,0,0,1,0},
	{0,0,0,0,1,0},
	{0,0,0,0,0,0}
};

char warrenGlasses[2][10] = {
	{1,1,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,1,1}
};

char warrenNeckTie[8][6] = {
	{1,1,1,1,1,1},
	{0,1,1,1,1,0},
	{0,0,1,1,0,0},
	{0,1,1,1,1,0},
	{1,1,1,1,1,1},
	{1,1,1,1,1,1},
	{0,1,1,1,1,0},
	{0,0,1,1,0,0},
};

char warrenCrown[4][8] = {
	{1,0,0,1,1,0,0,1},
	{1,1,0,1,1,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1}
};

void gameOver() 
{
	RemoveCursor();
	system("cls");
	while (!(_kbhit())) {
		SetCurrentCursorPos(50, 25);
		
		textcolor(14);
		gotoxy(5, 5);
		//THE END
		printf("    $           ���������          $     ��            ��      $      ��������      \n");
		gotoxy(5, 6);
		printf("                       ��                       ��            ��             ��         \n");
		gotoxy(5, 7);
		printf("                $      ��           $$          ��            ��             ��       $     \n");
		gotoxy(5, 8);
		printf("                       ��      $                �� �� ������             ��������             \n");
		gotoxy(5, 9);
		printf("       $               ��        $$             ��       $$   ��             ��         \n");
		gotoxy(5, 10);
		printf("                       ��                $      ��            ��      $      ��            \n");
		gotoxy(5, 11);
		printf("                  $    ��                       ��            ��   $         ��������\n");
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


		// ������ �̸�
		textcolor(14);
		gotoxy(55, 40);
		printf("���� ���� - �����, ������, �����, ä����");

		// ���� - �޼� ���� �������� �ٸ���?
		textcolor(7);
		gotoxy(65, 10);
		int i, j;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 6; j++) {
				gotoxy(65+j, 10 + i);
				if (antModel2[i][j] == 1)
					printf("��");
			}
		}
		gotoxy(65, 18);
		printf(" /�� /��\n");
		textcolor(14);
		Sleep(400);

		// �̸�, ���, �ڻ�, ȯ�갪, �����ð� ���������� ǥ��
		textcolor(15);
		gotoxy(10, 25);
		printf("�� �� : ");
		for (i = 0; i < 10; i++) {
			printf("%c", name[i]);
		}
		Sleep(300);
		gotoxy(10, 27);
		printf("������� : %d", coin);
		Sleep(300);
		gotoxy(10, 29);
		printf("�����ڻ� : ");
		Sleep(300);
		gotoxy(17, 29);
		textcolor(7);
		printf("���̿� - %d ��", QuantityList[0]);
		Sleep(300);
		gotoxy(17, 30);
		printf("��  �� - %d ��", QuantityList[1]);
		Sleep(300);
		gotoxy(17, 31);
		printf("�ݵ�ü - %d ��", QuantityList[2]);
		Sleep(300);
		gotoxy(17, 32);
		printf("��  �� - %d ��", QuantityList[3]);
		Sleep(300);
		gotoxy(17, 33);
		printf("�ڵ��� - %d ��", QuantityList[4]);
		Sleep(300);
		gotoxy(10, 35);
		textcolor(15);
		/*
		total = coin;
		for (int a = 0; a < 5; a++)
			total += QuantityList[a] * PriceList[a];
			*/
		printf("�� ȯ��� : %d", total);
		Sleep(300);
		gotoxy(10, 37);
		//rate = ((double)total - (double)seed) / (double)seed * 100.0;
		printf("���ͷ� : %.1f %%", rate);
		gotoxy(10, 39);
		Sleep(300);
		printf("�����ð� : %.1f ��", time_s);


		// ���� ǥ��
		Sleep(300);
		gotoxy(27, 27);
		printf("����");
		gotoxy(27, 29);
		printf("�� ���� ���� ���� 5�� �̻�");
		gotoxy(27, 30);
		printf("�� ���� ���� ���� 15�� �̻�");
		gotoxy(27, 31);
		printf("�� ���� ���� ���� 30�� �̻�");
		gotoxy(27, 33);
		printf("�� ���ͷ� 10%% �̻�");
		gotoxy(27, 34);
		printf("�� ���ͷ� 50%% �̻�");
		gotoxy(27, 35);
		printf("�� ���ͷ� 100%% �̻�");
		gotoxy(27, 37);
		printf("�� ���� �ð� 30�� �̻�");
		gotoxy(27, 38);
		printf("�� ���� �ð� 60�� �̻�");
		gotoxy(27, 39);
		printf("�� ���� �ð� 90�� �̻�");
		Sleep(600);

		// �޼� ���� Ȯ��
		// �� ���� �������� ����
		int property = 0; 
		for (int b = 0; b < 5; b++)
			property += QuantityList[b];

		if (property >= 5) {
			//achievement[0] == 1;
			achieve++;
			textcolor(11);
			gotoxy(27, 29);
			printf("�� ���� ���� ���� 5�� �̻�");
			Sleep(300);
			textcolor(15);
		}
			
		if (property >= 15) {
			//achievement[1] == 1;
			achieve++;
			textcolor(11);
			gotoxy(27, 30);
			printf("�� ���� ���� ���� 15�� �̻�");
			Sleep(300);
			textcolor(15);
		}
			
		if (property >= 30) {
			//achievement[2] == 1;
			achieve++;
			textcolor(11);
			gotoxy(27, 31);
			printf("�� ���� ���� ���� 30�� �̻�");
			Sleep(300);
			textcolor(15);
		}
			
		// ���ͷ� Ȯ��
		if (rate >= 10) {
			achieve++;
			textcolor(11);
			gotoxy(27, 33);
			printf("�� ���ͷ� 10%% �̻�");
			Sleep(300);
			textcolor(15);
		}
			
		if (rate >= 50) {
			achieve++;
			textcolor(11);
			gotoxy(27, 34);
			printf("�� ���ͷ� 50%% �̻�");
			Sleep(300);
			textcolor(15);
		}
			
		if (rate >= 100) {
			achieve++;
			textcolor(11);
			gotoxy(27, 35);
			printf("�� ���ͷ� 100%% �̻�");
			Sleep(300);
			textcolor(15);
		}
			
		// ���� �ð� Ȯ��
		if (time_s >= 30) {
			achieve++;
			textcolor(11);
			gotoxy(27, 37);
			printf("�� ���� �ð� 30�� �̻�");
			Sleep(300);
			textcolor(15);
		}
			
		if (time_s >= 60) {
			achieve++;
			textcolor(11);
			gotoxy(27, 38);
			printf("�� ���� �ð� 60�� �̻�");
			Sleep(300);
			textcolor(15);
		}
			
		if (time_s >= 90) {
			achieve++;
			textcolor(11);
			gotoxy(27, 39);
			printf("�� ���� �ð� 90�� �̻�");
			Sleep(300);
			textcolor(15);
		}
			

		// ������ ���� ȣĪ �ο�
		Sleep(300);
		gotoxy(55, 27);
		printf("����    �� �޼�!");
		textcolor(14);
		gotoxy(58, 27);
		printf("%d", achieve);
		textcolor(15);
		gotoxy(55, 29);
		printf("�����               �Դϴ�! ");
		textcolor(14);
		gotoxy(59, 29);

		if (achieve <= 3)
			printf("����� ����");
		else if (achieve <= 5) {
			printf("���۰���");
			gotoxy(65 + 4, 10 + 3);
			textcolor(4);
			printf("��");
		}
		else if (achieve <= 8) {
			printf("���ڿ� ����");
			gotoxy(65, 10);
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 7; j++) {
					if (crown[i][j] == 1) {
						gotoxy(65 + j, 10 + i);
						textcolor(6);
						printf("��");
					}
				}
			}
		}
		else if (achieve == 9) {
			printf("�������� ����");
			gotoxy(65, 15);
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 6; j++) {
					if (neckTie[i][j] == 1) {
						gotoxy(65 + j, 15 + i);
						textcolor(9);
						printf("��");
					}
				}
			}

		}


		getch(); 


		
	}
}


void isGoal() {
	if ((double)coin > (double)seed * 2.0) { // 2�迡�� ��� �� �� ������ double������ �ٲپ���ҽ��ϴ�
		switch (level) {
		case 0 :
			level++;
			seed = coin;
			// ������ �ؽ�Ʈ
			gotoxy(8, antY-1);
			textcolor(11);
			printf("LEVEL UP  ");
			textcolor(15);
			break;
		case 1:
			level++;
			seed = coin;
			gotoxy(8, antY-1);
			textcolor(11);
			printf("LEVEL UP  ");
			textcolor(15);
			break;
		default :
			break;
		}
	}
}

int isWarrenBuffit() {	// ���� ���� ���� 30�� �̻�, ���ͷ� 100% �̻�, ���� �ð� 90�� �̻� -> ��������! -> ���� ����
	int property = 0;
	//clock_t now = clock();
	//double survive = (double)(now - warrenStart);

	for (int b = 0; b < 5; b++)
		property += QuantityList[b];

	if (rate >= 100 && property >= 30 && time_s >= 90) {
		return 1;
	}
	return 0;
}

void drawWarrenBuffit() {
	system("cls");
	gotoxy(27, 27);
	printf("����");
	gotoxy(27, 29);
	printf("�� ���� ���� ���� 5�� �̻�");
	gotoxy(27, 30);
	printf("�� ���� ���� ���� 15�� �̻�");
	gotoxy(27, 31);
	printf("�� ���� ���� ���� 30�� �̻�");
	gotoxy(27, 33);
	printf("�� ���ͷ� 10%% �̻�");
	gotoxy(27, 34);
	printf("�� ���ͷ� 50%% �̻�");
	gotoxy(27, 35);
	printf("�� ���ͷ� 100%% �̻�");
	gotoxy(27, 37);
	printf("�� ���� �ð� 30�� �̻�");
	gotoxy(27, 38);
	printf("�� ���� �ð� 60�� �̻�");
	gotoxy(27, 39);
	printf("�� ���� �ð� 90�� �̻�");
	Sleep(600);

	textcolor(11);
	gotoxy(27, 29);
	printf("�� ���� ���� ���� 5�� �̻�");
	Sleep(300);
	textcolor(15);

	textcolor(11);
	gotoxy(27, 30);
	printf("�� ���� ���� ���� 15�� �̻�");
	Sleep(300);
	textcolor(15);

	textcolor(11);
	gotoxy(27, 31);
	printf("�� ���� ���� ���� 30�� �̻�");
	Sleep(300);
	textcolor(15);

	textcolor(11);
	gotoxy(27, 33);
	printf("�� ���ͷ� 10%% �̻�");
	Sleep(300);
	textcolor(15);

	textcolor(11);
	gotoxy(27, 34);
	printf("�� ���ͷ� 50%% �̻�");
	Sleep(300);
	textcolor(15);

	textcolor(11);
	gotoxy(27, 35);
	printf("�� ���ͷ� 100%% �̻�");
	Sleep(300);
	textcolor(15);

	textcolor(11);
	gotoxy(27, 37);
	printf("�� ���� �ð� 30�� �̻�");
	Sleep(300);
	textcolor(15);

	textcolor(11);
	gotoxy(27, 38);
	printf("�� ���� �ð� 60�� �̻�");
	Sleep(300);
	textcolor(15);

	textcolor(11);
	gotoxy(27, 39);
	printf("�� ���� �ð� 90�� �̻�");
	Sleep(300);
	textcolor(15);

	system("cls");

	Sleep(300);

	int i;
	int j;
	int  k;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			gotoxy(30 + j, 10 + i);
			if (antFace[i][j] == 1) {
				printf("��");
			}
		}
	}

	gotoxy(0, 10 + 5);
	textcolor(4);
	for (i = 0; i < 36; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 10; k++) {
				gotoxy(0 + i + k, 10 + 5 + j);
				textcolor(4);
				if (warrenGlasses[j][k] == 1) {
					printf("��");
				}
			}
		}
		Sleep(200);
		if (i == 35) {
			break;
		}
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 10; k++) {
				gotoxy(0 + i + k, 10 + 5 + j);
				if (warrenGlasses[j][k] == 1) {
					printf("  ");
				}
			}
		}
		textcolor(15);
		for (j = 0; j < 20; j++) {
			for (k = 0; k < 20; k++) {
				gotoxy(30 + k, 10 + j);
				if (antFace[j][k] == 1) {
					printf("��");
				}
			}
		}
	}
	;
	textcolor(9);
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 8; j++) {
			for (k = 0; k < 6; k++) {
				gotoxy(30 + 7 + k, 32 - i + j);
				if (warrenNeckTie[j][k] == 1) {
					printf("��");
				}
			}
		}
		if (i == 4) {
			break;
		}
		Sleep(200);
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 6; k++) {
				gotoxy(30 + 7 + k, 32 - i + j);
				if (warrenNeckTie[j][k] == 1) {
					printf("  ");
				}
			}
		}
	}

	textcolor(6);
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 8; k++) {
				gotoxy(30 + 6 + k, 1 + i + j);
				if (warrenCrown[j][k] == 1) {
					printf("��");
				}
			}
		}
		if (i == 7) {
			break;
		}
		Sleep(200);
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 8; k++) {
				gotoxy(30 + 6 + k, 1 + i + j);
				if (warrenCrown[j][k] == 1) {
					printf("  ");
				}
			}
		}
	}
	Sleep(100);
	gotoxy(60, 10);
	printf("����� ���̰��� ���������Դϴ�.");
	
	getch();
}