
#include "iostream"
using namespace std;

// 类模板
template <typename Type>
class Test
{
public:
	Test(Type a)
	{
		this->a = a;
	}
	void PrintA()
	{
		cout << " a: " << a << endl;
	}
public:
	Type a;
};


// 派生普通类
// 需要模板类具体化，子类必须知道为父类分配多大内存空间
class TestB : public Test<int>
{
public:
	TestB(int a, int b) : Test <int>(a)
	{
		this->b = b;
	}
	void Print()
	{
		cout << "a: " << a << "  b: " << b << endl;
	}
protected:
	int b;
};

// 派生模板类
// 需要模板类具体化，子类必须知道为父类分配多大内存空间
template <typename Tc>
class TestC : public Test<Tc>
{
public:
	TestC(Tc a, Tc c) : Test <Tc>(a)
	{
		this->c = c;
	}
	void Print()
	{
		cout << "c: " << c << endl;
	}
protected:
	Tc c;
};


int main()
{
	int ret = 0;

	TestB b(1, 2);
	b.Print();


	TestC <int>c(2, 3);
	c.PrintA();
	c.Print();
	
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}