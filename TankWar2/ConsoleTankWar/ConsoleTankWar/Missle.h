#pragma once
#ifndef __MISSLE_H__
#define __MISSLE_H__

#include "Object.h"
#include "Weapon.h"
#include "Tank.h"
#include <deque>

class Missle :public Object, public Weapon
{
public:
	Missle();
	Missle(int px, int py,double dr, WSIDE w);
	~Missle();
	void display();
	bool checkrange();
	void gettarget(deque<Tank> TX);
	double TargetDistance(Tank C);
	void setdir(deque<Tank> TX);
protected:
	int targetnumber;
};

#endif // !__MISSLE_H__

