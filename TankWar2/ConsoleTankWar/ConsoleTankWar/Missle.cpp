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

bool Missle::checkrange()
{
	if (mile == range) return false;
	else return true;
}

void Missle::gettarget(deque<Tank> TX)
{
	double distance;
	deque<Tank>::iterator it;
	it = TX.begin();
	distance = TargetDistance(*it);
	targetnumber = it->shownumber();
	for (it = TX.begin(); it != TX.end(); it++)
	{
		double distance2;
		distance2 = TargetDistance(*it);
		if (distance > distance2) targetnumber = it->shownumber();
	}
}

double Missle::TargetDistance(Tank C)
{
	double distance;
	distance = sqrt((C.ShowPosX() - x)*(C.ShowPosX() - x) + (C.ShowPosY ()- y)*(C.ShowPosY ()- y));
	return distance;
}

void Missle::setdir(deque<Tank> TX)
{
	int tX, tY;
	deque<Tank>::iterator itt;
	for (itt = TX.begin(); itt != TX.end(); itt++)
	{
		if (itt->shownumber()==targetnumber)
		{
			dir=
		}
	}
}
