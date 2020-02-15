
#include "iostream"
using namespace std;

class Test
{
public:
	Test(int a)
	{
		this->a = a;
		cout << "\t构造函数" << endl;
	}
	~Test()
	{
		cout << "\t析构函数" << endl;
	}
protected:
private:
	int a;
};

void voidTest()
{
	Test t1(1), t2(2), t3(3);
	cout << "发生异常" << endl;
	throw 2;
}

void voidTest2()
{
	Test t1(1), t2(2), t3(3);
	voidTest();
}

// 异常接口声明
// 不写，可以抛出任何类型异常
void voidTest3()
{
	Test t1(1), t2(2), t3(3);
	cout << "发生异常" << endl;
	throw 2;
}

// 写了， 只能抛出列表异常
void voidTest4() throw(int , char , char *)
{
	Test t1(1), t2(2), t3(3);
	cout << "发生异常" << endl;
	throw 2;
}

// 异常列表为空， 不抛出任何类型异常
void voidTest5() throw()
{
	Test t1(1), t2(2), t3(3);
	cout << "发生异常" << endl;
	throw 2;
}


// 栈解旋
//   从进入try语句到发生异常的语句之前所有栈变量都将被析构，析构顺序与构造顺序相反
int main() 
{
	int ret = 0;
	try
	{
		voidTest2();
	}
	catch (int e)
	{
		cout << "捕获异常： " << e << endl;
	}
	catch (...)
	{
		cout << "未知异常： " << endl;
	}

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}