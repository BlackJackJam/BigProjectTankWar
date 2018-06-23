#pragma once
#ifndef __MISSLE_H__
#define __MISSLE_H__

#include "Object.h"
#include "Weapon.h"

class Missle :public Object, public Weapon
{
public:
	Missle();
	~Missle();
	bool checkload();
	void launch();
	void display();
protected:
	static int load;
};

#endif // !__MISSLE_H__

