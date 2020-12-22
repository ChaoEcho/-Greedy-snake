#include "head.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <graphics.h>

int judge_3()
{
	int i;

	for (i = 0; i <= snack.number; i++)
	{
		if (snack.xy[i].y == 0)
			snack.xy[i].y = ROW - 1;
		else if (snack.xy[i].y == ROW)
			snack.xy[i].y = 1;
		else if (snack.xy[i].x == 0)
			snack.xy[i].x = LINE - 1;
		else if (snack.xy[i].x == LINE)
			snack.xy[i].x = 1;
	}
	return 0;
}