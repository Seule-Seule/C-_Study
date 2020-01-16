#include "04_Circular.h"

void Circular::setXYR(int _x, int _y, int _r)
{
	x = _x; y = _y; r = _r;
}
int Circular::getX()
{
	return x;
}
int Circular::getY()
{
	return y;
}
int Circular::getR()
{
	return r;
}
int Circular::judgeP(Point& p)
{
	int dd = (p.getX() - x) * (p.getX() - x) + (p.getY() - y) * (p.getY() - y);
	if (dd <= r * r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}