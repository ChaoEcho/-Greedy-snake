#include "head.h"
#include <graphics.h>

void initmap()
{
	int i, j;
	for (i = 0; i <= LINE; i++)
	{
		for (j = 0; j <= ROW; j++)
		{
			if (i == 0 || i == LINE)
			{
				setfillcolor(RED);
				fillrectangle(i*EVERY, j*EVERY, (i+1)*EVERY, (j + 1)*EVERY);
			}

			if (j == 0 || j == ROW)
			{
				setfillcolor(RED);
				fillrectangle(i*EVERY, j*EVERY, (i + 1)*EVERY, (j + 1)*EVERY);
			}
		}
	}
}