#include "head.h"
#include <stdio.h>

void eatfood()
{
	if (food.flag == 0)
	{

		if (snack.xy[0].x == food.x&&snack.xy[0].y == food.y)
		{
			gotoxy(food.x, food.y);
			printf("  ");
			food.flag = 1;
			score += 10;
			snack.number++;
		}

	}
}