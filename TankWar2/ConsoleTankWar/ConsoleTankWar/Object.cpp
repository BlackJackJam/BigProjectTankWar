#include "Object.h"
#include "stdafx.h"

void Object::move()
{
	x += (int)(pace * cos((dir / 360) * 2 * PI));
	y += (int)(pace * sin((dir / 360) * 2 * PI));
	mile += pace;
}
