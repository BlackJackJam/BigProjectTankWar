#pragma once
#ifndef __MISSLE_H__
#define __MISSLE_H__

#include "Object.h"
#include "Weapon.h"

class Missle :public Object, public Weapon
{
public:
	Missle();
	Missle(int px, int py,double dr);
	~Missle();
	void display();
protected:
};

#endif // !__MISSLE_H__

