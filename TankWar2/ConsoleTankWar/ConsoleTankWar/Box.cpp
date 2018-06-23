#include "Box.h"
#include "RandomP.h"


Box::Box()
{
	RandomP B, X, Y, E;
	int px, py, wt, EX;
	px = (int)X.uniform() * WIDTH;
	py = (int)Y.uniform() * HEIGHT;
	wt = (int)B.uniform() * 4;
	switch (wt)
	{
	case 0:
		tpp = DRONE;
		break;
	case 1:
		tpp = MISSLE;
		break;
	case 2:
		tpp = MISSLE;
		break;
	case 3:
		tpp = FIRE;
		break;
	case 4:
		tpp = FIRE;
		break;
	default:
		break;
	}
	x = px;
	y = py;
	dir = 0;
	sphere = 0;
	EX = E.poisson(0.1);
	if (EX == 0) exist = false;
	else exist = true;
	visible = true;
}

Box::~Box()
{
}
