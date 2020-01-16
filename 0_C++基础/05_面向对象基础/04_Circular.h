#pragma once

#include "04_Point.h"

class Circular
{
public:
	void setXYR(int _x, int _y, int _r);
	int getX();
	int getY();
	int getR();
	int judgeP(Point& p);

private:
	int x;
	int y;
	int r;
};