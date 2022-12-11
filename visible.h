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


#define SPACE 32
#define UP 72

// ���� �迭 (�ٸ���ġ���� ���Ե�.)
char antModel[9][6] =
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

    while (1)
    {
        if (level == 0) // ���̵� ����
        {
            coin = 30000;
            seed = 30000;
            speed = 100;
            break; 
        }
        else if (level == 1) // ���̵� ����
        {
            coin = 10000;
            seed = 10000;
            speed = 50;
            break;
        }
     
        else if (level == 2) // ���̵� �����
        {
            coin = 5000;
            seed = 5000;
            speed = 10;
            break;
        }
        else
        {
            gotoxy(20, 24);
            printf("                        ");
            Sleep(700);

            textcolor(5);
            gotoxy(20, 24);
            printf("�ٽ� �����Ͻʽÿ� !");

            
            gotoxy(20, 24);
            printf("                        ");

            textcolor(15);
            Sleep(700);
            gotoxy(20, 24);
            printf(" ���� : ");
            scanf("%d", &level);
        }

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
	
    printf("                                                                                                    \n");
    gotoxy(5, 6);
    printf("                                                                                                   ����\n");
    gotoxy(5, 7);
    printf("                    ���      ��        ����                    ������                      ��    ��  ��\n");
    gotoxy(5, 8);
    printf("                  ��    ��    ��      ��      ��                  ��                              ��    ��  ��\n");
    gotoxy(5, 9);
    printf("��        ��  ��  ��    ��    ��      ��      ��                  ������    �����    ��     ����   ����\n");
    gotoxy(5, 10);
    printf("��        ��  ��    ���      ��        ����                    ��                  ��    ��      ��      ��\n");
    gotoxy(5, 11);
    printf("��        ����                                                  ������        ��      ���    ��      ��    \n");
    gotoxy(5, 12);
    printf("��        ��  ��        �����    ��������                                ���      ��    �����    \n");
    gotoxy(5, 13);
    printf("�����  ��  ��              ��                                ��������   ��   ��    ��            ��� \n");
    gotoxy(5, 14);
    printf("                        �����      ��                              ��       ��      ��   ��           ��  ��\n");
    gotoxy(5, 15);
    printf("                        ��            ��                              ��                    ��           ��  ��\n");
    gotoxy(5, 16);
    printf("                        �����      ������                      ��                                  ��� \n");
    textcolor(15);
    gotoxy(1, 22);
    printf("                ������������������������������ ��� Ű  ������������������������������");
    gotoxy(1, 23);
    printf("                ��                                      ��");
    gotoxy(1, 24);
    printf("                ��     ����������������                         ��");
    gotoxy(1, 25);
    printf("                ��     ����������������   :   ����              ��");
    gotoxy(1, 26);
    printf("                ��    �����̽� ��                       ��");
    gotoxy(1, 27);
    printf("                ��                                      ��");
    gotoxy(1, 28);
    printf("                ��       ��������                           ��");
    gotoxy(1, 29);
    printf("                ��       �� P��     :   ����� ����       ��");
    gotoxy(1, 30);
    printf("                ��       ��������                           ��");
    gotoxy(1, 31);
    printf("                ��������������������������������������������������������������������������������");
    
    // ������ ����
    gotoxy(30, 22);
    printf("����������������������������������������������������������  ������ ����  ����������������������������������������������������������");
    gotoxy(30, 23);
    printf("��                                                                       ��");
    gotoxy(30, 24);
    printf("��               ��                      ");
    textcolor(10);
    printf("* * * * * * *");
    textcolor(15);
    printf("                   ��");
    gotoxy(30, 25);
    printf("��           ��  ��      :   ���ع�      ");
    textcolor(10);
    printf("*   1 0 0   *");
    textcolor(15);
    printf("   :   ����UP      ��");
    gotoxy(30, 26);
    printf("��       ��, ��, ��                      ");
    textcolor(10);
    printf("* * * * * * *");
    textcolor(15);
    printf("                   ��");
    gotoxy(30, 27);
    printf("��                                                                       ��");
    gotoxy(30, 28);
    printf("��       ");
    textcolor(12);
    printf("* * * * * * *                   ");
    textcolor(9);
    printf("* * * * * * *");
    textcolor(15);
    printf("                   ��");
    gotoxy(30, 29);
    printf("��       ");
    textcolor(12);
    printf("*   ������  *");
    textcolor(15);
    printf("   :   �����UP    ");
    textcolor(9);
    printf("*   ? ? ?   *");
    textcolor(15);
    printf("   :   ��������    ��");
    gotoxy(30, 30);
    printf("��       ");
    textcolor(12);
    printf("* * * * * * *                   ");
    textcolor(9);
    printf("* * * * * * *");
    textcolor(15);
    printf("                   ��");
    gotoxy(30, 31);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������");
 

    // ����
    textcolor(7);
    gotoxy(65, 8);
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 6; j++) {
            gotoxy(65 + j, 8 + i);
            if (antModel[i][j] == 1)
                printf("��");
        }
    }
    gotoxy(65, 16);
    printf(" /�� /��\n");
    textcolor(15);



    gotoxy(30, 35);
    printf("�����Ϸ��� Enter Ű�� �����ּ���.");
    Sleep(500);

    int on_off = 0;
    while (1)
    {
        gotoxy(30, 35);
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
    const int gravity = 2; // �ø��� ���� �ӵ� ����, ���̸� ����

    antY = 26;


    int leg = 0;
    Background();
    
    
    // �� ���������
    //gotoxy(cashX, cashY);
    //ShowCash(cashModel[cash_id]);

    //gotoxy(bombX, bombY);
    //ShowBomb(bombModel[bomb_id]);
    srand((unsigned int)time(NULL));

    //gotoxy(hurdleX, hurdleY);
    //ShowHurdle(cashModel[cash_id]);

    start = 0.0;
    int delay = 0;
    while (1)
    {
        makeCash();
        if (cashX == 45) DeleteText();
        if (cashX < 30) delay = 1;
        if (delay == 1) makeHurdle();
        if (hurdleX == 45) DeleteHurdleText();


        for (int i = 0; i < 20; i++)
        {
            if (_kbhit() != 0)
            {
                int key = _getch();
                switch (key)
                {
                    case SPACE:
                        if (isBottom)
                        {
                            isJumping = 1;
                            isBottom = 0;
                        }

                        
                        
                        break;
                    case 'p':
                        if (coin >= pur_heart)
                        {
                            coin -= pur_heart;
                            life += 20;
                            pur_heart += 5000;
                        }
                        break;
                    case 'P':
                        if (coin >= pur_heart)
                        {
                            coin -= pur_heart;
                            life += 20;
                            pur_heart += 5000;
                        }
                        break;

              
                        

                }
            }
            
            
        }
    
        Sleep(speed);
        /*
        if (GetKeyDown() == 'p' || GetKeyDown() == 'P' || GetKeyDown() == '��' || GetKeyDown() == '��')
        {
            coin -= pur_heart;
            life += 30;
            pur_heart += 5000;
        }
        */
        
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

        if (antY <= 10) // ������ �ִ����� ����
        {
            isJumping = 0;
        }

        Background();


        // ���� ���� �����
        gotoxy(0, pre_ant);
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");


        pre_ant = antY;

        int i, j;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                gotoxy(j + 1, antY + i);
                if (antModel[i][j] == 1)
                    printf("��");
            }
        }

        gotoxy(1, antY + 8);
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
    
        distance++;
        DetectCashCollision(antY, cashModel[cash_id], cash_id);
        DetectHurdleCollision(antY, hurdleModel[hurdle_id]);
        
       
        total = coin;
        for (int a = 0; a < 5; a++)
            total += QuantityList[a] * PriceList[a];
        rate = ((double)total - (double)seed) / (double)seed * 100.0;
        gotoxy(60, 37);
        textcolor(14);
        printf("���� ���ͷ� : %.1f %%", rate);
        gotoxy(60, 38);
        time_s = (distance / 1000.0) * 3 * speed;
        printf("���� �����ð� : %.1f ��", time_s);
        textcolor(15);

        

        LeftTime();//�ŷ��� ���� ����
        

        DrawingList(76, 3);

        //system("cls"); // �ֽ� �ŷ��ҿ� ������ �ʿ�
        gettingOld();
        isGoal();

        if (isEnd() == 1) {
            break;
        }

        
        


    }

    

}


