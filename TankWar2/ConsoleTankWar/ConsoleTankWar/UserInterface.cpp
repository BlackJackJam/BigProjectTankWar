#include "stdafx.h"
#include "UserInterface.h"

void UI::Initgraph()
{
	initgraph(WIDTH + 240, HEIGHT);
	setbkcolor(BGCOLOUR);
	setlinecolor(WHITE);
	rectangle(0, 0, WIDTH, HEIGHT);
}



