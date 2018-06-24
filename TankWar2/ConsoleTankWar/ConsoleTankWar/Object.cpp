#include "Object.h"
#include "stdafx.h"

Object::Object()
{
	x = 0;
	y = 0;
	dir = 0;
	pace = 0;
	sphere = 0;
	mile = 0;
	exist = false;
	visible = false;
}

Object::~Object()
{

}

int Object::ShowPosX()
{
	return x;
}

int Object::ShowPosY()
{
	return y;
}

double Object::ShowDir()
{
	return dir;
}

void Object::moveO()
{
	x += (int)(pace * cos((dir / 360) * 2 * PI));
	y += (int)(pace * sin((dir / 360) * 2 * PI));
	mile += pace;
}
 