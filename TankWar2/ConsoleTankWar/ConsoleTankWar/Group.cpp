#include "stdafx.h"
#include "Group.h"
#include "RandomP.h"
#include <cmath>

TankGroup::TankGroup()
{
	avrR = 0;
	avrY = 0;
	avrX = 0;
	EavrR = 0;
	EavrX = 0;
	EavrY = 0;
}

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

void TankGroup::tankoperate(deque<Tank>& TA,deque<Tank>& TB,deque<Box> &B)
{
	GetFriendDeque(TA);
	GetEnemyDeque(TB);
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
	Scanenemy(TA, TB);
	ScanBox(TA, B);
}

void TankGroup::Scanenemy(deque<Tank> &F, deque<Tank> &E)
{
	deque<Tank>::iterator fiter;
	deque<Tank>::iterator eiter;
	for (fiter = F.begin(); fiter != F.end(); fiter++)
	{
		double dd, cd;
		int enemyNum;
		bool fight = false;
		RandomP hc;
		int ex, ey;
		dd = 151;
		for (eiter = E.begin(); eiter != E.end(); eiter++)
		{
			cd = GMapDistance(fiter->ShowPosX(), fiter->ShowPosY(), eiter->ShowPosX(), eiter->ShowPosY());
			if (cd < dd)
			{
				dd = cd;
				ex = eiter->ShowPosX();
				ey = eiter->ShowPosY();
				if ((fiter->showhealth()) >(eiter->showhealth() + (int)hc.uniform() * 50 - 25)) fight = true;
			}
		}
		if (cd < 151)
		{
			if (fight == true)
			{
				double drr;
				drr = atan2((ex - fiter->ShowPosX()), (ey - fiter->ShowPosY())) * 180 / PI;
				fiter->setdir(drr);
			}
			else
			{
				double drr;
				drr = atan2((-ex + fiter->ShowPosX()), (-ey + fiter->ShowPosY())) * 180 / PI;
				drr += hc.uniform() * 60 - 30;
				fiter->setdir(drr);
			}
		}
	}
}

void TankGroup::ScanBox(deque<Tank>& T, deque<Box>& B)
{
	deque<Tank>::iterator itt;
	deque<Box>::iterator itb;
	for (itt = T.begin(); itt != T.end(); itt++)
	{
		int db = 31;
		int cdb;
		int bx, by;
		for (itb = B.begin(); itb != B.end(); itb++)
		{
			cdb = GMapDistance(itb->ShowPosX(), itb->ShowPosY(), itt->ShowPosX(), itt->ShowPosY());
			if (cdb < db)
			{
				db = cdb;
				bx = itb->ShowPosX();
				by = itb->ShowPosY();
			}
			double dib;
			dib = atan2(bx - itt->ShowPosX(), by - itt->ShowPosY());
			itt->setdir(dib);
		}
	}

}

int TankGroup::GMapDistance(int px1, int py1, int px2, int py2)
{
	int D;
	D = (int)sqrt((px1 - px2)*(px1 - px2) + (py1 - py2)*(py1 - py2));
	return D;
}
