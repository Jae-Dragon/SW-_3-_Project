#pragma once

#define Market_WIDTH 35
#define Market_HEIGHT 26
#define Market_ORIGIN_X 60
#define Market_ORIGIN_Y 14
clock_t start;

int distance = 0;//비거리에 따른 거래소 호출을 위해 호출
int coin = 10000;
char name[10]; // 플레이어 이름
int level; // 선택된 난이도
int life = 100;

int cash_id = 0; // 0 ~ 3
int cashX = 60, cashY = 20;// 초기 값
int antY; // 개미출력 시작부분(y좌표)
int pre_ant = 26; //  개미의 바로 이전 위치 (y좌표)
int speed = 10; 
int bomb_id = 0;
int bombX = 60, bombY = 30;// 초기 값
int cashColor = 1; // 랜덤아이템
int hurdleX = 60, hurdleY = 31;
int hurdle_id = 2;