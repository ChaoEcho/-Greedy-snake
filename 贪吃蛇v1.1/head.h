#pragma once
#ifndef __HEAD__
#define __HEAD__

//�궨��
#define GOAL 100
#define LINE 25
#define ROW 25


//��������
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
	int number; //�ߵĸ���
	Dir xy[GOAL + 1]; //�ߵ�����
	int dir;
};

extern struct Snack snack ;

struct Food {
	int flag; //ʳ���״̬
	int x;	  //ʳ�������
	int y;
};

extern struct Food food;

extern int score;

//��������

void gotoxy(int x, int y);

void initmap();

void drawsnack();

void movesnack();

void playgame();

void producefood();

void eatfood();

void judge();

#endif // !__HEAD__
