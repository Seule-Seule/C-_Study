
#include "iostream"
using namespace std;

class TestA
{
public:
	TestA(int a = 0)
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

class TestB :public TestA
{
public:
	TestB(int a = 0, int b = 0) :TestA(a)
	{
	//	this->b = b;
	}
	virtual void Print()
	{
		cout << " TestB " << endl;
	}
private:
	int b;
};


int main() 
{
	int ret = 0;

	TestB barray[] = { TestB(1,2), TestB(3,4), TestB(5,6) };

	TestA* pA;
	TestB* pB;

	pA = barray;
	pB = barray;

	pA->Print();
	pB->Print();

	// 指针的步长与指针的类型有关
	// 当子类与父类所占内存空间大小不一样的时候，两种指针步长大小不一样
	pA++;
	pB++;
	pA->Print();
	pB->Print();

	pA++;
	pB++;
	pA->Print();
	pB->Print();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}