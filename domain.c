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
char StockList[5][30];

void Title();

void Stock();
void Event();

int main()
{
	RemoveCursor();
	system("mode con cols=130 lines=34");
	//cols = ĭ/�� (����)  lines = ��/�� (����)

	Title();
	Event();

	return 0;
}

void Stock()
{
	strcpy(StockList[0], "����");
	strcpy(StockList[1], "���");
	strcpy(StockList[2], "�ݵ�ü");
	strcpy(StockList[3], "����");
	strcpy(StockList[4], "��ö");
}

void Event()
{
	//¦����° --> �ְ��϶� ����,  Ȧ����° --> �ְ���� ����

	strcpy(EventList[0], "��� ���ۿ� �߻�������");//����ȸ�� �ְ� �϶�
	strcpy(EventList[1], "�߻�");//����ȸ�� �ְ� ���

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


	gotoxy(5, 3);
	printf("%s\n", EventList[0]);
	gotoxy(5, 4);
	printf("%s\n", EventList[1]);
	gotoxy(5, 5);
	printf("%s\n", EventList[2]);
}

