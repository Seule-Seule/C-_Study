#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
using namespace std;

class Test
{
public:
	Test()   //  构造函数
		// 定义一个对象时，编译器自动调用
	{
		a = 0;
		b = 0;
	}
	void Print()
	{
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	~Test()  // 析构函数
		// 销毁一个对象时，编译器自动调用
	{
		
		cout << "析构函数" << endl;
	}
private:
	int a;
	int b;
};

void testClass()
{
	Test t1, t2;
	t1.Print();
	t2.Print();
}

void main() 
{
	testClass();

	cout << "Hello World!" << endl;
	system("pause");
}