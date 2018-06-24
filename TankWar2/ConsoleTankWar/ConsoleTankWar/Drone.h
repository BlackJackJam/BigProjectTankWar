#pragma once
#ifndef __DRONE_H__
#define __DRONE_H__

#include "Object.h"
#include "Weapon.h"


class Drone :public Object, public Weapon
{
public:
	Drone();
	Drone(int px, int py, double dr);
	~Drone();
	void display();
protected:
};

#endif // !__DRONE_H__
