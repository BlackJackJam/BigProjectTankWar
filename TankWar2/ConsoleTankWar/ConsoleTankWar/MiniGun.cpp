#include "stdafx.h"
#include "MiniGun.h"

MiniGun::MiniGun()
{
	power = 20;
	x = 0;
	y = 0;
	dir = 0;
	visible = false;
	exist = false;
	sphere = 2;
	pace = 0;
	range = 90;
	mile = 0;

}

MiniGun::MiniGun(int px, int py, double dr)
{
	power = 20;
	x = px;
	y = py;
	dir = dr;
	visible = true;
	exist = true;
	sphere = 2;
	pace = 3;
	range = 90;
	mile = 0;
}

MiniGun::~MiniGun()
{

}

void MiniGun::display()
{
	if (visible)
	{
		setlinecolor(0x8aaaff);
		circle(x, y, 1);
		setfillcolor(WHITE);
		fillcircle(x, y, 1);
	}

}