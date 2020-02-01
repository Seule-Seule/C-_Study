
#include "iostream"
using namespace std;

class Interface1
{
public:
	virtual int add(int a, int b) = 0;
	virtual void print() = 0;
};

class Interface2
{
public:
	virtual int add(int a, int b) = 0;
	virtual void print() = 0;
	virtual int GetAge() = 0;
};

class People
{
public:
	People(int age)
	{
		this->age = age;
	}
public:
	int age;
};

class Student:public People , public Interface1, public Interface2
{
public:
	Student(int age):People(age)
	{

	}
	virtual int add(int a, int b)
	{
		cout << "Student::add() " << endl;
		return a + b;
	}
	virtual void print()
	{
		cout << "Student::print() " << endl;
	}
	virtual int GetAge()
	{
		cout << "Student::GetAge() " << endl;
		return this->age;
	}
};


// 抽象类中的纯虚函数多继承不具有二义性， 通常用来模拟接口编程
int main() 
{
	int ret = 0;

	Student s(23);

	Interface1* i1;
	Interface2* i2;

	i1 = &s;
	i2 = &s;

	i1->add(2, 3);
	i2->add(3, 4);

	i1->print();
	i2->print();

	cout << i2->GetAge() << endl;

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}