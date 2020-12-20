#pragma once
#ifndef  __HEAD__
#define __HEAD__

//宏定义
#define GOAL 50   //蛇身最大数量，即目标
#define LINE 25   //列数
#define ROW 25    //行数
#define EVERY 20  //单位长度


//数据类型
enum Coo
{
	up = 72,
	down = 80,
	left = 75,
	right = 77
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

extern struct Snack snack;

struct Food {
	int flag; //食物的状态
	int x;	  //食物的坐标
	int y;
};

extern struct Food food;

extern int score;

//函数声明
void initmap();
void drawimage();
void movesnack();
void producefood();
void eatfood();
void playgame();
int judge_1();
int judge_2();
int judge_3();
void welcome();
void introducte();
#endif // ! __HEAD__
