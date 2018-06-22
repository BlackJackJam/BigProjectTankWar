#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "Object.h"

using namespace std;

enum WEAPONTYPE {BULLET, MINIGUN, DRONE, MISSLE, FIRE};

class Weapon :public Object
{
public:
	Weapon();
	~Weapon();
protected:
	int power;
	

};

#endif // !__WEAPON_H__
