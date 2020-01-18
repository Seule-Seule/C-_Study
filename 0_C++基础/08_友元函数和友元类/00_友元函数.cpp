#include "iostream"

using namespace std;


// 友元函数是类的好朋友，能访问类的私有变量
// 友元函数在类中声明的位置没有意义
class Test
{
	friend class TestB;        // 友元类声明
	friend void friendClassTest(Test* tmp, int a, int b);  // 友元函数声明
public:
	Test(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}

	void Print()
	{
		cout << "a:" << a << "\tb:" << b << endl;
	}

private:
	int a;
	int b;
};

// 友元类能访问类的私有变量
// 友元类一般用在数据操作或者类之间消息辅助传递
class TestB  // 友元类定义
{
public:
	TestB(int a, int b)
	{
		Aobj.a = a;
		Aobj.b = b;
	}

	void Print()
	{
		Aobj.Print();
	}
private:
	Test Aobj;
};

void friendClassTest(Test* tmp, int a, int b)// 友元函数定义
{
	tmp->a = a;
	tmp->b = b;
}

void main() 
{
	// 友元函数
	Test t1(1, 2);

	t1.Print();

	friendClassTest(&t1, 100, 200);
	t1.Print();

	// 友元类
	TestB b1(1, 3);
	b1.Print();

	cout << "Hello World!" << endl;
	system("pause");
}