#pragma once

#define Market_WIDTH 35
#define Market_HEIGHT 20
#define Market_ORIGIN_X 60
#define Market_ORIGIN_Y 14

int distance = 0;//비거리에 따른 거래소 호출을 위해 호출
int coin = 10000;
char name[10]; // 플레이어 이름
int level; // 선택된 난이도
int cash_id = 0; // 0 ~ 3
int cashX = 60, cashY = 20;// 초기 값
int cashColor = 1; // 랜덤아이템
int pre_ant = 26; // 전에 개미 위치