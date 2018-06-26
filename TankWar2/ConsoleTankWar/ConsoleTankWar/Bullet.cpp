#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
	power = 100;
	x = 0;
	y = 0;
	dir = 0;
	visible = false;
	exist = false;
	sphere = 1;
	pace = 0;
	range = 90;
	mile = 0;
}

Bullet::Bullet(int px, int py, double dr)
{
	power = 100;
	x = px;
	y = py;
	dir = dr;
	visible = true;
	exist = true;
	sphere = 1;
	pace = 3;
	range = 90;
	mile = 0;
}

Bullet::~Bullet()
{
}


void Bullet::display()
{
	if (visible)
	{
		setlinecolor(0x8aaaff);
		circle(x, y, 1);
		setfillcolor(YELLOW);
		fillcircle(x, y, 1);
	}
}

bool Bullet::checkrange()
{
	if (mile==range) return false;
	else return true;
}




