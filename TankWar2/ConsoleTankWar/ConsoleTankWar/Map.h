#pragma once
#ifndef __MAP_H__
#define __MAP_H__

#include "Object.h"
#include "Tank.h"
#include "Box.h"
#include "Bullet.h"
#include "MiniGun.h"
#include "Missle.h"
#include "Fire.h"
#include "Drone.h"
#include <deque>
#include "Environment.h"
#include "Group.h"
#include "RandomP.h"

using namespace std;

class Map
{
public:
	Map();//生成地图空间
	template<typename T> deque<T> showdeque(deque<T> X);
	void MapRefresh();//地图刷新
	void DetectEvent();//事件检测
protected:
	deque<Tank> Etank;
	deque<Tank> Ftank;
	deque<Box> B;
	deque<Bullet> Bu;
	deque<MiniGun> Mg;
	deque<Missle> M;
	deque<Fire> F;
	deque<Drone> D;
	Tank UserTank;
};

#endif // !__MAP_H__

template<typename T>
inline deque<T> Map::showdeque(deque<T> X)
{
	return X;
}
