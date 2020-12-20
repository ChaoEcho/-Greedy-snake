#include "head.h"
#include <stdio.h>

void movesnack()
{
	int i;
	for (i = snack.number; i > 0; i--)
	{
		snack.xy[i].x = snack.xy[i - 1].x;
		snack.xy[i].y = snack.xy[i - 1].y;
	}

	switch (snack.dir)
	{
	case up:
		snack.xy[0].y -= 1;
		break;
	case down:
		snack.xy[0].y += 1;
		break;
	case left:
		snack.xy[0].x -= 2;
		break;
	case right:
		snack.xy[0].x += 2;
		break;
	}
}