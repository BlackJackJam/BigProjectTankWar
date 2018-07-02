#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <graphics.h>
#include "Environment.h"
#include <cmath>
#include <iostream>

using namespace std;

class Object
{
public:
	Object();
	Object(int ox, int oy, double odir, int opace, bool oexist, bool ovisible, int osphere, int orange, int omile);
	~Object();
	int ShowPosX();
	int ShowPosY();
	double ShowDir();
	void moveO();
	void reset(int ox, int oy, double odir, int opace, bool oexist, bool ovisible, int osphere, int orange, int omile);
	int countsphere() { return sphere; };
	bool ShowExist() { return exist; };
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
