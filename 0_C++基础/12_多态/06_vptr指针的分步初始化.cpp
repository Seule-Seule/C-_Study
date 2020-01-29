
#include "iostream"
using namespace std;

class TestA
{
public:
	TestA(int a = 0)
	{
		this->a = a;
		Print();
	}
	virtual void Print()
	{
		cout << " TestA " << endl;
	}
private:
	int a;
};

class TestB :public TestA
{
public:
	TestB(int a = 0, int b = 0) :TestA(a)
	{
		this->b = b;
		Print();
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

int main() 
{
	int ret = 0;
	
	TestB b;
	// 分步初始化 b 的 vptr 指针：
	//     当执行父类构造函数的时候，b 的 vptr 指针指向父类的虚函数表
	//     父类构造函数执行完毕后，b 的 vptr 指针指向子类的虚函数表
	// 结论：构造函数中调用虚函数，只会执行本类虚函数表中函数

	
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}