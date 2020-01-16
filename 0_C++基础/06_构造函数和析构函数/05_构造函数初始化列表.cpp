#include "iostream"

using namespace std;

class TestA
{
public:
	TestA(int _a)
	{
		a = _a;
		cout << "TestA 构造函数->a" << a << endl;
	}
	~TestA()
	{
		cout << "TestA 析构函数->a" << a << endl;
	}
protected:
private:
	int a;
};

class TestB
{
public:
	TestB(int _b, int _a1, int _a2, int _b2) : a1(_a1), a2(_a2), b2(_b2)
	{
		b = _b;
		cout << "TestB 的构造函数->" << b << endl;
	}
	~TestB()
	{
		cout << "TestB 的析构函数->" << b << endl;
	}
private:
	int b;
	TestA a1;
	TestA a2;
	const int b2;
};

void testClass()
{
	TestB(1, 1, 2, 2);
}


// 构造函数的初始化列表
// 类B的成员变量中有类A的组合，定义时使用构造函数的初始化列表
//    语法：Constructor::Constructor():m1(v1),m2(v1,v2),m3(v3)

// 执行顺序：
//   定义B类时，先调用A类的构造函数，后调用B类的构造函数
//    包含多个A类时，按照定义顺序调用构造函数完成构造，与初始化列表的顺序无关
//   析构函数的调用按顺序相反

// const 成员变量必须使用构造函数初始化列表初始化

void testClass2()
{
	cout << "testClass2() start" << endl;
	//TestA(1); // 直接调用构造函数，产生一个匿名对象，调用完成后被析构
	TestA a = TestA(1); // 先定义匿名对象，转成a对象(扶正)
	cout << "testClass2() end" << endl;
}

void main() 
{
	testClass2();

	cout << "Hello World!" << endl;
	system("pause");
}