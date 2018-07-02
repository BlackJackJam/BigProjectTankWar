#include "stdafx.h"
#include "Missle.h"
#include <cmath>



/*void Missle::gettarget(deque<Tank> TX)
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
		if (distance > distance2)
		{
			distance = distance2;
			targetnumber = it->shownumber();
		}
	}
}

double Missle::TargetDistance(Tank C)
{
	double distance;
	distance = sqrt((C.ShowPosX() - x)*(C.ShowPosX() - x) + (C.ShowPosY ()- y)*(C.ShowPosY ()- y));
	return distance;
}

template <typename T> void Missle::setdir(deque<T> TX)
{
	int tX, tY;
	deque<Tank>::iterator itt;
	for (itt = TX.begin(); itt != TX.end(); itt++)
	{
		if (itt->shownumber()==targetnumber)
		{
			tX = itt->ShowPosX();
			tY = itt->ShowPosY();
			Missle::dir = atan2((tX - x), (tY - y))*180/PI;
		}
		else Missle::dir = Missle::dir;
	}
}*/
