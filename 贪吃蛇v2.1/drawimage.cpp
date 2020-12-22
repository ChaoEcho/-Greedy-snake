#include "head.h"
#include <graphics.h>
#include <stdio.h>

void drawimage()
{
	int i;
	for (i = 0; i < snack.number; i++)
	{
		if(i==0)
			setfillcolor(YELLOW);
		else 
			setfillcolor(BLUE);
		fillrectangle(snack.xy[i].x*EVERY,snack.xy[i].y*EVERY, (snack.xy[i].x+1)*EVERY, (snack.xy[i].y+1)*EVERY);
	}

	if (food.flag == 0)
	{
		setfillcolor(GREEN);
		fillrectangle(food.x*EVERY, food.y*EVERY, (food.x + 1)*EVERY, (food.y + 1)*EVERY);
	}
}