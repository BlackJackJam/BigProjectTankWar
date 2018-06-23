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
protected:
	SIDE side;
	CONTROL con;
	int health;
	WEAPONTYPE CurrentWeapon;
	Bullet B;
	MiniGun MG;
	Drone D;
	Missle MS;
	Weapon *W;
	Object *O;
};

#endif // !__TANK_H__



