#pragma once
#ifndef __TANK_H__
#define __TANK_H__

#include "Object.h"
#include "Weapon.h"

using namespace std;

enum SIDE {Friend,Enemy};

class Tank:public Object
{
public:
	Tank();
	Tank(int px, int py, double rdir, SIDE si);
	~Tank();
	virtual void display();
protected:
	SIDE side;
	int health;
	WEAPONTYPE CurrentWeapon;
};

#endif // !__TANK_H__



