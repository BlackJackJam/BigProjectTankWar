#pragma once
#ifndef __MINIGUN_H__
#define __MINIGUN_H__

#include "Object.h"
#include "Weapon.h"


using namespace std;

class MiniGun :public Object, public Weapon
{
public:
	MiniGun();
	MiniGun(int px, int py, double dr);
	~MiniGun();
	bool checkrange();
	void display();
protected:

};

#endif // !__MINIGUN_H__
