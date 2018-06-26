#include "stdafx.h"
#include "Map.h"
#include <windows.h>
#include "RandomP.h"
#include <cmath>
#include "Environment.h"

Map::Map()
{
	int i;
	UserTank.SetTank(Friend, USER);
	for (i = 1; i <= TN; i++)
	{
		Etank.push_back(Tank(Enemy, AI));
	}
	for (i = 1; i <= TN - 1; i++)
	{
		Ftank.push_back(Tank(Friend, AI));
	}
	Ftank.push_back(UserTank);
}

int Map::MapDistance(int px1, int py1, int px2, int py2)
{
	int D;
	D = (int)sqrt((px1 - px2)*(px1 - px2) + (py1 - py2)*(py1 - py2));
	return D;
}



void Map::DetectNonATTEvent()
{
}
