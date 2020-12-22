#include "head.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <graphics.h>

int judge_1()
{
	int i;
	char score_e[10];
	if (snack.xy[0].x == 0 || snack.xy[0].y == 0 || snack.xy[0].x == LINE || snack.xy[0].y == ROW)
	{
		outtextxy(600, 275, "最终分数：");
		sprintf(score_e, "%d", score);
		outtextxy(600, 300, score_e);
		return 1;
	}

	for (i = 1; i <= snack.number; i++)
	{
		if (snack.xy[i].x == snack.xy[0].x&& snack.xy[0].y == snack.xy[i].y)
		{
			outtextxy(600, 275, "最终分数：");
			sprintf(score_e, "%d", score);
			outtextxy(600, 300, score_e);
			return 1;
		}
	}
	return 0;
}
