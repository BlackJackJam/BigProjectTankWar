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
	template<typename T> deque<T> showdeque(deque<T> X);
protected:
	deque<Tank> Etank;
	deque<Tank> Ftank;
	deque<Box> B;
	deque<Bullet> Bu;
	deque<MiniGun> Mg;
	deque<Missle> M;
	deque<Fire> F;
	deque<Drone> D;
};

#endif // !__MAP_H__
