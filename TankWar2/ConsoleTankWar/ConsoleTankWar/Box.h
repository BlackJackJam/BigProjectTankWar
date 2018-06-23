#pragma once
#ifndef __BOX_H__
#define __BOX_H__

#include "Object.h"
#include "Weapon.h"


class Box :public Object
{
public:
	Box();
	~Box();
	void display();
protected:
	WEAPONTYPE tpp;
};
#endif // !__BOX_H__
