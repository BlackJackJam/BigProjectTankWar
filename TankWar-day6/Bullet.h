#ifndef __BULLET_H__
#define __BULLET_H__

#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	Bullet(Point pos, Dir dir, COLORREF color);
	~Bullet();

	void Display();

	void Move();

	void Boom(list<Object*>& lstBombs);

	bool IsDisappear()
	{
		return m_bDisappear;
	}

	Rect GetSphere()
	{
		return m_rectSphere;
	}

	void SetDisappear()
	{
		m_bDisappear = true;
	}

protected:
	void CalculateSphere();

	int BulletType;

	int Power;
};

#endif