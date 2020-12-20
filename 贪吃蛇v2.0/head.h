#pragma once
#ifndef  __HEAD__
#define __HEAD__

//�궨��
#define GOAL 50   //���������������Ŀ��
#define LINE 25   //����
#define ROW 25    //����
#define EVERY 20  //��λ����


//��������
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
	int number; //�ߵĸ���
	Dir xy[GOAL + 1]; //�ߵ�����
	int dir;
};

extern struct Snack snack;

struct Food {
	int flag; //ʳ���״̬
	int x;	  //ʳ�������
	int y;
};

extern struct Food food;

extern int score;

//��������
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
