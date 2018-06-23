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
	virtual bool checkload()=0; 
	virtual void launch() = 0;
protected:
	int power;
};

#endif // !__WEAPON_H__
