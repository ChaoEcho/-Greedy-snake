#include "head.h"
#include "resource.h"
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


enum Coo Coop;

struct Snack snack;

struct Food food;

Mark *head=NULL;   //ͷָ��

int score = 0;

char *first=(char *)malloc(sizeof(char)*20);

int main()
{
	//ȥ�����
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

	//������
	//mciSendString("open �˱�����.mp3", 0, 0, 0);
	//mciSendString("play �˱�����.mp3", 0, 0, 0);
	PlaySound("�˱�����", GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);


	food.flag = 1;       //��ʼʳ���״̬��1.������ 0.���ڣ�
	snack.number = 3;    //��ʼ����
	snack.dir = right;   //��ʼ�ƶ��ķ���
	int solution=0;		 //�ж�����
	char mode;		     //ģʽѡ��

	//��ʼ����λ��
	snack.xy[0].x = 4;
	snack.xy[0].y = 5;
	snack.xy[1].x = 3;
	snack.xy[1].y = 5;
	snack.xy[2].x = 2;
	snack.xy[2].y = 5;
	snack.xy[3].x = 1;
	snack.xy[3].y = 5;
	
	//չʾ�ַ�
	char score_t[10], speed[10];

	//��������
	initgraph(900, 520);
	
	//
	name();

	//��ӭ����
	welcome();
	mode=_getch();

	//���ܽ���
	settextcolor(BLACK);
	introducte();
	_getch();

	//��Ϸ����
	setbkcolor(WHITE);
	cleardevice();
	IMAGE backgroud;
	loadimage(&backgroud, "IMAGE","Background");
	BeginBatchDraw();
	while (true)
	{
		putimage(0, 0, &backgroud);
		initmap();
		settextcolor(BLACK);
		producefood();
		if (_kbhit())
			playgame();
		eatfood();
		drawimage();
		movesnack();
		
		//չʾ��Ϣ
		outtextxy(600, 120, "��ӭ����̰���ߴ󴳹�");
		sprintf(score_t,"%d",score);
		outtextxy(600, 175, "��ǰ������");
		outtextxy(600, 200, score_t);
		if ((150 - score / 2) >= 60)
		sprintf(speed, "%d", 100 + score / 2);
		outtextxy(600, 225, "��ǰ�ٶȣ�");
		outtextxy(600, 250, speed);
		outtextxy(600, 350, "���ո����ͣ/������Ϸ");

		if ((150 - score/2) >= 60)
			Sleep(150 - score/2);
		else
			Sleep(60);
		FlushBatchDraw();
		if (mode == '1')
			solution = judge_1();
		else if (mode == '2')
			solution = judge_2();
		else if (mode == '3')
		{
			solution = judge_3();
			outtextxy(600, 275, "�޵�ģʽ��¼�����շ���");
		}
		if (solution)
		{
			FlushBatchDraw();
			_getch();
			savescore();
			readfile();
			system("pause");
			exit(0);
		}
		else continue;
		cleardevice();
	}
	EndBatchDraw();
	_getch();
	closegraph();
}
