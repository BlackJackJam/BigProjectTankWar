#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	x = 0;
	y = 0;
	dir = 0;
	pace = 0;
	sphere = 0;
	range = 0;
	mile = 0;
	exist = false;
	visible = false;
}

Object::Object(int ox, int oy, double odir, int opace, bool oexist, bool ovisible, int osphere, int orange, int omile)
{
	x = ox;
	y = oy;
	dir = odir;
	pace = opace;
	exist = oexist;
	visible = ovisible;
	sphere = osphere;
	range = orange;
	mile = omile;
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

void Object::reset(int ox, int oy, double odir, int opace, bool oexist, bool ovisible, int osphere, int orange, int omile)
{
	x = ox;
	y = oy;
	dir = odir;
	pace = opace;
	exist = oexist;
	visible = ovisible;
	sphere = osphere;
	range = orange;
	mile = omile;
}
 