#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <graphics.h>

using namespace std;

class Object
{
public:
	Object();
	virtual ~Object();
	virtual void display();
	int ShowPosX();
	int ShowPosY();
	double ShowDir();
protected:
	int x;
	int y;
	double dir;
	int pace;
	bool exist;
	bool visible;
	int sphere;
};

#endif
