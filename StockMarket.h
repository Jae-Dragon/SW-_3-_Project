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
	//���� �Է¹ް� �� ������ ��ȣ ��ȯ

	strcpy(StockList[0], "���� X");
	strcpy(StockList[1], "���");//2, 3
	strcpy(StockList[2], "�ݵ�ü");
	strcpy(StockList[3], "����");
	strcpy(StockList[4], "��ö");
	strcpy(StockList[5], "����");//0, 1
}

void Event()
{
	//¦����° --> �ְ��϶� ����,  Ȧ����° --> �ְ���� ����
	//StockList 0:����, 1:���, 2:�ݵ�ü, 3:����, 4:��ö
	
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



	//�߰��Ǹ�  Random�� ���� ������ ������ �������
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
	
	*random1 = Random(0, 15);//�̺�Ʈ�� �߰��Ǵ� ��ŭ ������ �Ķ���͸� �÷��� ��
	textcolor(10);
	gotoxy(13, 3);
	printf("News: %s", EventList[*random1]);
	Sleep(1000);
	*random2 = Random(0, 15);//�̺�Ʈ�� �߰��Ǵ¸�ŭ ������ �Ķ���͸� �÷��� ��
	gotoxy(13, 5);
	printf("News: %s", EventList[*random2]);
	Sleep(1000);

	textcolor(13);
	gotoxy(14, 8);
	printf("���ڻ�ǰ ���");
	textcolor(15);
	gotoxy(14, 10);
	Sleep(1000);
	printf("1.%s, 2.%s, 3.%s, 4.%s, 5.%s", StockList[0], StockList[1], StockList[2], StockList[3], StockList[4]);

	gotoxy(14, 12);
	Sleep(100);
	printf("��ǰ�� �����ϰ� �����ø� Y��, �ƴ϶�� N�� �Է����ּ���: ");
	scanf("%c", YorN);
	getchar();
	Sleep(50);
	if (*YorN == 'N') return;

	gotoxy(14, 14);
	printf("�����ϰ� ���� ��ǰ�� ��ȣ�� �Է��ϼ���: ");

	gotoxy(14, 16);
	printf("�ִ� 2������ ����, 2�� �� 1������ ���� ����");//�������� �۾��� �κ�
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

	Drawingmarket();//�ŷ��� ���� �׷��ֱ�
	Opinion(&YORN, &Choice, &random1, &random2);//�÷��̾��� ���� ����
	Sleep(600);


	revenue = Result(YORN, Choice, random1, random2);//���ͷ� ��ȯ
	//�׷��� ���������� ������ Gold�� +- revenue�� ����




	//�� �����δ� ��� �۾��� ���� �Ŀ� ����
	EraseMarket();//�� ������ �޸��� ȭ������ ��ȯ�ϱ� �� �ŷ��Ҹ� ������
	EraseOpinion();
}

int Result(char YorN, int Choice, int RandEvent1, int RandEvent2)//���ʺ��� ���ʴ�� ���ڿ���, ���� ����, ���� �̺�Ʈ
{
	if (YorN == 'N') return 0;

	//0, 1�� ���� ����, // 2, 3�� ��� ���� // �������� ���� �ش��

	
}