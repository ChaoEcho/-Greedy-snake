#include "head.h"
#include <stdio.h>

void drawsnack()
{
	for (int i = 0; i <= snack.number; i++)
	{
		if (i == snack.number)
		{
			gotoxy(snack.xy[i].x, snack.xy[i].y);
			printf("  ");
		}
		else
		{
			gotoxy(snack.xy[i].x, snack.xy[i].y);
			printf("¡ö");
		}
	}
	if (food.flag == 0)
	{
		gotoxy(food.x, food.y);
		printf("¡ö");
	}
}