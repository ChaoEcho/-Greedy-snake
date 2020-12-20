#include "head.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

enum Coo Coop;

struct Snack snack;

struct Food food;

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

	//测试语句
	//printf("%d", snack.xy[3].y);
	//gotoxy(snack.xy[3].x, snack.xy[3].y);

	initmap();
	while (true)
	{
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