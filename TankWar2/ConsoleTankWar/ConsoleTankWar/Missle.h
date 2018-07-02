#pragma once
#ifndef __MISSLE_H__
#define __MISSLE_H__

#include "Object.h"
#include "Weapon.h"
#include "Tank.h"
#include <deque>

using namespace std;

template <typename T>;

class Missle :public Object, public Weapon
{
public:
	Missle();
	Missle(int px, int py,double dr, WSIDE w);
	~Missle();
	void display()
	{
		if (visible)
		{
			setlinecolor(0x8aaaff);
			circle(x, y, 1);
			setfillcolor(GREEN);
			fillcircle(x, y, 1);
		}
	};
	bool checkrange()
	{
		if (mile == range) return false;
		else return true;
	};
	void setdir(double d) { dir = d; };
	void settargetnumber(int tn) { targetnumber = tn; };
	int stn() { return targetnumber; };
protected:
	int targetnumber;
};

#endif // !__MISSLE_H__

Missle::Missle()
{
	Weapon::SetPW(150);
	reset(0, 0, 0, 3, false, false, 3, 900, 0);
	Weapon::SetWS(EW);
}

Missle::Missle(int px, int py, double dr, WSIDE w)
{
	Weapon::SetPW(150);
	reset(px, py, dr, 3, true, true, 3, 900, 0);
	Weapon::SetWS(w);
}



Missle::~Missle()
{

}


