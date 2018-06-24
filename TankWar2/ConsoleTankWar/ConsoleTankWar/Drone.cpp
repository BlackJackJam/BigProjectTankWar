#include "stdafx.h"
#include "Drone.h"

Drone::Drone()
{
}

Drone::Drone(int px, int py, double dr)
{
	power = 10;
	x = px;
	y = py;
	dir = dr;
	visible = true;
	exist = true;
	sphere = 8;
	pace = 2;
	range = 120;
	mile = 0;
}

Drone::~Drone()
{

}

void Drone::display()
{

	if (visible)
	{
		setlinecolor(RED);
		setlinestyle(PS_DOT);
		putpixel(x, y, RED);
		circle(x, y, 8);
	}
}
