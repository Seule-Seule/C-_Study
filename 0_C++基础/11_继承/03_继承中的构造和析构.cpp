
#include "iostream"
using namespace std;

class People
{
public:
	People(int a,int b)
	{
		this->a = a;
		this->b = b;
		cout << "People 构造函数" << a << b << endl;
	}
	~People()
	{
		cout << "People 析构函数" << a << b << endl;
	}
private:
	int a;
	int b;
};

class Yong:public People
{
public:
	Yong(const char* p):People(1,2)
	{
		this->p = p;
		cout << "Yong 构造函数" << p << endl;
	}
	~Yong()
	{
		cout << "Yong 析构函数" << p << endl;
	}
protected:
	int age;
	const char* p;
};


class Student:public Yong
{
public:
	Student(const char *p,int studyAge):Yong(p),people1(3,4), people2(5, 6)
	{
		this->studyAge = studyAge;
		cout << "Student 构造函数" << studyAge << endl;
	}

	~Student()
	{
		cout << "Student 析构函数" << p << endl;
	}
public:
	int studyAge;
	People people1;
	People people2;
};

void testClassStudent()
{
	const char* p = "ssss";
	Student(p, 0);
}

// -先调用继承的构造函数、后调用组合的构造函数、最后调用自己的构造函数
// - 调用继承构造函数的时候，按继承顺序，从父类调用到子类
// - 调用组合构造函数时，按组合类在本类中的定义顺序调用
// - 析构函数与构造函数的调用顺序相反

int main() 
{
	int ret = 0;
	testClassStudent();
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}