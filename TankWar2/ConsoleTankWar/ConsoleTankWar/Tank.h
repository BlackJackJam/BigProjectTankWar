#pragma once
#ifndef __TANK_H__
#define __TANK_H__

#include "Object.h"
#include "Weapon.h"
#include "Bullet.h"
#include "MiniGun.h"
#include "Missle.h"
#include "Drone.h"
#include "RandomP.h"

using namespace std;

enum SIDE {Friend,Enemy};
enum CONTROL {AI,USER};

class Tank:public Object
{
public:
	Tank();//构造函数
	Tank(int px, int py, double rdir, SIDE si,CONTROL co);//初始化特定坦克
	Tank(SIDE si, CONTROL co);//初始化随机位置特定阵营及操纵方式的坦克
	~Tank();
	void SetTank(SIDE si, CONTROL co);//设置坦克阵营及操纵模式
	void display();//坦克显示
	void setdir(double dr);//设置坦克行进方向
	void reload(WEAPONTYPE TX);//重新装填
	bool checkload(WEAPONTYPE w);//是否可以发射
	int getloadstatus(WEAPONTYPE ww);//检测弹药量
	bool checkrange() { return true; };//坦克没有运动距离限制
	int counthealth(int power);//计算血量
	int showhealth();
	int shownumber();//显示坦克编号
	bool checkUser();//检查坦克是否由用户控制
	void TankDestroy();
	void launchMissle() { Mload--; };
	WEAPONTYPE usingWeapon();//使用何种类武器
protected:
	SIDE side;
	CONTROL con;
	const int Maxhealth = 1000;
	int health;
	WEAPONTYPE CurrentWeapon;
	int Bload;
	int Fload;
	int Dload;
	int Mload;
	bool BL;
	int number;
	static int N;
};



#endif // !__TANK_H__



