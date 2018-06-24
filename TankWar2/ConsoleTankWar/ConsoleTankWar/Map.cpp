#include "stdafx.h"
#include "Map.h"
#include <windows.h>

Map::Map()
{
	int i;
	UserTank.SetTank(Friend, USER);
	for (i = 1; i <= 5; i++)
	{
		Etank.push_back(Tank(Enemy, AI));
	}
	for (i = 1; i <= 4; i++)
	{
		Ftank.push_back(Tank(Friend, AI));
	}
	Ftank.push_back(UserTank);
}
