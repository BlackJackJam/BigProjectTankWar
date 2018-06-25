#include "stdafx.h"
#include "Tank.h"


static int N = 0;

Tank::Tank()
{
	RandomP X, Y, D;
	x = (int)X.uniform()*WIDTH;
	y = (int)Y.uniform()*HEIGHT;
	dir = D.uniform() * 360;
	health = Maxhealth;
	side = Enemy;
	con = AI;
	CurrentWeapon = BULLET;
	Bload = 5;
	Fload = 0;
	Dload = 0;
	Mload = 0;
	BL = true;
	sphere = 5;
	pace = 1;
	mile = 0;
	range = 0;
	visible = true;
	exist = true;
	number = N;
	N++;
}

Tank::Tank(int px, int py, double rdir, SIDE si, CONTROL co)
{
	x = px;
	y = py;
	dir = rdir;
	health = Maxhealth;
	side = si;
	con = co;
	CurrentWeapon = BULLET;
	Bload = 5;
	Fload = 0;
	Dload = 0;
	Mload = 0;
	BL = true;
	sphere = 5;
	pace = 1;
	mile = 0;
	range = 0;
	visible = true;
	exist = true;
	number = N;
	N++;
}

Tank::Tank(SIDE si, CONTROL co)
{
	RandomP X, Y, D;
	x = (int)X.uniform()*WIDTH;
	y = (int)Y.uniform()*HEIGHT;
	dir = D.uniform() * 360;
	health = Maxhealth;
	side = si;
	con = co;
	CurrentWeapon = BULLET;
	Bload = 5;
	Fload = 0;
	Dload = 0;
	Mload = 0;
	BL = true;
	sphere = 5;
	pace = 1;
	mile = 0;
	range = 0;
	visible = true;
	exist = true;
	number = N;
	N++;
}

Tank::~Tank()
{
}

void Tank::SetTank(SIDE si, CONTROL co)
{
	side = si;
	con = co;
}

void Tank::display()
{
	setlinecolor(GREEN);
	circle(x, y, 5);
	if (con == USER) setfillcolor(WHITE);
	else if (side == Friend) setfillcolor(BROWN);
	else setfillcolor(CYAN);
	fillcircle(x, y, 5);
	setlinecolor(BLUE);
	rectangle(x - 5, y - 9, x + 5, y - 7);//ÑªÌõ
	if (side == Friend) setfillcolor(GREEN);
	else setfillcolor(RED);
	fillrectangle(x - 5, y - 9, x - 5 + (int)(health / 100), y - 7);
}

void Tank::setdir(double dr)
{
	dir = dr;
}

void Tank::reload(int cload)
{
	cload++;
}

bool Tank::checkload(WEAPONTYPE w)
{
	int current;
	current = getloadstatus(w);
	if (current == 0)
	{
		if (w == BULLET)
		{
			BL = false;
			reload(Bload);
		}
		return false;
	}
	else if (w == BULLET)
	{
		if (BL == false)
		{ 
			reload(Bload);
			if (Bload == 5) BL = true;
			return false;
		}
		if (BL) return true;
	}
	return true;
}

int Tank::getloadstatus(WEAPONTYPE ww)
{
	switch (ww)
	{
	case BULLET:
		return Bload;
		break;
	case FIRE:
		return Fload;
		break;
	case DRONE:
		return Dload;
		break;
	case MISSLE:
		return Mload;
		break;
	default:
		return 0;
		break;
	}

}

int Tank::counthealth(int power)
{
	return (health - power);
}

int Tank::shownumber()
{
	return number;
}


