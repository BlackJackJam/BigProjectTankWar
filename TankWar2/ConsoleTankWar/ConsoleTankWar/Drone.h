#pragma once
#ifndef __DRONE_H__
#define __DRONE_H__

#include "Object.h"
#include "Weapon.h"


class Drone :public Object, public Weapon
{
public:
	Drone();
	~Drone();
	bool checkload();
	void display();
	void launch();
protected:
	static int load;
};

#endif // !__DRONE_H__
