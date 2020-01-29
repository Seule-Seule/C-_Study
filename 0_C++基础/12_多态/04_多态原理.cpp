
#include "iostream"
using namespace std;

class TestA
{
public:
	TestA(int a =0)
	{
		this->a = a;
	}
	virtual void Print()
	{
		cout << " TestA " << endl;
	}
private:
	int a;
};

class TestB:public TestA
{
public:
	TestB(int a = 0,int b = 0):TestA(a)
	{
		this->b = b;
	}
	virtual void Print()
	{
		cout << " TestB " << endl;
	}
private:
	int b;
};

void TestCLass(TestA* base)
{
	base->Print();
}

// 当类中声明虚函数的时候， C++编译器会在类中维护一个虚函数表
// 虚函数表是一个存储对应类虚函数指针的数据结构
// virtual 关键字修饰的成员函数会被放入虚函数表中
// 存在虚函数时，每一个类对象中都有一个指向虚函数表的指针(vptr指针)

int main() 
{
	int ret = 0;

	TestA a(5);
	TestB b(4,7);

	TestCLass(&a);
	TestCLass(&b);


	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}