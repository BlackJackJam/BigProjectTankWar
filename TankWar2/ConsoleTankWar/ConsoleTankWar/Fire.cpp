#include "stdafx.h"
#include "Fire.h"

Fire::Fire()
{
	power = 200;
	x = 0;
	y = 0;
	dir = 0;
	visible = false;
	exist = false;
	sphere = 2;
	pace = 0;
	range = 30;
	mile = 0;
}

Fire::Fire(int px, int py, double dr)
{
	power = 200;
	x = px;
	y = py;
	dir = dr;
	visible = true;
	exist = true;
	sphere = 2;
	pace = 3;
	range = 30;
	mile = 0;
}

Fire::~Fire()
{

}

void Fire::display()
{
	if (visible)
	{
		setlinecolor(RED);
		circle(x, y, 2);
		setfillcolor(RED);
		fillcircle(x, y, 2);
	}
}
