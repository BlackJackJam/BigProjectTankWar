#include "stdafx.h"
#include "MiniGun.h"

MiniGun::MiniGun()
{
	Weapon::SetPW(20);
	reset(0, 0, 0, 3, false, false, 2, 90, 0);

}

MiniGun::MiniGun(int px, int py, double dr, WSIDE w)
{
	Weapon::SetPW(20);
	reset(px, py, dr, 3, true, true, 2, 90, 0);
	Weapon::SetWS(w);
}



MiniGun::~MiniGun()
{

}

bool MiniGun::checkrange()
{
	if (mile >= range) return false;
	else return true;
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