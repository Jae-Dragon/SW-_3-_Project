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

char **EVENT_LIST;

void Title();

void EVENT();

int main()
{
	RemoveCursor();
	system("mode con cols=130 lines=34");
	//cols = ĭ/�� (����)  lines = ��/�� (����)

	Title();

	gotoxy(10, 3);
	EVENT();

	return 0;
}

void Title()
{
	COORD curPos;
	//curPos = GetCurrentCursorPos();
	//�ֽ����� 5��� ���ּ���

	curPos.X = 60; curPos.Y = 15;
	SetCurrentCursorPos(curPos.X, curPos.Y);
	textcolor(14);
	printf("������ �ֽĿ�!!!\n");
	getchar();
	textcolor(15);
}

void EVENT()
{
	EVENT_LIST = (char**)malloc(sizeof(char*)*20);

	EVENT_LIST[0] = "������ �߻�";//����ȸ�� �ְ� ���
	EVENT_LIST[1] = "��� ���ۿ� �߻�";//����ȸ�� �ְ� �϶�

	EVENT_LIST[2] = "����ü���� �� �߻�";//��� ���� �ְ� �϶�
	EVENT_LIST[3] = "������ ���ؾ����� �̻��� �߻�";//��� ���� �ְ� ���

	EVENT_LIST[4] = "��ü���� ������ ������ ���";//�ְ� �϶�
	EVENT_LIST[5] = "��ü���� ������ ������ ����";//�ְ� ���
	EVENT_LIST[6] = "��ȭ�� ȯ���� ����Ͽ���";//�ְ� �϶� -->���ѹα� ��ȭ�� ��ġ�� ���� ������ �Ǳ� ����
	EVENT_LIST[7] = "��ȭ�� ȯ���� �϶��Ͽ���";//�ְ� ���
	EVENT_LIST[8] = "��ݸ��� �ô밡 �����Ͽ���";//�ְ� �϶� -->ä���� ���䰡 �����ϰ� �ֽ��� ����� ����
	EVENT_LIST[9] = "���ݸ��� �ô밡 �����Ͽ���";//�ְ���� -->ä���� ���䰡 �����ϰ� �ֽ� ���� ����
	EVENT_LIST[10] = "�ݸ��� �϶� �߼��� ���Ƽ���";//�ְ��϶� -->ä�Ǹż��� ���� ä�� ���� ����, �ֽ� �ŵ�
	EVENT_LIST[11] = "�ݸ��� ��� �߼��� ���Ƽ���";//�ְ���� -->ä�Ǹŵ��� ���� ä�� ���� �϶�, �ֽ� �ż�
	EVENT_LIST[12] = "�������� ���ڸ� ����ߴ�";//�ְ��϶� --> �ؿ��ڱ� ���� --> ������� ��ȭ
	EVENT_LIST[13] = "�������� ���ڸ� ����ߴ�";//�ְ���� --> �ؿ��ڱ� ���� --> ������� ȣ��
	EVENT_LIST[14] = "������ ����Ͽ���";//�ְ��϶� -->�������� ��ȭ�ǰ� ��������� ��ȭ(�����簪�� ����)
	EVENT_LIST[15] = "������ �϶��Ͽ���";//�ְ���� -->�������� ȣ���ǰ� ��������� ȣ��(�����簪�� ����)

}

