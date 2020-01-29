
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

class TestB
{
public:
	TestB(int a = 0)
	{
		this->a = a;
	}
	void Print()
	{
		cout << " TestA " << endl;
	}
private:
	int a;
};

int main() 
{
	int ret = 0;

	printf("sizeof(TestA):%d  sizeof(TestB):%d\n", sizeof(TestA), sizeof(TestB));
	
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}