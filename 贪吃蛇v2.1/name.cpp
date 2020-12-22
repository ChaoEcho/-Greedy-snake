#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <graphics.h>


void name()
{
	int i = 0;
	setbkcolor(WHITE);
	cleardevice();

	InputBox(first, 10, NULL, "少侠请输入你的名字：", "不妨起个霸气点的名字", 0, 0, true);
}