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
	Tank();//���캯��
	Tank(int px, int py, double rdir, SIDE si,CONTROL co);//��ʼ���ض�̹��
	Tank(SIDE si, CONTROL co);//��ʼ�����λ���ض���Ӫ�����ݷ�ʽ��̹��
	~Tank();
	void SetTank(SIDE si, CONTROL co);//����̹����Ӫ������ģʽ
	void display();//̹����ʾ
	void setdir(double dr);//����̹���н�����
	void reload(WEAPONTYPE TX);//����װ��
	bool checkload(WEAPONTYPE w);//�Ƿ���Է���
	int getloadstatus(WEAPONTYPE ww);//��ⵯҩ��
	bool checkrange() { return true; };//̹��û���˶���������
	int counthealth(int power);//����Ѫ��
	int showhealth();
	int shownumber();//��ʾ̹�˱��
	bool checkUser();//���̹���Ƿ����û�����
	void TankDestroy();
	void launchMissle() { Mload--; };
	WEAPONTYPE usingWeapon();//ʹ�ú���������
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



