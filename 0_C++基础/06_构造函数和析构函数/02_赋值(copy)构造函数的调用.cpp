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
		a = t.a + 10;
		b = t.b + 10;
	}

	~Test()
	{
		cout << "析构函数" << endl;
	}
public:
	void Print()
	{
		cout << "a: " << a << "  b: " << b << endl;
	}
	int getA() { return a; }; int getB() { return b; }
private:
	int a;
	int b;
};


// 赋值(copy)构造函数的调用

void main00() 
{
	Test t1(1, 2);
	t1.Print();
	Test t2; 

	t2 = t1; // 赋值操作，不是初始化操作，不调用构造函数 
	t2.Print();
	
	// 赋值(copy)构造函数的调用 方法1
	Test t3 = t1;
	t3.Print();

    //  赋值(copy)构造函数的调用 方法2
	Test t4(t1);
	t4.Print();
	
	cout << "Hello World!" << endl;
	system("pause");
}

void copyInit3(Test tmp)
{
	cout << "tmp.getA():" << tmp.getA() << endl;
}

void testClassTest()
{
	Test t1(1, 2);
	Test t2(t1);

	copyInit3(t2);  // 使用实参t2初始化形参tmp，调用构造函数  方法3
}

void main01() 
{
	testClassTest();
	system("pause");
}


// 返回类对象时， C++会提前创建一个匿名对象作为返回值,调用构造函数
Test copyInit4()
{
	Test tmp(1, 2);
	return tmp;
}

void testClassTest2()
{
	Test t1(1,2);
	t1 = copyInit4();  // 用匿名对象赋值时，析构匿名对象，将值给被赋值对象

	Test t2 = copyInit4();  // 用匿名对象初始化时，直接将匿名对象名字改为新对象(扶正)
}

void main()
{
	testClassTest2();
	system("pause");
}