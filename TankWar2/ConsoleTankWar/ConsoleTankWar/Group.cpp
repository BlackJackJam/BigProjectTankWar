#include "stdafx.h"
#include "Group.h"
#include "RandomP.h"
#include <cmath>

void TankGroup::GetFriendDeque(deque<Tank> &TA)
{
	int sumX = 0;
	int sumY = 0;
	double R;
	deque<Tank>::iterator iter;
	for (iter = TA.begin(); iter != TA.end(); iter++)
	{
		sumX += iter->ShowPosX();
		sumY += iter->ShowPosY();
	}
	avrX = (int)sumX / TA.size();
	avrY = (int)sumY / TA.size();
	for (iter = TA.begin(); iter != TA.end(); iter++)
	{
		R = sqrt((iter->ShowPosX() - avrX)*(iter->ShowPosX() - avrX) + (iter->ShowPosY() - avrY)*(iter->ShowPosY() - avrY));
		avrR += R;
	}
	avrR = avrR / TA.size();
}

void TankGroup::GetEnemyDeque(deque<Tank>& TA)
{
	int sumX = 0;
	int sumY = 0;
	double R;
	deque<Tank>::iterator iter;
	for (iter = TA.begin(); iter != TA.end(); iter++)
	{
		sumX += iter->ShowPosX();
		sumY += iter->ShowPosY();
	}
	EavrX = (int)sumX / TA.size();
	EavrY = (int)sumY / TA.size();
	for (iter = TA.begin(); iter != TA.end(); iter++)
	{
		R = sqrt((iter->ShowPosX() - EavrX)*(iter->ShowPosX() - EavrX) + (iter->ShowPosY() - EavrY)*(iter->ShowPosY() - EavrY));
		EavrR += R;
	}
	EavrR = EavrR / TA.size();
}

void TankGroup::tankoperate(deque<Tank>& TA)
{
	deque<Tank>::iterator tt;
	if (EavrR > avrR)
	{
		for (tt = TA.begin(); tt != TA.end(); tt++)
		{
			double d1,d2,d;
			int tx, ty;
			tx = tt->ShowPosX();
			ty = tt->ShowPosY();
			d1 = atan2((tx - avrX), (ty - avrY))*180/PI;
			d2 = atan2((avrX - EavrX), (avrY - EavrY))*180/PI;
			d = (d1 + d2) / 2;
			tt->setdir(d);
		}
	}
	else if(EavrR<avrR)
	{
		for (tt = TA.begin(); tt != TA.end(); tt++)
		{
			double d1, d2, d;
			int tx, ty;
			tx = tt->ShowPosX();
			ty = tt->ShowPosY();
			d1 = atan2((avrX - tx), (avrY - ty))*180/PI;
			d2 = atan2((EavrX - avrX), (EavrY - avrY))*180/PI;
			d = (d1 + d2) / 2;
			tt->setdir(d);
		}
	}
	else
	{
		for (tt = TA.begin(); tt != TA.end(); tt++)
		{
			double d;
			RandomP rr;
			d = (rr.uniform() - 0.5) * 360 / PI;
			tt->setdir(d);
		}
	}
}
