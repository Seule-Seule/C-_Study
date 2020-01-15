#include "iostream"

using namespace std;


//  定义一个圆类，一个点类，判断点是否在圆上
class Point
{
public:
	void setXY(int _x, int _y)
	{
		x = _x;  y = _y;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
private:
	int x;
	int y;
};

class Circular
{
public:
	void setXYR(int _x, int _y, int _r)
	{
		x = _x; y = _y; r = _r;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getR()
	{
		return r;
	}
	int judgeP(Point& p)
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
private:
	int x;
	int y;
	int r;
};

void main() 
{
	Point p1;
	Circular c1;

	p1.setXY(5, 5);
	c1.setXYR(3, 3, 3);

	if (c1.judgeP(p1))
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
		 
	cout << "Hello World!" << endl;
	system("pause");
}