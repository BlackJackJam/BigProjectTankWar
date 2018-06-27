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



void Map::DetectNonATTEvent()//检测非攻击事件，具体而言为与武器操作无关的坦克碰撞，吃箱子事件 
{
	RandomP DX;
	deque<Tank>::iterator fit;
	deque<Tank>::iterator eit;
	deque<Box>::iterator bit;
	for (fit = Ftank.begin(); fit != Ftank.end(); fit++)
	{
		if (fit->checkUser() == false)
		{
			for (eit = Etank.begin(); eit != Etank.end(); eit++)
			{
				int DD;
				double drx;
				int fx, fy, ex, ey;
				fx = fit->ShowPosX();
				fy = fit->ShowPosY();
				ex = eit->ShowPosX();
				ey = eit->ShowPosY();
				DD = MapDistance(fit->ShowPosX(), fit->ShowPosY(), eit->ShowPosX(), eit->ShowPosY());
				drx = atan2((fx - ex), (fy - ey)) * 180 / PI;
				if (DD <= eit->countsphere() + fit->countsphere())
				{
					eit->setdir(-drx + 10 - 20 * DX.uniform());
					fit->setdir(drx + 10 - 20 * DX.uniform());
				}
			}
		}
	}
	for (fit = Ftank.begin(); fit != Ftank.end(); fit++)
	{
		int tx, ty;
		tx = fit->ShowPosX();
		ty = fit->ShowPosY();
		if (fit->checkUser()==false)
		{ 
			if ((tx <= fit->countsphere()) && (ty <= fit->countsphere())) fit->setdir(90-90*DX.uniform());
			if ((tx <= fit->countsphere()) && ((HEIGHT - ty) <= fit->countsphere())) fit->setdir(-90*DX.uniform());
			if (((WIDTH - tx) <= fit->countsphere()) && ((HEIGHT - ty) <= fit->countsphere())) fit->setdir(-90-90*DX.uniform());
			if (((WIDTH - tx) <= fit->countsphere()) && (ty <= fit->countsphere())) fit->setdir(90+90*DX.uniform());
			else
			{
				if (tx <= fit->countsphere()) fit->setdir(90-180*DX.uniform());
				if ((WIDTH - tx) <= fit->countsphere()) fit->setdir(90+180*DX.uniform());
				if (ty <= fit->countsphere()) fit->setdir(180*DX.uniform());
				if ((HEIGHT - ty) <= fit->countsphere()) fit->setdir(-180*DX.uniform());
			}//检查AI坦克是否位于边界，如是，改变其方向(随机)
		}//主坦克的边界条件在用户指令输入处另行处理

	}
	for (eit = Etank.begin(); eit != Etank.end(); fit++)
	{
		int tx, ty;
		tx = eit->ShowPosX();
		ty = eit->ShowPosY();
		if (eit->checkUser() == false)
		{
			if ((tx <= eit->countsphere()) && (ty <= eit->countsphere())) eit->setdir(90 - 90 * DX.uniform());
			if ((tx <= eit->countsphere()) && ((HEIGHT - ty) <= eit->countsphere())) eit->setdir(-90 * DX.uniform());
			if (((WIDTH - tx) <= eit->countsphere()) && ((HEIGHT - ty) <= eit->countsphere())) eit->setdir(-90 - 90 * DX.uniform());
			if (((WIDTH - tx) <= eit->countsphere()) && (ty <= eit->countsphere())) eit->setdir(90 + 90 * DX.uniform());
			else
			{
				if (tx <= eit->countsphere()) eit->setdir(90 - 180 * DX.uniform());
				if ((WIDTH - tx) <= eit->countsphere()) eit->setdir(90 + 180 * DX.uniform());
				if (ty <= eit->countsphere()) eit->setdir(180 * DX.uniform());
				if ((HEIGHT - ty) <= eit->countsphere()) eit->setdir(-180 * DX.uniform());
			}//检查AI坦克是否位于边界，如是，改变其方向(随机)
		}//主坦克的边界条件在用户指令输入处另行处理
	}
	for (fit = Ftank.begin(); fit != Ftank.end(); fit++)//我方坦克是否吃到箱子
	{
		for (bit = B.begin(); bit != B.end(); bit++)
		{
			int tx, ty, bx, by, dbt;
			tx = fit->ShowPosX();
			ty = fit->ShowPosY();
			bx = bit->ShowPosX();
			by = bit->ShowPosY();
			dbt = MapDistance(tx, ty, bx, by);
			if (dbt <= bit->countsphere() + fit->countsphere())
			{
				WEAPONTYPE tp;
				tp = bit->show();
				fit->reload(tp);
			}
		}
	}
	for (eit = Etank.begin(); eit != Etank.end(); eit++)//敌方坦克是否吃到箱子
	{
		for (bit = B.begin(); bit != B.end(); bit++)
		{
			int tx, ty, bx, by, dbt;
			tx = eit->ShowPosX();
			ty = eit->ShowPosY();
			bx = bit->ShowPosX();
			by = bit->ShowPosY();
			dbt = MapDistance(tx, ty, bx, by);
			if (dbt <= bit->countsphere() + eit->countsphere())
			{
				WEAPONTYPE tp;
				tp = bit->show();
				eit->reload(tp);
			}
		}
	}
}

void Map::DetectATTEvent()
{
	deque<Bullet>::iterator buit;
	deque<MiniGun>::iterator mgit;
	deque<Missle>::iterator msit;
	deque<Fire>::iterator frit;
	deque<Drone>::iterator dit;
	for (buit = Bu.begin(); buit != Bu.end(); buit++)
	{
		if
	}
}
