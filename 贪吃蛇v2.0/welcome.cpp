#include "head.h"
#include <graphics.h>

void welcome()
{
	IMAGE welcome;
	loadimage(&welcome, "IMAGE", "WELCOME");
	putimage(0, 0, &welcome);
}