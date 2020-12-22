#include "head.h"
#include <graphics.h>


void introducte()
{
	IMAGE introduction;
	loadimage(&introduction, "IMAGE", "Introduction");
	putimage(0, 0, &introduction);
}