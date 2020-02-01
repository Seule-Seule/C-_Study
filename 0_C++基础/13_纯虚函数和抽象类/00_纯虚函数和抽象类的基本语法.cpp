
#include "iostream"
using namespace std;

// 通过抽象类实现统一接口编程

class People           // 抽象类
{ 
public:
	virtual void GetWork() = 0;  // 纯虚函数
};

class Student:public People
{
public:
	virtual void GetWork()
	{
		cout << "student" << endl;
	}

};

class Doctor :public People
{
public:
	virtual void GetWork()
	{
		cout << "doctor" << endl;
	}

};

void PrintWork(People* base)
{
	base->GetWork();
}

// 抽象类不能建立对象
// 抽象类可以声明指针和引用
// 抽象类不能作为函数返回类型
// 抽象类对象不能作为函数参数， 抽象类指针可以
int main() 
{
	int ret = 0;

	// People p;

	Student s;
	Doctor d;

	PrintWork(&s);
	PrintWork(&d);

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}