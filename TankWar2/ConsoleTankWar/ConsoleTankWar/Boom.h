#pragma once
#ifndef __BOOM_H__
#define __BOOM_H__

#include "Object.h"
#include "Environment.h"
#include <graphics.h>
#include "RandomP.h"

class Boom :public Object
{
public:
	Boom();
	Boom(int px, int py);
	void display();
	bool checkrange() { return true; };
};

#endif // !__BOOM_H__
