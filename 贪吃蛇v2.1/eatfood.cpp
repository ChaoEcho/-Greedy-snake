#include "head.h"
#include <graphics.h>

void eatfood()
{
	if (food.flag == 0)
	{
		if (snack.xy[0].x == food.x&&snack.xy[0].y == food.y)
		{
			food.flag = 1;
			score += 10;
			snack.number++;
		}
	}
}