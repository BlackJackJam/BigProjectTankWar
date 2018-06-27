#include "stdafx.h"
#include "Boom.h"

Boom::Boom()
{
	x = 0;
	y = 0;
	dir = 0;
	pace = 0;
	visible = false;
	exist = false;
	sphere = 0;
	range = 0;
	mile = 0;
}

Boom::Boom(int px, int py)
{
	x = px;
	y = py;
	dir = 0;
	pace = 0;
	sphere = 0;
	range = 0;
	mile = 0;
	visible = true;
	exist = true;
}

void Boom::display()
{
	RandomP sx;
	switch (mile)
	{
	case 0:
		setlinecolor(YELLOW);
		circle(x, y, 4);
		setfillcolor(0xfb6603);
		fillcircle(x, y, 4);
		mile++;
		break;
	case 1:
		setlinecolor(YELLOW);
		setfillcolor(0xfb6603);
		int dx, dy,i;
		for (i = 1; i <= 3; i++)
		{
			dx = 4*(int)sx.uniform()-2;
			dy = 4 * (int)sx.uniform() - 2;
			circle(dx, dy, 2);
			fillcircle(dx, dy, 2);
		}
		mile++;
		exist = false;
		break;
	default:
		break;
	}
}

