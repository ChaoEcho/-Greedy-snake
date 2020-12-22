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

Mark *head=NULL;   //头指针

int score = 0;

char *first=(char *)malloc(sizeof(char)*20);

int main()
{
	//去掉光标
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

	//音乐起
	//mciSendString("open 核爆神曲.mp3", 0, 0, 0);
	//mciSendString("play 核爆神曲.mp3", 0, 0, 0);
	PlaySound("核爆神曲", GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);


	food.flag = 1;       //初始食物的状态（1.不存在 0.存在）
	snack.number = 3;    //初始数量
	snack.dir = right;   //开始移动的方向
	int solution=0;		 //判断问题
	char mode;		     //模式选择

	//初始蛇身位置
	snack.xy[0].x = 4;
	snack.xy[0].y = 5;
	snack.xy[1].x = 3;
	snack.xy[1].y = 5;
	snack.xy[2].x = 2;
	snack.xy[2].y = 5;
	snack.xy[3].x = 1;
	snack.xy[3].y = 5;
	
	//展示字符
	char score_t[10], speed[10];

	//创建画布
	initgraph(900, 520);
	
	//
	name();

	//欢迎界面
	welcome();
	mode=_getch();

	//介绍界面
	settextcolor(BLACK);
	introducte();
	_getch();

	//游戏内容
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
		
		//展示信息
		outtextxy(600, 120, "欢迎来到贪吃蛇大闯关");
		sprintf(score_t,"%d",score);
		outtextxy(600, 175, "当前分数：");
		outtextxy(600, 200, score_t);
		if ((150 - score / 2) >= 60)
		sprintf(speed, "%d", 100 + score / 2);
		outtextxy(600, 225, "当前速度：");
		outtextxy(600, 250, speed);
		outtextxy(600, 350, "按空格键暂停/继续游戏");

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
			outtextxy(600, 275, "无敌模式不录入最终分数");
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
