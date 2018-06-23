#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "Environment.h"

using namespace std;

enum WEAPONTYPE {BULLET, MINIGUN, DRONE, MISSLE, FIRE};

class Weapon
{
public:
	Weapon();
	virtual ~Weapon();
protected:
	int power;
};

#endif // !__WEAPON_H__
