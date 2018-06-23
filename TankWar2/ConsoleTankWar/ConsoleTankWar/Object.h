#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <graphics.h>
#include "Environment.h"
#include <cmath>

using namespace std;

class Object
{
public:
	Object();
	virtual ~Object();
	virtual void display() = 0;
	int ShowPosX();
	int ShowPosY();
	double ShowDir();
	void move();
	virtual bool checkrange() = 0;
protected:
	int x;
	int y;
	double dir;
	int pace;
	bool exist;
	bool visible;
	int sphere;
	int range;
	int mile;
};

#endif
