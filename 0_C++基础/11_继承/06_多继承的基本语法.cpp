
#include "iostream"
using namespace std;

class Test1
{
public:
	Test1(int t)
	{
		this->t1 = t;
	}
public:
	void PrintT1()
	{
		cout << " t1; " << t1 << endl;
	}
private:
	int t1;
};


class Test2
{
public:
	Test2(int t)
	{
		this->t2 = t;
	}
public:
	void PrintT2()
	{
		cout << " t1; " << t2 << endl;
	}
private:
	int t2;
};


class Test:public Test1, public Test2
{
public:
	Test(int t1, int t2, int t3):Test1(t1),Test2(t2)
	{
		this->t3 = t3;
	}
public:
	void PrintT3()
	{
		cout << " t1; " << t3 << endl;
	}
private:
	int t3;
};
int main() 
{
	int ret = 0;

	Test t1(1, 2, 3);
	t1.PrintT1();
	t1.PrintT2();
	t1.PrintT3();
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}