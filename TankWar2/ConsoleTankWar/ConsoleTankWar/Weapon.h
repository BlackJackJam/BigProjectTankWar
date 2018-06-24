#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "Environment.h"

using namespace std;

enum WEAPONTYPE {BULLET, MINIGUN, DRONE, MISSLE, FIRE};
enum WSIDE {FW,EW};

class Weapon
{
public:
	Weapon();
	virtual ~Weapon();
protected:
	int power;
	WSIDE ws;//ÎäÆ÷ÕóÓª±ê¼Ç
};

#endif // !__WEAPON_H__
