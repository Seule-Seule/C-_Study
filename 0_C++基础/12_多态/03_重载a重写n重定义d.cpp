
#include "iostream"
using namespace std;


class TestA
{
public:
	void func()
	{
		cout << "TestA::func()" << endl;
	}
	void func(int a)
	{
		cout << "TestA::func(int a)" << endl;
	}
	void func(int a, int b)
	{
		cout << "TestA::func(int a, int b)" << endl;
	}
	virtual void func(int a, int b,int c)
	{
		cout << "TestA::func(int a, int b,int c)" << endl;
	}
};

class TestB:public TestA
{
public:
	void func(int a, int b, int c)
	{
		cout << "TestB::func(int a, int b,int c)" << endl;
	}
	void func(int a, int b, int c,int d)
	{
		cout << "TestB::func(int a, int b, int c,int d)" << endl;
	}
};


// 函数重载
//     在同一个类中的同名函数
//     子类无法重载父类函数，父类中同名函数将被覆盖(可以通过域作用符调用)
//     重载是由编译器编译过程中静态的由参数确定

// 函数重写
//     子类与父类中的同名函数
//     子类与父类中的函数必须具有相同的原型


// 函数重写分两类
//     写了virtual的函数为虚函数重写，发生多态
//     没写virtual的函数为函数重定义，调用父类

int main() 
{
	int ret = 0;

	TestB b1;
	b1.TestA::func();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}