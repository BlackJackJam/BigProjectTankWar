#pragma once//use to set direction of AI tanks.
#ifndef __GROUP_H__
#define __GROUP_H__

#include "Environment.h"
#include <deque>
#include "Object.h"
#include "Tank.h"
#include "Map.h"

using namespace std;

class TankGroup
{
public:
	TankGroup();
	void GetFriendDeque(deque<Tank> &TA);
	void GetEnemyDeque(deque<Tank> &TA);
	void tankoperate(deque<Tank>&TA,deque<Tank> &TB,deque<Box> &B);
	void Scanenemy(deque<Tank> &F, deque<Tank> &E);
	void ScanBox(deque<Tank> &T, deque<Box> &B);
	double GMapDistance(int px1, int py1, int px2, int py2);
protected:
	int avrX;
	int avrY;
	int avrR;
	int EavrX;
	int EavrY;
	int EavrR;
};

#endif // !__TANK_H__
