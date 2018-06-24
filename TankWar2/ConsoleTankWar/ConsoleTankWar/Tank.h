#pragma once
#ifndef __TANK_H__
#define __TANK_H__

#include "Object.h"
#include "Weapon.h"
#include "Bullet.h"
#include "MiniGun.h"
#include "Missle.h"
#include "Drone.h"
#include "RandomP.h"

using namespace std;

enum SIDE {Friend,Enemy};
enum CONTROL {AI,USER};

class Tank:public Object
{
public:
	Tank();
	Tank(int px, int py, double rdir, SIDE si,CONTROL co);
	Tank(SIDE si, CONTROL co);
	~Tank();
	void SetTank(SIDE si, CONTROL co);
	void display();
	void reload(int cload);
	bool checkload(WEAPONTYPE w);
	int getloadstatus(WEAPONTYPE ww);
	bool checkrange() { return true; };
	int counthealth(int power);
	int shownumber();
protected:
	SIDE side;
	CONTROL con;
	const int Maxhealth = 1000;
	int health;
	WEAPONTYPE CurrentWeapon;
	int Bload;
	int Fload;
	int Dload;
	int Mload;
	bool BL;
	int number;
	static int N;
};

#endif // !__TANK_H__



