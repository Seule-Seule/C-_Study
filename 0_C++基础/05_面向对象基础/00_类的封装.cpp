#include "iostream"

using namespace std;

// 类的封装
// --> 对成员函数和成员属性进行封装
// --> 对成员函数和成员属性进行访问控制

class MyCricle
{
	double m_d;  // class 默认定义的属性是private: 在类外部不可见
public:
	double m_r;
	double m_s;

public:
	void setR(double r)
	{
		m_r = r;
	}
	double getS()
	{
		m_s = 3.14 * m_r * m_r;
		return m_s;
	}
};

void PrintC(MyCricle* pC)
{
	cout << "pC ：S" << pC->getS() << endl;
}

void PrintC1(MyCricle& c)
{
	cout << "C : S" << c.getS() << endl;
}

void main00() 
{
	MyCricle c1;
	c1.setR(10);
	cout << "c1 : s" << c1.getS() << endl;

	c1.setR(11);
	PrintC(&c1);

	c1.setR(22);
	PrintC1(c1);

	// c1.m_d = 20;   // ERRO默认定义，不可访问

	cout << "Hello World!" << endl;
	system("pause");
 }

// 类对成员属性和成员变量的访问控制
// public: 可以在类的内部和外部访问
// private: 只能在类的内部访问，不能在类的外部访问


class MyCricle1
{
private:
	double m_r;
	double m_s;

public:
	void setR(double r)
	{
		m_r = r;
	}
	double getS()
	{
		m_s = 3.14 * m_r * m_r;
		return m_s;
	}
};

void main01()
{
	MyCricle1 c1;
	// c1.m_r = 10; // ERRO 不能在外部访问private:修饰的成员变量或成员函数
	c1.setR(20);

	cout << "c1 : S" << c1.getS() << endl;

	system("pause");
}

struct stud
{
	int age;
	const char *name;
public:
	int len;
private:
	int wight;
};

void main()
{
	stud s1;
	s1.age = 20;           // 默认属性为 public 外部可访问
	s1.len = 175;
	//s1.wight = 60;  // ERRO 不能访问

}