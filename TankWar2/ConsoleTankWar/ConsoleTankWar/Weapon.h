#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "Environment.h"
#include <iostream>

using namespace std;

enum WEAPONTYPE {BULLET, MINIGUN, DRONE, MISSLE, FIRE};
enum WSIDE {FW,EW};

class Weapon
{
public:
	Weapon();
	virtual ~Weapon();
	void SetWS(WSIDE k) { ws = k; };
	void SetPW(int p) { power = p; };
	WSIDE getWS() { return ws; };
	int showpower() { return power; };
protected:
	int power;
	WSIDE ws;//ÎäÆ÷ÕóÓª±ê¼Ç
};

#endif // !__WEAPON_H__
