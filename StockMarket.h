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
#include "visible.h"//�⺻������ ��¸� �����ϴ� �Լ��鸸 ��Ƶδ� ��(���� ���)
#include "StockMarket.h"//�ŷ��� ���� �Լ��鸸 ��Ƶδ� ��(��� ���)
#include "item.h"//������ ���� �Լ��鸸 ��Ƶδ� ��(��� ���)
#include "status.h"//����â ���� �Լ��鸸 ��Ƶδ� ��(���� ���)

char EventList1[40][60];//Ư�� ���� ����
char EventList2[30][30];//��ü �ְ� ����
char StockList[5][30];//���� ����
int PriceList[5];//�� ������ �ְ�
int QuantityList[5];//�� ������ ������


//�����ؾ� �� ���� 
//1. �ְ��� �ŷ��� ��� �� ǥ�õž� �� --> �����Ϸ�
//2. �÷��̾ ��� �Ĵ� ���� ������ �� �ֵ��� �ؾ���(�Է� �޾��� �� ���� ����� ����) -->
//3. �ְ��� �ŷ��ҿ��� �����ǵ��� �ؾ� ��, Result�Լ����� ��ġ ����
//4. �ֽ� ���� ���� ��Ȳ�� �� �� �ֵ��� �ؾ� ��

void Stock()
{
	//���� �Է¹ް� �� ������ ��ȣ ��ȯ
	strcpy(StockList[0], "���̿�");//0, 1
	strcpy(StockList[1], "���");//2, 3
	strcpy(StockList[2], "�ݵ�ü");
	strcpy(StockList[3], "����");
	strcpy(StockList[4], "�ڵ���");

	//�� ������ �� �ʱ�ȭ
	QuantityList[0] = 0;
	QuantityList[1] = 0;
	QuantityList[2] = 0;
	QuantityList[3] = 0;
	QuantityList[4] = 0;
}

void Event()
{
	//¦����° --> �ְ��϶� ����,  Ȧ����° --> �ְ���� ����
	// ��Ȳ�� 2���� �з�
	// Ư�� ���� ������ ��ġ�� �̺�Ʈ�� ��ü���� ���� ������ ��ġ�� �̺�Ʈ�� ���� 
	//StockList 0:����, 1:���, 2:�ݵ�ü, 3:����, 4:��ö

	//�ʱ� �ֽ� ����
	PriceList[0] = 500;
	PriceList[1] = 500;
	PriceList[2] = 500;
	PriceList[3] = 500;
	PriceList[4] = 500;

	//�� ���� �̺�Ʈ
	strcpy(EventList1[0], "��� ���ۿ� �߻�");//���̿�ȸ�� �ְ� �϶�
	strcpy(EventList1[1], "������ �߻�");//���̿�ȸ�� �ְ� ���
	strcpy(EventList1[2], "�̱��� �ڱ���� ��ȣ�� ���� ������� ����ŰƮ �������");//���̿�ȸ�� �ְ� �϶�
	strcpy(EventList1[3], "�̱��� ������� ����ŰƮ �������");//���̿�ȸ�� �ְ� ���
	strcpy(EventList1[4], "Ż��� ġ���� ���ۿ� �߻�");//���̿�ȸ�� �ְ� �϶�
	strcpy(EventList1[5], "Ż�� ġ���� ���� ����!!!");//���̿�ȸ�� �ְ� ���

	strcpy(EventList1[6], "����ü���� �� �߻�");//��� ���� �ְ� �϶�
	strcpy(EventList1[7], "������ ���ؾ����� �̻��� �߻�");//��� ���� �ְ� ���
	strcpy(EventList1[8], "������ ������ ���� ����");//��� ���� �ְ� �϶�
	strcpy(EventList1[9], "���ѹα�, �����忡 K9 ������ ����");//��� ���� �ְ� ���
	strcpy(EventList1[10], "�߱��� �̱��� ���� ���� ��ȭ ���� ü�� ");//��� ���� �ְ� �϶�
	strcpy(EventList1[11], "���þƿ� ��ũ���̳��� ����߹�");//��� ���� �ְ� ���

	strcpy(EventList1[12], "�̱� ���ķ� ���� �Ｚ���� ����ƾ ���� ���� �ߴ�");//�ݵ�ü ���� �ְ� �϶�
	strcpy(EventList1[13], "�ݵ�ü ���޳����� ���� �̱��� �ݵ�ü ��� ���� ��ȭ");//�ݵ�ü ���� �ְ�
	strcpy(EventList1[14], "���� ��� ���� ���� ����");//�ݵ�ü ���� �ְ� �϶�
	strcpy(EventList1[15], "��Ʈ������ ä�� ���� ����");//�ݵ�ü ���� �ְ�
	strcpy(EventList1[16], "�������� ���� �ݵ�ü ���� ���� �ߴ�");//�ݵ�ü ���� �ְ� �϶�
	strcpy(EventList1[17], "Ŭ���� ����� Ȯ������ ���� ������ D�� ���� ����");//�ݵ�ü ���� �ְ�

	strcpy(EventList1[18], "���� ������ �޵�");//���� ���� �ְ� �϶�(������ �ֿ� ������)
	strcpy(EventList1[19], "�ݵ�ü ���޳����� ���� �̱��� �ݵ�ü ��� ���� ��ȭ");//���� ���� �ְ� ���
	strcpy(EventList1[20], "īŸ������ LNG ��ݼ� ��빮���� �ΰ� ���� �߻�");//���� ���� �ְ� �϶�(������ �ֿ� ������)
	strcpy(EventList1[21], "īŸ������ LNG ��ݼ� ���� ���� ��� ����");//���� ���� �ְ� ���

	strcpy(EventList1[22], "���� ���� �ڵ��� ��� ������ ���� �θ����� �߻�");//�ڵ��� ���� �ְ� �϶�
	strcpy(EventList1[23], "�������� ������� �߰��� ���� ����");//�ڵ��� ���� �ְ� ���
	strcpy(EventList1[24], "������ �� ���� �� ���� ���� ���� ���� ���� ����");//�ڵ��� ���� �ְ� �϶�
	strcpy(EventList1[25], "�������� ��Ⱓ ������ SUV ���");//�ڵ��� ���� �ְ� ���
	strcpy(EventList1[26], "ȯ������� ���� ���� ������ ���߱��� ���� ��ȭ");//�ڵ��� ���� �ְ� �϶�
	strcpy(EventList1[27], "���翡 ��ϵ� ����� ���� �ټ� �� ħ��");//�ڵ��� ���� �ְ� ���

	//��ü �ְ� ���� �̺�Ʈ
	strcpy(EventList2[0], "��ü���� ������ ������ ���");//�ְ� �϶�
	strcpy(EventList2[1], "��ü���� ������ ������ ����");//�ְ� ���
	strcpy(EventList2[2], "��ȭ�� ȯ���� ����Ͽ���");//�ְ� �϶� -->���ѹα� ��ȭ�� ��ġ�� ���� ������ �Ǳ� ����
	strcpy(EventList2[3], "��ȭ�� ȯ���� �϶��Ͽ���");//�ְ� ���
	strcpy(EventList2[4], "��ݸ��� �ô밡 �����Ͽ���");//�ְ� �϶� -->ä���� ���䰡 �����ϰ� �ֽ��� ����� ����
	strcpy(EventList2[5], "���ݸ��� �ô밡 �����Ͽ���");//�ְ���� -->ä���� ���䰡 �����ϰ� �ֽ� ���� ����
	strcpy(EventList2[6], "�ݸ��� �϶� �߼��� ���Ƽ���");//�ְ��϶� -->ä�Ǹż��� ���� ä�� ���� ����, �ֽ� �ŵ�
	strcpy(EventList2[7], "�ݸ��� ��� �߼��� ���Ƽ���");//�ְ���� -->ä�Ǹŵ��� ���� ä�� ���� �϶�, �ֽ� �ż�
	strcpy(EventList2[8], "�������� ���ڸ� ����ߴ�");//�ְ��϶� --> �ؿ��ڱ� ���� --> ������� ��ȭ
	strcpy(EventList2[9], "�������� ���ڸ� ����ߴ�");//�ְ���� --> �ؿ��ڱ� ���� --> ������� ȣ��
	strcpy(EventList2[10], "������ ����Ͽ���");//�ְ��϶� -->�������� ��ȭ�ǰ� ��������� ��ȭ(�����簪�� ����)
	strcpy(EventList2[11], "������ �϶��Ͽ���");//�ְ���� -->�������� ȣ���ǰ� ��������� ȣ��(�����簪�� ����)



	//�߰��Ǹ� Random�� ���� ������ ������ �������
}

int Random(int min, int max)
{
	srand(time(NULL));
	int random = 0;
	random = rand() % (max - min) + min;

	return random;
}

void EraseDeal()
{
	gotoxy(32, 23);
	printf("                                                     ");

	gotoxy(32, 25);
	printf("                                                     ");


	gotoxy(32, 27);
	printf("                                                     ");
	gotoxy(32, 29);
	printf("                                                     "); 


	gotoxy(32, 34);
	printf("                                                                 ");
	gotoxy(32, 35);
	printf("                   ");
}

void Deal()
{
	int c, b, s, q;
	while (1)
	{
		//�ɼ��� ������ �� �ֵ��� �ؾ��ϴµ� ���� 
		textcolor(15);
		gotoxy(32, 23);
		printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���(�ż�: 1��, �ŵ�: 2��, ����: 3��)");//�������� �۾��� �κ�

		gotoxy(32, 25);
		printf("�ɼ� ����: "); scanf("%d", &c);

		if (c == 3) break;//�ݺ��� Ż��

		else if (c == 1)//�ż�
		{
			gotoxy(32, 27);
			printf("�ŷ��� ����ϴ� ������ ��ȣ�� �Է����ּ���: "); scanf("%d", &b);
			gotoxy(32, 29);
			printf("���Ͻô� ������ �ż����� �Է����ּ���: "); scanf("%d", &q);

			if (coin < PriceList[b] * q) {
				textcolor(13);
				gotoxy(32, 32);
				printf("���� ������ �����մϴ�!!!");
				textcolor(15);
			}
			else {
				coin -= PriceList[b] * q;//���� ����
				QuantityList[b] += q;//������ �ֽ��� �� ������Ʈ
			}

		}

		else if (c == 2)//�ż�
		{
			gotoxy(32, 27);
			printf("�ŷ��� ����ϴ� ������ ��ȣ�� �Է����ּ���: "); scanf("%d", &s);
			gotoxy(32, 29);
			printf("���Ͻô� ������ �ŵ����� �Է����ּ���: "); scanf("%d", &q);

			if (QuantityList[s] < q)
			{
				textcolor(13);
				gotoxy(32, 32);
				printf("���� �ֽķ��� �����մϴ�!!!");
				textcolor(15);
			}
			else {
				coin += PriceList[s] * q;//
				QuantityList[s] -= q;//�ŵ��� �ֽ��� �� ������Ʈ
			}
		}
		int M;
		gotoxy(32, 34);
		printf("���Ḧ ���Ͻø� 0��, �ŷ��� ����Ͻñ⸦ ���Ͻø� 1���� �����ʽÿ�");
		gotoxy(32, 36);
		printf("��ȣ�Է�: "); scanf("%d", &M);

		if (M == 0) break;

		EraseDeal();//
		Sleep(1000);
	}
}

void Opinion(char* YorN, int* Choice, int* random1, int* random2)
{
	
	*random1 = Random(0, 21);//�̺�Ʈ�� �߰��Ǵ� ��ŭ ������ �Ķ���͸� �÷��� ��
	textcolor(10);
	gotoxy(32, 10);
	printf("News: %s", EventList1[*random1]);
	Sleep(1000);
	*random2 = Random(0, 11);//�̺�Ʈ�� �߰��Ǵ¸�ŭ ������ �Ķ���͸� �÷��� ��
	gotoxy(32, 12);
	printf("News: %s", EventList2[*random2]);
	Sleep(1000);

	textcolor(13);
	gotoxy(32, 16);
	printf("���ڻ�ǰ ���");
	textcolor(15);
	gotoxy(32, 18);
	Sleep(100);
	printf("����: 1.%s || 2.%s || 3.%s || 4.%s || 5.%s", StockList[0], StockList[1], StockList[2], StockList[3], StockList[4]);
	
	gotoxy(32, 19);
	printf("====================================================================");

	gotoxy(32, 20);
	printf("�ְ�: 1.%d    || 2.%d  || 3.%d    || 4.%d  || 5.%d", PriceList[0], PriceList[1], PriceList[2], PriceList[3], PriceList[4]);

	Deal();//�ż��ŵ� ��� �߰�
	

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

int Result(char YorN, int Choice, int RandEvent1, int RandEvent2)//���ʺ��� ���ʴ�� ���ڿ���, ���� ����, ���� �̺�Ʈ
{
	int revenue = 0;
	if (YorN == 'N') return 0;
	
	//EventList2���� �� ���񿡼� ¦����°�� ����, Ȧ����°�� ȣ����
	//0~21 
	else {
		if (RandEvent2 % 2 == 0)
			revenue -= coin * 0.2;
		else
			revenue += coin * 0.1;
	}



	//EventList1���� �� ���񿡼� ¦����°�� ����, Ȧ����°�� ȣ����
	//0~5�� ���̿� ����, // 6~11�� ��� ���� // 12~17�� �ݵ�ü ���� // 18~21�� ���� ����

	if (RandEvent1 % 2 == 0)//������ ��
	{
		if (RandEvent1 >= 0 && RandEvent1 <= 5)//���̿� ���� �ֶ��
		{
			if (Choice == 1) revenue -= coin * 0.4;
		}
		if (RandEvent1 >= 6 && RandEvent1 <= 11)//��� ���� �ֶ��
		{
			if (Choice == 2) revenue -= coin * 0.4;
		}
		if (RandEvent1 >= 12 && RandEvent1 <= 17)//�ݵ�ü ���� �ֶ��
		{
			if (Choice == 3) revenue -= coin * 0.4;
		}
		if (RandEvent1 >= 18 && RandEvent1 <= 21)//�ݵ�ü ���� �ֶ��
		{
			if (Choice == 4) revenue -= coin * 0.4;
		}
		if (RandEvent1 >= 22 && RandEvent1 <= 27)//�ڵ��� ���� �ֶ��
		{
			if (Choice == 5) revenue -= coin * 0.4;
		}
	}

	else//ȣ���� ��
	{
		if (RandEvent1 >= 0 && RandEvent1 <= 5)//���̿� ���� �ֶ��
		{
			if (Choice == 1) revenue += coin * 0.35;
		}
		if (RandEvent1 >= 6 && RandEvent1 <= 11)//��� ���� �ֶ��
		{
			if (Choice == 2) revenue += coin * 0.35;
		}
		if (RandEvent1 >= 12 && RandEvent1 <= 17)//�ݵ�ü ���� �ֶ��
		{
			if (Choice == 3) revenue += coin * 0.35;
		}
		if (RandEvent1 >= 18 && RandEvent1 <= 21)//�ݵ�ü ���� �ֶ��
		{
			if (Choice == 4) revenue += coin * 0.35;
		}
		if (RandEvent1 >= 22 && RandEvent1 <= 27)//�ڵ��� ���� �ֶ��
		{
			if (Choice == 5) revenue += coin * 0.35;
		}
	}


	//�켱 �� ���� ���� ���ͷ� ������ ���ؾ� ��
	//EventList2���� �߻��ϴ� ��ǵ� �� �ְ��� ũ�� ������ ��ġ�� �κа� �׷��� ���� �κ��� ������ ��
	//��Ʈ �׸� �߰��� �ʿ���, ��Ȯõ���� �븱 �� �ֵ��� �ϴ� ��� �߰��� �߿��غ���

	return revenue;
}

void StockMarket()
{
	int Choice, random1, random2, revenue = 0;
	char YORN;

	Drawingmarket();//�ŷ��� ���� �׷��ֱ�
	Opinion(&YORN, &Choice, &random1, &random2);//�÷��̾��� ���� ����
	Sleep(600);


	revenue = Result(YORN, Choice, random1, random2);//���ͷ� ��ȯ
	//�׷��� ���������� ������ Gold�� + - revenue�� ����

	coin += revenue;//��忡 ���ͷ� ��ȯ����

	//�� �����δ� ��� �۾��� ���� �Ŀ� ����
	EraseMarket();//�� ������ �޸��� ȭ������ ��ȯ�ϱ� �� �ŷ��Ҹ� ������
	EraseOpinion();
	system("cls");
}

