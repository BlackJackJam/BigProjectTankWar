#include "stdafx.h"
#include "Missle.h"

Missle::Missle()
{
	power = 150;
	x = 0;
	y = 0;
	dir = 0;
	visible = false;
	exist = false;
	sphere = 2;
	pace = 3;
	range = 300;
	mile = 0;

}

Missle::Missle(int px, int py, double dr)
{
	power = 150;
	x = px;
	y = py;
	dir = dr;
	visible = true;
	exist = true;
	sphere = 2;
	pace = 3;
	range = 300;
	mile = 0;
}

Missle::~Missle()
{

}

void Missle::display()
{
	if (visible)
	{
		setlinecolor(0x8aaaff);
		circle(x, y, 1);
		setfillcolor(GREEN);
		fillcircle(x, y, 1);
	}
}
