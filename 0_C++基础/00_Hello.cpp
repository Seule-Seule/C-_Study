/*
#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int	ErroMsg = 0;
	
	
	return ErroMsg;
}
*/
#include "iostream" // 包含C++头  //iostream.h

using namespace std;  //std 标准命名空间，定义了很多标准定义。

void main_00() {

	// cout 标准输出 对象？？？ 可能是黑屏幕
	// << 左移操作符 不是左移？？ 据说是操作符重载
	// endl == \n
	cout << "Hello World!" << endl;
	system("pause");
}

//面向过程，圆面积计算
void main_01() {
	double	r = 0;
	double	s = 0;
	cout << "输入半径：";
	cin >> r;

	s = 3.14  *r * r;

	cout << "面积：" << s << endl;

	cout << "Hello World!" << endl;
	system("pause");
}


//面向对象
//内存分配？？
//类方法参数传递？？
class  Round
{
public:
	double	m_r;
	double	m_s;

public:
	void SetR(double r)
	{
		m_r = r;
	}
	double GetS()
	{
		m_s = m_r * m_r * 3.14;
		return m_s;
	}
};

void main() {
	Round	c;
	double	r;
	cout << "输入半径：";
	cin >> r;
	c.SetR(r);

	cout << "面积：" << c.GetS() << endl;
	cout << "Hello World!" << endl;
	system("pause");
}