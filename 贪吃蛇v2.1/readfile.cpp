#include "head.h"
#include <stdio.h>
#include <conio.h>
#include <graphics.h>


void readfile()
{
	head = NULL;
	Mark *head_1 = head;

	FILE *fp = fopen("英雄榜.txt", "r+");
	
	if (fp == NULL)
		printf("出现错误，文件打开失败");

	while (!feof(fp))
	{
		Mark *tem = (Mark *)malloc(sizeof(Mark));
		tem->next = NULL;
		

		fscanf(fp, "%10s %d", &tem->name, &tem->score);
		tem->next = NULL;

		if (head == NULL)
		{
			head_1 = tem;
			head = head_1;
		}
		else
		{
			head_1->next = tem;
			head_1 = head_1->next;
		}
	}

	setbkcolor(WHITE);
	cleardevice();
	settextcolor(BLACK);

	int i = 1;
	char ch[20];
	outtextxy(0, 0, "用户名");
	outtextxy(150, 0, "成绩");
	head_1 = head;
	int max = head_1->score;
	char max_name[20];
	strcpy(max_name, head_1->name);
	while (head_1->next != NULL)
	{
		//输出到命令行
		//fprintf(stdout, "%-10s %d\n", head_1->name, head_1->score);
		if (head_1->score > max)
		{
			max = head_1->score;
			strcpy(max_name, head_1->name);
		}
		settextcolor(BLACK);
		sprintf(ch, "%d",head_1->score);
		outtextxy(0,i*20,head_1->name);
		outtextxy(10*15, i * 20, ch);
		settextcolor(RED);
		outtextxy(400, 230, "最高分数：");
		outtextxy(400, 250, max_name);
		sprintf(ch, "%d", max);
		outtextxy(400, 270, ch);
		i++;
		FlushBatchDraw();
		head_1 = head_1->next;
	}

}