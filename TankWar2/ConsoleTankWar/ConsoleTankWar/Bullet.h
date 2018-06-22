#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Weapon.h"
#include "Object.h"

using namespace std;


class Bullet :public Weapon,public Object
{
public:
	Bullet();
	~Bullet();
	virtual void display();
	bool checkload();
protected:
	int Maxload = 5;
};

#endif // !__BULLET_H__
