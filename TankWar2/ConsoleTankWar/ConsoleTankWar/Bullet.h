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
	void display();
	bool checkload();
	void reload();
	void launch();
protected:
	int Maxload = 5;
	static int load;
};

#endif // !__BULLET_H__
