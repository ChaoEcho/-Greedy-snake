#include "head.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <graphics.h>

int judge_2()
{
	int i;

	for (i = 0; i <= snack.number; i++)
	{
		if (snack.xy[i].y == 0)
			snack.xy[i].y = ROW-1;
		else if (snack.xy[i].y == ROW)
			snack.xy[i].y = 1;
		else if (snack.xy[i].x == 0)
			snack.xy[i].x = LINE-1;
		else if (snack.xy[i].x == LINE)
			snack.xy[i].x = 1;
	}

	for (i = 1; i <= snack.number; i++)
	{
		if (snack.xy[i].x == snack.xy[0].x&& snack.xy[0].y == snack.xy[i].y)
		{
			outtextxy(600, 275, "×îÖÕ·ÖÊý£º");
			char score_f[10];
			sprintf(score_f, "%d", score);
			outtextxy(600, 300, score_f);
			return 1;
		}
	}
	return 0;
}