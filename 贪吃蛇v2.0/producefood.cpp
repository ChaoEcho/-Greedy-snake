#include "head.h"
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

void producefood()
{
	srand((unsigned)time(NULL));

	if (food.flag == 1)
	{
		while ((food.x = rand() % 24 + 1) % 2 != 0)
			continue;
		food.y = rand() % 24 + 1;
		food.flag = 0;
	}
}