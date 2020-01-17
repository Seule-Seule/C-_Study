#include "iostream"

using namespace std;

class Test
{
public:
	Test(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
	}

	~Test()
	{
		cout << "Class Test 析构函数" << endl;
	}

	void PrintTest()
	{
		cout << "a:" << a << "\tb:" << b << endl;
	}

	//t3 = t1.testAdd(t2);
	Test testAdd(const Test &t2)
	{
		Test tmp(this->a+t2.a, this->b+t2.b);
		return tmp;
	}

	//t3.testAdd2(t2);
	Test& testAdd2(const Test& t2)
	{
		this->a = this->a + t2.a;
		this->b = this->b + t2.b;
		return *this;
	}
public:
	int a;
	int b;
};

Test testAdd(const Test &a, const Test &b)
{
	Test tmp(0, 0);
	tmp.a = a.a + b.a;
	tmp.b = a.b + b.b;
	return tmp;
}

void main() 
{
	Test t1(1, 2);
	Test t2(3, 4);
	
	Test t3 = testAdd(t1, t2);   // 全局函数
	t3.PrintTest();       

	t3 = t1.testAdd(t3);      // 成员函数
	t3.PrintTest();

	t3.testAdd2(t2);         // 成员函数返回引用
	t3.PrintTest();

	cout << "Hello World!" << endl;
	system("pause");
}