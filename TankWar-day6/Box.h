#ifndef __BOX_H__
#define __BOX_H__

#include"Object.h"

class Box : public Object
{
public:
	Box();
	Box(Point pos, Dir dir, COLORREF color);
	~Box();

	void Display();

	void Move();

	void Get();//Tank get Box

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

	int WeaponNumber;
};

#endif