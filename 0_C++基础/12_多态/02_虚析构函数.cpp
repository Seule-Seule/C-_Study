
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

class TestA
{
public:
	TestA()
	{
		p = new char[20];
		strcpy(p, "a a a a a");
	}
	virtual ~TestA()
	{
		delete[]p;
	}
private:
	char* p;
};

class TestB:public TestA
{
public:
	TestB()
	{
		p = new char[20];
		strcpy(p, "a a a a a");
	}
	virtual ~TestB()
	{
		delete[]p;
	}
private:
	char* p;
};

class TestC:public TestB
{
public:
	TestC()
	{
		p = new char[20];
		strcpy(p, "a a a a a");
	}
	virtual ~TestC()
	{
		delete[]p;
	}
private:
	char* p;
};

void Test(TestA* base)
{
	delete base;
}


// 不使用 virtual 调用父类释放函数，只释放父类资源
// 使用 virtual 调用父类释放函数，使父类指针释放所有子类资源

int main()
{
	int ret = 0;

	TestC* pc1 = new TestC;
	
	Test(pc1);      
	//delete pc1;  // 直接释放，依次调用所有父类析构函数释放资源
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}