// ConsoleTankWar.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Map.h"
#include "UserInterface.h"
#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<cmath>
#include<time.h>

#define PI 3.14159265358979

int main()
{
	Map m;
	UI u;
	int i;
	u.Initgraph;
	for (i = 1; i <= 10000; i++)
	{
		m.MapRefresh();
		m.MapDisplay();
		Sleep(10);
	}
	closegraph();
    return 0;
}

