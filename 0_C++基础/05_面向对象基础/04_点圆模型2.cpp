#include "iostream"

using namespace std;

#include "04_Circular.h"
#include "04_Point.h"

void main() 
{
	Point p1;
	Circular c1;

	p1.setXY(6, 7);
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