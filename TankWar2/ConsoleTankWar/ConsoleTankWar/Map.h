#pragma once
#ifndef __MAP_H__
#define __MAP_H__

#include <deque>
#include <iostream>
#include "Weapon.h"
#include "Object.h"
#include "Tank.h"
#include "Box.h"

#include "Bullet.h"
#include "MiniGun.h"
#include "Missle.h"
#include "Fire.h"
#include "Drone.h"
#include "Group.h"

#include "Environment.h"

#include "RandomP.h"
#include "Boom.h"
#include "UserInterface.h"

using namespace std;

class Map
{
public:
	Map();//生成地图空间
	//template<typename T> deque<T> showdeque(deque<T> X);
	void MapRefresh();//地图刷新（结算等级：击毁（包括炮弹到达边界或射程）>行动>攻击）
	double MapDistance(int px1, int py1, int px2, int py2);
	void DetectNonATTEvent();//非攻击事件检测
	void DetectATTEvent();//攻击事件检测
	void TankAttack();
	void MapDisplay();
	friend class TankGroup;
	friend class UserInterface;
protected:
	deque<Tank*>& Etank;
	deque<Tank*>& Ftank;
	deque<Box*>& B;
	deque<Bullet*>& Bu;
	deque<MiniGun*>& Mg;
	deque<Missle*>& M;
	deque<Fire*>& F;
	deque<Drone*>& D;
	deque<Boom*>& BO;
	TankGroup Fgroup;
	TankGroup Egroup;
	Tank UserTank;
};

#endif // !__MAP_H__

