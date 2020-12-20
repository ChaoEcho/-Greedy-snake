#include "head.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

void playgame()
{
	char ch = _getch();
	switch (ch)
	{
	case up:
		if (snack.dir != down)
			snack.dir = up;
		break;
	case down:
		if (snack.dir != up)
			snack.dir = down;
		break;
	case left:
		if (snack.dir != right)
			snack.dir = left;
		break;
	case right:
		if (snack.dir != left)
			snack.dir = right;
		break;
	case 'Q':
	case 'q':
		gotoxy(75, 12);
		system("pause");
		break;
	}
}