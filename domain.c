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

#define Market_WIDTH 35
#define Market_HEIGHT 20
#define Market_ORIGIN_X 25
#define Market_ORIGIN_Y 7


char EventList[30][30];
char StockList[30][30];

void Title();

void Stock();
void Event();
int Random(int min, int max);
void Opinion(int* Choice, char * YorN);
void Drawingmarket();
void EraseMarket();
void EraseOpinion();
void StockMarket();

int main()
{
	RemoveCursor();
	system("mode con cols=130 lines=34");
	//cols = ĭ/�� (����)  lines = ��/�� (����)
	//Title();
	Event();//�ʱ⿡ �̺�Ʈ ����Ʈ ���� ���� ���� �ʿ�
	Stock();//�ʱ� �������� ����Ʈ ���� ���� ���� �ʿ�

	StockMarket();


	return 0;
}

void Stock()
{
	//���� �Է¹ް� �� ������ ��ȣ ��ȯ

	strcpy(StockList[0], "����");//0, 1
	strcpy(StockList[1], "���");//2, 3
	strcpy(StockList[2], "�ݵ�ü");
	strcpy(StockList[3], "����");
	strcpy(StockList[4], "��ö");

}

void Event()
{
	//¦����° --> �ְ��϶� ����,  Ȧ����° --> �ְ���� ����

	strcpy(EventList[0], "��� ���ۿ� �߻�");//����ȸ�� �ְ� �϶�
	strcpy(EventList[1], "������ �߻�");//����ȸ�� �ְ� ���

	strcpy(EventList[2], "����ü���� �� �߻�");//��� ���� �ְ� �϶�
	strcpy(EventList[3], "������ ���ؾ����� �̻��� �߻�");//��� ���� �ְ� ���

	strcpy(EventList[4], "��ü���� ������ ������ ���");//�ְ� �϶�
	strcpy(EventList[5], "��ü���� ������ ������ ����");//�ְ� ���
	strcpy(EventList[6], "��ȭ�� ȯ���� ����Ͽ���");//�ְ� �϶� -->���ѹα� ��ȭ�� ��ġ�� ���� ������ �Ǳ� ����
	strcpy(EventList[7], "��ȭ�� ȯ���� �϶��Ͽ���");//�ְ� ���
	strcpy(EventList[8], "��ݸ��� �ô밡 �����Ͽ���");//�ְ� �϶� -->ä���� ���䰡 �����ϰ� �ֽ��� ����� ����
	strcpy(EventList[9], "���ݸ��� �ô밡 �����Ͽ���");//�ְ���� -->ä���� ���䰡 �����ϰ� �ֽ� ���� ����
	strcpy(EventList[10], "�ݸ��� �϶� �߼��� ���Ƽ���");//�ְ��϶� -->ä�Ǹż��� ���� ä�� ���� ����, �ֽ� �ŵ�
	strcpy(EventList[11], "�ݸ��� ��� �߼��� ���Ƽ���");//�ְ���� -->ä�Ǹŵ��� ���� ä�� ���� �϶�, �ֽ� �ż�
	strcpy(EventList[12], "�������� ���ڸ� ����ߴ�");//�ְ��϶� --> �ؿ��ڱ� ���� --> ������� ��ȭ
	strcpy(EventList[13], "�������� ���ڸ� ����ߴ�");//�ְ���� --> �ؿ��ڱ� ���� --> ������� ȣ��
	strcpy(EventList[14], "������ ����Ͽ���");//�ְ��϶� -->�������� ��ȭ�ǰ� ��������� ��ȭ(�����簪�� ����)
	strcpy(EventList[15], "������ �϶��Ͽ���");//�ְ���� -->�������� ȣ���ǰ� ��������� ȣ��(�����簪�� ����)

	int random;

	/*
	for (int i = 0; i < 10; i++)
	{
		random = Random(0, 15);
		gotoxy(i, i);
		printf("%s\n", EventList[random]);

		Sleep(1000);
	}
	*/
}

int Random(int min, int max)
{
	srand(time(NULL));
	int random = 0;
	random = rand() % (max - min) + min;

	return random;
}

void Opinion(int* Choice, char* YorN)
{
	textcolor(13);
	gotoxy(14,8);
	printf("���ڻ�ǰ ���");

	textcolor(15);
	gotoxy(14, 10);
	printf("1.%s, 2.%s, 3.%s, 4.%s, 5.%s", StockList[0], StockList[1], StockList[2], StockList[3], StockList[4]);

	gotoxy(14, 12);
	printf("��ǰ�� �����ϰ� �����ø� Y��, �ƴ϶�� N�� �Է����ּ���: ");
	scanf("%c", YorN);


	gotoxy(14, 14);
	printf("�����ϰ� ���� ��ǰ�� ��ȣ�� �Է��ϼ���: ");
	scanf("%d", Choice);
	
	getchar();
}

void Drawingmarket()
{
	int x, y;

	for (x = 2; x <= 2 * Market_WIDTH + 16; x++) {
		SetCurrentCursorPos(Market_ORIGIN_X + x - 8, Market_ORIGIN_Y);

		printf("��");
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
			printf("��");//�� �� ��
		}

		else {
			printf("��");
		}
	}


	for (x = 2; x <= 2 * Market_WIDTH; x++) {
		SetCurrentCursorPos(Market_ORIGIN_X + x, Market_ORIGIN_Y + Market_HEIGHT);

		printf("��");
	}

	for (y = 0; y <= Market_HEIGHT; y++) {
		SetCurrentCursorPos(Market_ORIGIN_X + 2 * Market_WIDTH + 2, Market_ORIGIN_Y + y);//

		if (y == Market_HEIGHT) {
			printf("��");//����
		}

		else {
			printf("��");
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
	textcolor(13);
	gotoxy(14, 8);
	printf("                                                               ");

	textcolor(15);
	gotoxy(14, 10);
	printf("                                                               ");

	gotoxy(14, 12);
	printf("                                                               ");

	gotoxy(14, 14);
	printf("                                                               ");

}

void StockMarket()
{
	int a;
	char YORN;

	Drawingmarket();//�ŷ��� ���� �׷��ֱ�
	Opinion(&a, &YORN);//�÷��̾��� ���� ����
	Sleep(600);

	EraseMarket();//�� ������ �޸��� ȭ������ ��ȯ�ϱ� �� �ŷ��Ҹ� ������
	EraseOpinion();
}
