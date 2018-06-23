#pragma once
#ifndef __TANK_H__
#define __TANK_H__

#include "Object.h"
#include "Weapon.h"
#include "Bullet.h"
#include "MiniGun.h"
#include "Missle.h"
#include "Drone.h"

using namespace std;

enum SIDE {Friend,Enemy};
enum CONTROL {AI,USER};

class Tank:public Object
{
public:
	Tank();
	Tank(int px, int py, double rdir, SIDE si);
	~Tank();
	void display();
	void reload();
	bool checkload(WEAPONTYPE w);
	bool checkrange() { return true; };
protected:
	SIDE side;
	CONTROL con;
	const int Maxhealth = 1000;
	int health;
	WEAPONTYPE CurrentWeapon;
	int Bload;
	bool BLOAD;
	int Fload;
	int Dload;
	int Mload;
};

#endif // !__TANK_H__



