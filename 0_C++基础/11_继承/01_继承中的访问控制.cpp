
#include "iostream"
using namespace std;


// 类的访问控制
// public     : 公共成员-类的内部和类的外部均可访问
// protected  : 受保护的成员-类的内部和派生类可访问
// private    : 私有成员-类的内部可访问，外部不能访问


class  People
{
public:
	int age;
protected:
	int lenght;
private:
	int high;
};

class publicStudent :public People
{
public:
	int studyAge;
protected:
	int studyLenght;
private:
	int studyHigh;
public:
	void Print()
	{
		age = 30;
		lenght = 170;
		//high = 50;
	}
};

class protectedStudent :protected People
{
public:
	int studyAge;
protected:
	int studyLenght;
private:
	int studyHigh;
public:
	void Print()
	{
		age = 30;
		lenght = 170;
		//high = 50;
	}
};

class privateStudent :private People
{
public:
	int studyAge;
protected:
	int studyLenght;
private:
	int studyHigh;
public:
	void Print()
	{
		age = 30;
		lenght = 170;
		//high = 50;
	}
};
/*
-------------------public-----protected----private---
-----public--------public-----protected----private---
-----protected-----protected--protected----private---
-----private-------private----private------private---
*/
int main() 
{
	int ret = 0;

	// publicStudent
	publicStudent publicStudent1;
	publicStudent1.age = 20;
	//publicStudent1.lenght = 10;
	//publicStudent1.high = 20;


	protectedStudent protectedStudent1;
	//protectedStudent1.age = 20;
	//protectedStudent1.lenght = 20;
	//protectedStudent1.high = 20;

	protectedStudent protectedStudent1;
	//protectedStudent1.age = 20;
	//protectedStudent1.lenght = 20;
	//protectedStudent1.high = 20;


	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}