
#include "iostream"
using namespace std;

class Test1
{
public:
	int a;
	int b;
	void Print()
	{
		cout << "Test1" << b << endl;
	}
};

class Tset2:public Test1
{
public:
	int b;
	int c;
	void Print()
	{
		cout << "Test2" << b << endl;
	}
};
int main() 
{
	int ret = 0;

	Tset2 t1;

	t1.b = 2;      // 默认使用子类属性
	t1.Print();    // 默认使用子类方法
	t1.Test1::Print();   // 域名限制使用方法

	t1.Test1::b = 20;   // 域名限制使用属性
	t1.Print();    // 默认使用子类方法
	t1.Test1::Print();   

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}