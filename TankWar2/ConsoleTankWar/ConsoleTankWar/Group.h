#pragma once//use to set direction of AI tanks.
#ifndef __GROUP_H__
#define __GROUP_H__

#include "Tank.h"
#include "Object.h"
#include <deque>
#include "Environment.h"

using namespace std;

class TankGroup
{
public:
	TankGroup();
	void GetFriendDeque(deque<Tank> &TA);
	void GetEnemyDeque(deque<Tank> &TA);
	void OutPutDeque();
protected:
	int avrX;
	int avrY;
	int EavrX;
	int EavrY;
	deque<Tank> taka;
	deque<Tank> faka;
};

#endif // !__TANK_H__
