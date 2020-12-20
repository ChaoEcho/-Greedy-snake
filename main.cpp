#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define GOAL 100
#define LINE 25
#define ROW 25

//函数的声明
void gotoxy(int x, int y); //光标位置
void initmap(); //画出框架
void drawsnack(); //画出蛇
void movesnack(); //蛇的移动
void playgame(); //人为操控
void producefood(); //食物产生
void judge(); //判断情况
void eatfood(); //吃食物
//数据定义
enum Coop
{
	up = 72,
	down = 80,
	left = 75 ,
	right = 77
};
struct Dir {
	int x;
	int y;
};
struct Snack {
	int number; //蛇的个数
	Dir xy[GOAL+1]; //蛇的坐标
	int dir;
} snack;

struct Food {
	int flag; //食物的状态
	int x;	  //食物的坐标
	int y;
}food;

int score = 0;

int main()
{
	food.flag = 1;
	snack.number = 3;
	snack.dir = right;
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	snack.xy[0].x = 8;
	snack.xy[0].y = 5;
	snack.xy[1].x = 6;
	snack.xy[1].y = 5;
	snack.xy[2].x = 4;
	snack.xy[2].y = 5;
	snack.xy[3].x = 2;
	snack.xy[3].y = 5;
	initmap();
	while (true)
	{
		char ch;
		//initmap();
		producefood();
		drawsnack();
		if (_kbhit())
			playgame();
		eatfood();
		movesnack();
		judge();
		gotoxy(75, 12);
		printf("你的分数是：%d", score);
		gotoxy(75, 10);
		printf("当前速度为：%d", 150 + score / 5);
		int i = 150 - score / 2;
		if (i >= 20);
		else i = 20;
		Sleep(i);
	}
	return 0;
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}

void initmap()
{
	int i, j;
	for (i = 0; i <= ROW; i++)
	{
		for (j = 0; j <= LINE; j++)
		{
			if (i == 0 || i == ROW)
				printf("■");
			else if (j == 0 || j == LINE)
				printf("■");
			else printf("  ");
		}
		printf("\n");
	}
}

void drawsnack()
{
	for (int i = 0; i <= snack.number; i++)
	{
		if (i == snack.number)
		{
			gotoxy(snack.xy[i].x, snack.xy[i].y);
			printf("  ");
		}
		else
		{
			gotoxy(snack.xy[i].x, snack.xy[i].y);
			printf("■");
		}
	}
	if (food.flag == 0)
	{
		gotoxy(food.x, food.y);
		printf("■");
	}
}

void movesnack()
{
	int i;
	for (i = snack.number; i > 0; i--)
	{
		snack.xy[i].x= snack.xy[i-1].x;
		snack.xy[i].y = snack.xy[i-1].y;
	}
	
	switch (snack.dir)
		{
		case up :
			snack.xy[0].y -= 1;
			break;
		case down:
			snack.xy[0].y += 1;
			break;
		case left:
			snack.xy[0].x -= 2;
			break;
		case right:
			snack.xy[0].x += 2;
			break;
		}
}

void playgame()
{
	char ch = _getch();
	switch (ch)
	{
	case up:
		if (snack.dir != down)
			snack.dir = up;
		break;
	case down:
		if (snack.dir != up)
			snack.dir = down;
		break;
	case left:
		if (snack.dir != right)
			snack.dir = left;
		break;
	case right:
		if (snack.dir != left)
			snack.dir = right;
		break;
	case 'Q':
	case 'q':
		gotoxy(75, 12);
		system("pause");
		break;
	}	
}

void producefood()
{
	srand((unsigned)time(NULL));
	if (food.flag == 1)
	{
		while ((food.x = rand() % 48 + 1) % 2 != 0)
			continue;
		food.y = rand() % 24 + 1;
		food.flag = 0;
	}
}

void judge()
{
	int i;
	if (snack.xy[0].x == 0 || snack.xy[0].y == 0 || snack.xy[0].x == LINE * 2 || snack.xy[0].y == ROW)
	{
		gotoxy(75, 14);
		printf("你输了哦！");
		gotoxy(75, 16);
		printf("最高纪录：1000");
		gotoxy(75, 17);
		printf("是由EchoChao创造的，真是个小机灵鬼");
		gotoxy(75, 19);
		gotoxy(75, 20);
		system("pause");
		gotoxy(75, 21);
		exit(0);
	}
	for (i = 1; i < snack.number; i++)
	{
		if (snack.xy[i].x == snack.xy[0].x&& snack.xy[0].y == snack.xy[i].y)
		{
			gotoxy(75, 14);
			printf("你输了哦！");
			gotoxy(75, 16);
			printf("最高纪录：1000");
			gotoxy(75, 17);
			printf("是由EchoChao创造的，真是个小机灵鬼");
			gotoxy(75, 19);
			gotoxy(75, 20);
			system("pause");
			gotoxy(75, 21);
			exit(0);
		}
	}
}

void eatfood()
{
	if (food.flag == 0)
	{
		
			if (snack.xy[0].x == food.x&&snack.xy[0].y == food.y)
			{
				gotoxy(food.x, food.y);
				printf("  ");
				food.flag = 1;
				score += 10;
				snack.number++;
			}
		
	}
}

