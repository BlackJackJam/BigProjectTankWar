#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Weapon.h"
#include "Object.h"
#include <cmath>;


using namespace std;


class Bullet :public Weapon,public Object
{
public:
	Bullet();
	Bullet(int px, int py, double dr,WSIDE w);
	~Bullet();
	void display();
	bool checkrange();
protected:
};

#endif // !__BULLET_H__
