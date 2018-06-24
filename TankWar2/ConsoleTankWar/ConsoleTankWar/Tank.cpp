#include "Tank.h"
#include "stdafx.h"

void Tank::display()
{


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


