#include "iostream"

using namespace std;


// 定义一个立方体，求立方体的的体积和面积
// 判断两个立方体是否相等

class SixFace
{
public:
	void setABC(int _a, int _b, int _c)
	{
		a = _a;
		b = _b;
		c = _c;
	}
	int getS()
	{
		s = (a * b + b * c + a * c) * 2;
		return s;
	}

	int getV()
	{
		v = a * b * c;
		return v;
	}
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
	int getC()
	{
		return c;
	}

	int judgeSixFace(SixFace& s1, SixFace& s2)
	{
		if (s1.getA() == s2.getA() &&
			s1.getB() == s2.getB() &&
			s1.getC() == s2.getC())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int judgeSixFace(SixFace& s2)
	{
		if (a == s2.getA() &&
			b == s2.getB() &&
			c == s2.getC())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
private:
	int a;
	int b;
	int c;
	int s;
	int v;

};

void main00()
{
	SixFace s1,s2;
	s1.setABC(1, 2, 3);
	cout << "s1 : v:" << s1.getV() << endl;
	cout << "s1 : s:" << s1.getS() << endl;

	s2.setABC(1, 2, 4);
	cout << "Hello World!" << endl;
	system("pause");
}
 

// 全局函数实现，立方体相等判断
int judgeSixFace(SixFace& s1, SixFace& s2)
{
	if (s1.getA() == s2.getA() &&
		s1.getB() == s2.getB() &&
		s1.getC() == s2.getC())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void main01()
{
	SixFace s1, s2;
	s1.setABC(1, 2, 3);
	cout << "s1 : v:" << s1.getV() << endl;
	cout << "s1 : s:" << s1.getS() << endl;

	s2.setABC(1, 2, 4);
	if (judgeSixFace(s1, s2))
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
	cout << "Hello World!" << endl;
	system("pause");
}

// 类方法实现
void main()
{
	SixFace s1, s2;
	s1.setABC(1, 2, 3);
	cout << "s1 : v:" << s1.getV() << endl;
	cout << "s1 : s:" << s1.getS() << endl;

	s2.setABC(1, 2, 4);
	cout << "s2.setABC(1, 2, 4)" << endl;
	if (s1.judgeSixFace(s1, s2))
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	s2.setABC(1, 2, 3);
	cout << "s2.setABC(1, 2, 3)" << endl;
	if (s1.judgeSixFace(s2))
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	cout << "Hello World!" << endl;
	system("pause");
}