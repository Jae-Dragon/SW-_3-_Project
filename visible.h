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


void setName()
{
    system("cls");
    gotoxy(20, 10);
    printf("�̸��� �Է����ּ��� : ");
    scanf("%s", name);
    //printf(name);
    //system("PAUSE");
}


void setLevel()
{
    //system("cls");
    textcolor(10);
    gotoxy(20, 15);
    printf("������������������ ���̵� ������������������ ");
    gotoxy(20, 16);
    printf("��                        ��");
    gotoxy(20, 17);
    printf("��   ���� ( Easy ) : 0    ��");
    gotoxy(20, 18);
    printf("��                        ��");
    gotoxy(20, 19);
    printf("��   ���� ( Normal ) : 1  ��");
    gotoxy(20, 20);
    printf("��                        ��");
    gotoxy(20, 21);
    printf("��   ����� ( Hard ) : 2  ��");
    gotoxy(20, 22);
    printf("��                        ��");
    gotoxy(20, 23);
    printf("����������������������������������������������������");

    textcolor(15);
    gotoxy(20, 24);
    printf(" ���� : ");
    scanf("%d", &level);

    if (level == 0) // ���̵� ����
    {
        coin = 30000;
        //speed = 15;
    }
    else if (level == 1) // ���̵� ����
    {
        coin = 10000;
        //speed = 10;
    }
    else if (level == 2) // ���̵� �����
    {
        coin = 5000;
        //speed = 5;
    }
        

    //printf("%d", level);
    //system("PAUSE");
}

void Title()
{
	COORD curPos;
	//curPos = GetCurrentCursorPos();
	//�ֽ����� 5��� ���ּ���

	curPos.X = 60; curPos.Y = 15;
	SetCurrentCursorPos(curPos.X, curPos.Y);
    

    textcolor(14);
    gotoxy(5, 5);
	//printf("������ �ֽĿ�!!!\n");
    printf("                              ��                                                                   ���� \n");
    gotoxy(5, 6);
    printf("                    ���      ��                                                                  ��    ��  ��\n");
    gotoxy(5, 7);
    printf("                  ��    ��    ��        ����                    ������                      ��    ��  ��\n");
    gotoxy(5, 8);
    printf("��        ��  ��  ��    ��    ��      ��      ��                  ��                               ����   ����\n");
    gotoxy(5, 9);
    printf("��        ��  ��    ���      ��      ��      ��                  ������    �����    ��      ��      ��\n");
    gotoxy(5, 10);
    printf("��        ����              ��        ����                    ��                  ��    ��      ��      ��\n");
    gotoxy(5, 11);
    printf("��        ��  ��                                                  ������        ��      ���  �����\n");
    gotoxy(5, 12);
    printf("��        ��  ��        �����    ��������                                ���      ��            ���\n");
    gotoxy(5, 13);
    printf("�����  ��  ��              ��                                ��������   ��   ��    ��           ��  ��\n");
    gotoxy(5, 14);
    printf("                        �����      ��                              ��       ��      ��   ��           ��  ��\n");
    gotoxy(5, 15);
    printf("                        ��            ��                              ��                    ��            ��� \n");
    gotoxy(5, 16);
    printf("                        �����      ������                      ��\n");
    textcolor(15);
    gotoxy(7, 23);
    printf("                                  ������������������������������ ��� Ű  ������������������������������");
    gotoxy(7, 24);
    printf("                                  ��                                      ��");
    gotoxy(7, 25);
    printf("                                  ��     ����������������                         ��");
    gotoxy(7, 26);
    printf("                                  ��     ����������������   :   ����              ��");
    gotoxy(7, 27);
    printf("                                  ��    �����̽� ��                       ��");
    gotoxy(7, 28);
    printf("                                  ��������������������������������������������������������������������������������");
    

    gotoxy(25, 31);
    printf("�����Ϸ��� Enter Ű�� �����ּ���.");
    Sleep(500);

    int on_off = 0;
    while (1)
    {
        gotoxy(25, 31);
        if (_kbhit())
        {
            break;
        }
        if (on_off % 2 == 0)
        {
            printf("�����Ϸ��� Enter Ű�� �����ּ���.");
        }
        else {
            printf("                                                            ");

        }
        RemoveCursor();
        Sleep(300);
        on_off += 1;
    }
	getchar();

    setName();
    setLevel();
    system("cls");
    
}

// �ٴ�
void Background()
{
    gotoxy(0, 35);
    for (int i = 0; i < 13; i++)
        printf("������������������������");
    
    statInfo();
}

// Ű���� �Էµ� ���� ��ȯ�ϴ� �Լ�
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}

void movingAnt()
{
    

    int isJumping = 0;
    int isBottom = 1;
    const int gravity = 3;

    int antY = 26;


    int leg = 0;
    Background();
    //int idx = 1;

    start = 0.0;
    
    // �� ���������
    gotoxy(cashX, cashY);
    ShowCash(cashModel[cash_id]);

    gotoxy(bombX, bombY);
    ShowCash(bombModel[bomb_id]);
    srand((unsigned int)time(NULL));

    while (1)
    {
        makeCash();

        //makeBomb();
        // �����̽� Ű�� ������, �ٴ��� ���� ��������
        if (GetKeyDown() == ' ' && isBottom)
        {
            isJumping = 1;
            isBottom = 0;
        }

        if (isJumping)
        {
            antY -= gravity;
        }
        else
        {
            antY += gravity;
        }

        if (antY >= 26) 
        {
            antY = 26;
            isBottom = 1;
        }

        if (antY <= 10) // ������ ���� ����
        {
            isJumping = 0;
        }

        Background();
        
        

        gotoxy(0, pre_ant);
        printf("            \n");
        printf("            \n");
        printf("            \n");
        printf("            \n");
        printf("            \n");
        printf("            \n");
        printf("            \n");
        printf("            \n");
        printf("            \n");

        gotoxy(0, antY);
        pre_ant = antY;
        printf("      ���  \n");
        printf("      ��    \n");
        printf("    �����\n");
        printf("    ���  ��\n");
        printf("    �����\n");
        printf("      ���  \n");
        printf("������  \n");
        printf("�����  \n");
        if (leg == 0)
        {
            printf(" /�� /��\n");
            leg = 1;
        }
        else
        {
            printf(" ��/ ��/\n");
            leg = 0;
        }
        
        Sleep(speed);
        //
        
        distance++;

       
      
        if (distance != 0 && distance % 100 == 0)//�ŷ��� ���� ����
        {
            system("cls");
            StockMarket();
        }
    
        gettingOld();

        if (isEnd() == 1) {
            break;
        }

        
        


    }

    

}


