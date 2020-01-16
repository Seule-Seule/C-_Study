#include "iostream"

using namespace std;

class  Test
{
public:
	Test()  // 无参构造函数
	{
		a = 0;
		b = 0;
	}
	Test(int _a)  // 有参构造函数
	{
		a = _a;
		b = 0;
	}
	Test(int _a, int _b)
	{
		a = _a;
		b = _b;
	}
	Test(const Test& t)  // 赋值构造函数 (或者) copy 构造函数
	{
		a = t.a;
		b = t.b;
	}

	~Test()
	{
		cout << "析构函数" << endl;
	}

private:
	int a;
	int b;
};

// 无参构造函数调用
void main00() 
{
	Test t1;

	cout << "Hello World!" << endl;
	system("pause");
}

// 有参构造函数的调用 三种方法
void main()
{
	Test t1(1, 2);  // Test(int _a, int _b)

	Test t2 = (1, 2);     // Test(int _a)  调用一个参数的构造函数
	Test t3 = (1, 2, 3, 4);  // Test(int _a) 调用一个参数的构造函数
	// 逗号表达式，最后一个逗号后面的值即为逗号表达式的值

	Test t4 = Test(2); // Test(int _a)  // 使用了匿名对象(匿名对象的生命周期? )

	cout << "Hello World!" << endl;
	system("pause");
}