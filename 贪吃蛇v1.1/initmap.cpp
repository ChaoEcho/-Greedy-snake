#include "head.h"
#include <stdio.h>

void initmap()
{
	int i, j;
	for (i = 0; i <= ROW; i++)
	{
		for (j = 0; j <= LINE; j++)
		{
			if (i == 0 || i == ROW)
				printf("��");
			else if (j == 0 || j == LINE)
				printf("��");
			else printf("  ");
		}
		printf("\n");
	}
}