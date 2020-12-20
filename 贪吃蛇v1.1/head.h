#pragma once
#ifndef __HEAD__
#define __HEAD__

//宏定义
#define GOAL 100
#define LINE 25
#define ROW 25


//数据类型
enum Coo
{
	up = 72,
	down = 80,
	left = 75,
	right=77
};

extern enum Coo Coop;

struct Dir {
	int x;
	int y;
};

extern struct Dir xy[GOAL + 1];

struct Snack {
	int number; //蛇的个数
	Dir xy[GOAL + 1]; //蛇的坐标
	int dir;
};

extern struct Snack snack ;

struct Food {
	int flag; //食物的状态
	int x;	  //食物的坐标
	int y;
};

extern struct Food food;

extern int score;

//函数声明

void gotoxy(int x, int y);

void initmap();

void drawsnack();

void movesnack();

void playgame();

void producefood();

void eatfood();

void judge();

#endif // !__HEAD__
