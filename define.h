#pragma once

#define Market_WIDTH 35
#define Market_HEIGHT 26
#define Market_ORIGIN_X 60
#define Market_ORIGIN_Y 14
clock_t start;

int distance = 0;//��Ÿ��� ���� �ŷ��� ȣ���� ���� ȣ��
int coin = 10000;
char name[10]; // �÷��̾� �̸�
int level; // ���õ� ���̵�
int life = 100;

int cash_id = 0; // 0 ~ 3
int cashX = 60, cashY = 20;// �ʱ� ��
int antY; // ������� ���ۺκ�(y��ǥ)
int pre_ant = 26; //  ������ �ٷ� ���� ��ġ (y��ǥ)
int speed = 10; 
int bomb_id = 0;
int bombX = 60, bombY = 30;// �ʱ� ��
int cashColor = 1; // ����������
int hurdleX = 60, hurdleY = 31;
int hurdle_id = 2;