#include "stdafx.h"
#include "Group.h"

void TankGroup::GetFriendDeque(deque<Tank> &TA)
{
	int sumX = 0;
	int sumY = 0;
	taka = TA;
	deque<Tank>::iterator iter;
	for (iter = taka.begin(); iter != taka.end(); iter++)
	{
		sumX += iter->ShowPosX();
		sumY += iter->ShowPosY();
	}
	avrX = (int)sumX / taka.size();
	avrY = (int)sumY / taka.size();

}

void TankGroup::GetEnemyDeque(deque<Tank>& TA)
{
	int sumX = 0;
	int sumY = 0;
	faka = TA;
	deque<Tank>::iterator iter;
	for (iter = faka.begin(); iter != faka.end(); iter++)
	{
		sumX += iter->ShowPosX();
		sumY += iter->ShowPosY();
	}
	EavrX = (int)sumX / faka.size();
	EavrY = (int)sumY / faka.size();
}
