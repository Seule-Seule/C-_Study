#include "iostream"

using namespace std;

class Test
{
public:
	Test()
	{
		a = 10;
	}
	void prinB()
	{
		b = b + 1;
		cout << "b:" << b << endl;
	}
	static void getB()  // 静态成员函数  // 静态方法
	{
		cout << "b:" << b << endl;
	}
protected:
private: 
	int a;
	static int b; // 静态成员变量  // 静态属性  //声明
};

// 所有类对象共用一个静态成员变量
int Test::b = 20;  // 静态成员变量的定义


void main() 
{
	Test t1, t2;
	t1.prinB();
	t2.prinB();

	// 静态方法的调用
	t1.getB();     // 对象.
	Test::getB();  // 类::

	cout << "Hello World!" << endl;
	system("pause");
}