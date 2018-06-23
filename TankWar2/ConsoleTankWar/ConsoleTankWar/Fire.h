#pragma once
#ifndef __FIRE_H__
#define __FIRE_H__

#include "Weapon.h"
#include "Object.h"

class Fire :public Object, public Weapon
{
public:
	Fire();
	~Fire();
	void display();
protected:
};

#endif // !__FIRE_H__
