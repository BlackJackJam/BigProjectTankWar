#pragma once
#ifndef __TANK_H__
#define __TANK_H__

#include "Object.h"

using namespace std;

enum SIDE {Friend,Enemy};

class Tank:public Object
{
public:
	Tank();
	Tank(int px, int py, double rdir, SIDE si);
	~Tank();
	virtual void display();
	virtual int ShowPosX();
	virtual int ShowPosY();
	virtual double ShowDir();
protected:
	SIDE side;
	int health;
};

#endif // !__TANK_H__



