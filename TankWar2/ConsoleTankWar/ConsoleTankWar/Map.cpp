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

double Map::MapDistance(int px1, int py1, int px2, int py2)
{
	double D;
	D = sqrt((px1 - px2)*(px1 - px2) + (py1 - py2)*(py1 - py2));
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
				double DD;
				double drx;
				int fx, fy, ex, ey;
				fx = fit->ShowPosX();
				fy = fit->ShowPosY();
				ex = eit->ShowPosX();
				ey = eit->ShowPosY();
				DD = MapDistance(fit->ShowPosX(), fit->ShowPosY(), eit->ShowPosX(), eit->ShowPosY());
				drx = atan2((fx - ex), (fy - ey)) * 180 / PI;
				if (DD <=(double) eit->countsphere() + fit->countsphere())
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
			int tx, ty, bx, by;
			double dbt;
			tx = fit->ShowPosX();
			ty = fit->ShowPosY();
			bx = bit->ShowPosX();
			by = bit->ShowPosY();
			dbt = MapDistance(tx, ty, bx, by);
			if (dbt <= (double)bit->countsphere() + fit->countsphere())
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
			int tx, ty, bx, by;
			double dbt;
			tx = eit->ShowPosX();
			ty = eit->ShowPosY();
			bx = bit->ShowPosX();
			by = bit->ShowPosY();
			dbt = MapDistance(tx, ty, bx, by);
			if (dbt <= (double)bit->countsphere() + eit->countsphere())
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
	deque<Tank>::iterator fit;
	deque<Tank>::iterator eit;
	for (buit = Bu.begin(); buit != Bu.end(); buit++)
	{
		if (buit->ShowPosX() <= 0 || buit->ShowPosY() <= 0 || buit->ShowPosX() >= WIDTH || buit->ShowPosY() >= HEIGHT)
		{
			BO.push_back(Boom(buit->ShowPosX(), buit->ShowPosY()));
		}
		else if (buit->checkrange() == false)
		{
			BO.push_back(Boom(buit->ShowPosX(), buit->ShowPosY()));
		}
		else
		{
			for (fit = Ftank.begin(); fit != Ftank.end(); fit++)
			{
				double dfb;
				dfb = MapDistance(buit->ShowPosX(), buit->ShowPosY(), fit->ShowPosX(), fit->ShowPosY);
				if ((buit->getWS() == EW)&&(dfb<=(double)buit->countsphere()+fit->countsphere()))
				{
					BO.push_back(Boom(buit->ShowPosX(), buit->ShowPosY()));
					fit->counthealth(buit->showpower);
				}
			}
			for (eit = Etank.begin(); eit != Etank.end(); eit++)
			{
				double deb;
				deb = MapDistance(buit->ShowPosX(), buit->ShowPosY(), eit->ShowPosX(), eit->ShowPosY);
				if ((buit->getWS() == FW) && (deb <= (double)buit->countsphere() + eit->countsphere()))
				{
					BO.push_back(Boom(buit->ShowPosX(), buit->ShowPosY()));
					eit->counthealth(buit->showpower);
				}
			}
		}
	}
	for (mgit = Mg.begin(); mgit != Mg.end(); mgit++)
	{
		if (mgit->ShowPosX() <= 0 || mgit->ShowPosY() <= 0 || mgit->ShowPosX() >= WIDTH || mgit->ShowPosY() >= HEIGHT)
		{
			BO.push_back(Boom(mgit->ShowPosX(), mgit->ShowPosY()));
		}
		else if (mgit->checkrange() == false)
		{
			BO.push_back(Boom(mgit->ShowPosX(), mgit->ShowPosY()));
		}
		else
		{
			for (fit = Ftank.begin(); fit != Ftank.end(); fit++)
			{
				double dfb;
				dfb = MapDistance(mgit->ShowPosX(), mgit->ShowPosY(), fit->ShowPosX(), fit->ShowPosY);
				if ((mgit->getWS() == EW) && (dfb <= (double)mgit->countsphere() + fit->countsphere()))
				{
					BO.push_back(Boom(mgit->ShowPosX(), mgit->ShowPosY()));
					fit->counthealth(mgit->showpower);
				}
			}
			for (eit = Etank.begin(); eit != Etank.end(); eit++)
			{
				double deb;
				deb = MapDistance(mgit->ShowPosX(), mgit->ShowPosY(), eit->ShowPosX(), eit->ShowPosY);
				if ((mgit->getWS() == FW) && (deb <= (double)mgit->countsphere() + eit->countsphere()))
				{
					BO.push_back(Boom(mgit->ShowPosX(), mgit->ShowPosY()));
					eit->counthealth(mgit->showpower);
				}
			}
		}
	}
	for (frit = F.begin(); frit != F.end(); frit++)
	{
		if (frit->ShowPosX() <= 0 || frit->ShowPosY() <= 0 || frit->ShowPosX() >= WIDTH || frit->ShowPosY() >= HEIGHT)
		{
			BO.push_back(Boom(frit->ShowPosX(), frit->ShowPosY()));
		}
		else if (frit->checkrange() == false)
		{
			BO.push_back(Boom(frit->ShowPosX(), frit->ShowPosY()));
		}
		else
		{
			for (fit = Ftank.begin(); fit != Ftank.end(); fit++)
			{
				double dfb;
				dfb = MapDistance(frit->ShowPosX(), frit->ShowPosY(), fit->ShowPosX(), fit->ShowPosY);
				if ((frit->getWS() == EW) && (dfb <= (double)frit->countsphere() + fit->countsphere()))
				{
					BO.push_back(Boom(frit->ShowPosX(), frit->ShowPosY()));
					fit->counthealth(frit->showpower);
				}
			}
			for (eit = Etank.begin(); eit != Etank.end(); eit++)
			{
				double deb;
				deb = MapDistance(frit->ShowPosX(), frit->ShowPosY(), eit->ShowPosX(), eit->ShowPosY);
				if ((frit->getWS() == FW) && (deb <= (double)frit->countsphere() + eit->countsphere()))
				{
					BO.push_back(Boom(frit->ShowPosX(), frit->ShowPosY()));
					eit->counthealth(frit->showpower);
				}
			}
		}
	}
	for (msit = M.begin(); msit != M.end(); msit++)
	{
		if (msit->ShowPosX() <= 0 || msit->ShowPosY() <= 0 || msit->ShowPosX() >= WIDTH || msit->ShowPosY() >= HEIGHT)
		{
			BO.push_back(Boom(msit->ShowPosX(), msit->ShowPosY()));
		}
		else if (msit->checkrange() == false)
		{
			BO.push_back(Boom(msit->ShowPosX(), msit->ShowPosY()));
		}
		else
		{
			for (fit = Ftank.begin(); fit != Ftank.end(); fit++)
			{
				double dfb;
				dfb = MapDistance(msit->ShowPosX(), msit->ShowPosY(), fit->ShowPosX(), fit->ShowPosY);
				if ((msit->getWS() == EW) && (dfb <= (double)msit->countsphere() + fit->countsphere()))
				{
					BO.push_back(Boom(msit->ShowPosX(), msit->ShowPosY()));
					fit->counthealth(msit->showpower);
				}
			}
			for (eit = Etank.begin(); eit != Etank.end(); eit++)
			{
				double deb;
				deb = MapDistance(msit->ShowPosX(), msit->ShowPosY(), eit->ShowPosX(), eit->ShowPosY);
				if ((msit->getWS() == FW) && (deb <= (double)msit->countsphere() + eit->countsphere()))
				{
					BO.push_back(Boom(msit->ShowPosX(), msit->ShowPosY()));
					eit->counthealth(msit->showpower);
				}
			}
		}
	}
	for (dit = D.begin(); dit != D.end(); dit++)
	{
		if (dit->ShowPosX() <= 0 || dit->ShowPosY() <= 0 || dit->ShowPosX() >= WIDTH || dit->ShowPosY() >= HEIGHT)
		{
			BO.push_back(Boom(dit->ShowPosX(), dit->ShowPosY()));
		}
		else if (dit->checkrange() == false)
		{
			BO.push_back(Boom(dit->ShowPosX(), dit->ShowPosY()));
		}
		else
		{
			for (fit = Ftank.begin(); fit != Ftank.end(); fit++)
			{
				double dfb;
				dfb = MapDistance(dit->ShowPosX(), dit->ShowPosY(), fit->ShowPosX(), fit->ShowPosY);
				if ((dit->getWS() == EW) && (dfb <= (double)dit->countsphere() + fit->countsphere()))
				{
					BO.push_back(Boom(dit->ShowPosX(), dit->ShowPosY()));
					fit->counthealth(dit->showpower);
				}
			}
			for (eit = Etank.begin(); eit != Etank.end(); eit++)
			{
				double deb;
				deb = MapDistance(dit->ShowPosX(), dit->ShowPosY(), eit->ShowPosX(), eit->ShowPosY);
				if ((dit->getWS() == FW) && (deb <= (double)dit->countsphere() + eit->countsphere()))
				{
					BO.push_back(Boom(dit->ShowPosX(), dit->ShowPosY()));
					eit->counthealth(dit->showpower);
				}
			}
		}
	}
}

void Map::TankAttack()//坦克自动攻击
{
	deque<Tank>::iterator fit;
	deque<Tank>::iterator eit;
	deque<Missle>::iterator mit;
	double Xdir;
	double dd;
	WEAPONTYPE wt;
	for (fit = Ftank.begin(); fit != Ftank.end(); fit++)
	{
		for (eit = Etank.begin(); eit != Etank.end(); eit++)
		{
			dd = MapDistance(eit->ShowPosX(), eit->ShowPosY(), fit->ShowPosX(), fit->ShowPosY());
			Xdir = atan2(eit->ShowPosX() - fit->ShowPosX(), eit->ShowPosY() - fit->ShowPosX());
			if (fit->checkUser() == false && fit->checkload(MISSLE) == true)
			{
				M.push_back(Missle(fit->ShowPosX(), fit->ShowPosY(),fit->ShowDir(), FW));
				mit = M.end();
				mit->gettarget(Etank);
				mit->setdir(Etank);
				fit->launchMissle();
			}
			else if (fit->checkUser()==false&&Xdir==fit->ShowDir()&&dd<=150)
			{
				wt=fit->usingWeapon();
				switch (wt)
				{
				case FIRE:
					F.push_back(Fire(fit->ShowPosX(), fit->ShowPosY(), fit->ShowDir(), FW));
					break;
				case DRONE:
					D.push_back(Drone(fit->ShowPosX(), fit->ShowPosY(), fit->ShowDir(), FW));
					break;
				case BULLET:
					Bu.push_back(Bullet(fit->ShowPosX(), fit->ShowPosY(), fit->ShowDir(), FW));
					break;
				case MINIGUN:
					Mg.push_back(MiniGun(fit->ShowPosX(), fit->ShowPosY(), fit->ShowDir(), FW));
					break;
				default:
					break;
				}
			}
		}
	}
	for (eit = Ftank.begin(); eit != Ftank.end(); eit++)
	{
		for (fit = Etank.begin(); fit != Etank.end(); fit++)
		{
			dd = MapDistance(eit->ShowPosX(), eit->ShowPosY(), fit->ShowPosX(), fit->ShowPosY());
			Xdir = atan2(fit->ShowPosX() - eit->ShowPosX(), fit->ShowPosY() - eit->ShowPosX());
			if (eit->checkload(MISSLE) == true)
			{
				M.push_back(Missle(eit->ShowPosX(), eit->ShowPosY(), eit->ShowDir(), EW));
				mit = M.end();
				mit->gettarget(Ftank);
				mit->setdir(Ftank);
				eit->launchMissle();
			}
			else if (Xdir == eit->ShowDir() && dd <= 150)
			{
				wt = eit->usingWeapon();
				switch (wt)
				{
				case FIRE:
					F.push_back(Fire(eit->ShowPosX(), eit->ShowPosY(), eit->ShowDir(), EW));
					break;
				case DRONE:
					D.push_back(Drone(eit->ShowPosX(), eit->ShowPosY(), eit->ShowDir(), EW));
					break;
				case BULLET:
					Bu.push_back(Bullet(eit->ShowPosX(), eit->ShowPosY(), eit->ShowDir(), EW));
					break;
				case MINIGUN:
					Mg.push_back(MiniGun(eit->ShowPosX(), eit->ShowPosY(), eit->ShowDir(), EW));
					break;
				default:
					break;
				}
			}
		}
	}
}
