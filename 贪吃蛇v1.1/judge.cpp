#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void judge()
{
	int i;
	if (snack.xy[0].x == 0 || snack.xy[0].y == 0 || snack.xy[0].x == LINE * 2 || snack.xy[0].y == ROW)
	{
		gotoxy(75, 14);
		printf("������Ŷ��");
		gotoxy(75, 16);
		printf("��߼�¼��1000");
		gotoxy(75, 17);
		printf("����EchoChao����ģ����Ǹ�С�����");
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
			printf("������Ŷ��");
			gotoxy(75, 16);
			printf("��߼�¼��1000");
			gotoxy(75, 17);
			printf("����EchoChao����ģ����Ǹ�С�����");
			gotoxy(75, 19);
			gotoxy(75, 20);
			system("pause");
			gotoxy(75, 21);
			exit(0);
		}
	}
}