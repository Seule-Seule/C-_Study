
#include "iostream"
using namespace std;

class TestParent
{
public:
	virtual int Soul()
	{
		return 10;
	}
};

class TestChild
{
public:
	int Soul()
	{
		return 15;
	}
};


class TestParent2:public TestParent
{
public:
	virtual int Soul()
	{
		return 20;
	}
};

// 封装：突破C语言函数的概念，类的对象可以使用类的属性和方法
// 继承：a<-b, b可以使用a的代码，代码复用原则
// 多态：为未来的代码编写框架，写给未来的

void SoulChallenge(TestParent &p, TestChild &c)
{
	if (p.Soul() < c.Soul())
	{
		cout << "Parent is old!" << endl;
	}
	else
	{
		cout << "Child is fail!" << endl;
	}
}
// 实现多态的条件
// 要有继承
// 虚函数重写
// 用父类指针(父类引用)指向子类

 
// 不写 virtual 是静态联编，C++在编译的时候根据定义的类调用函数
// 写 virtual 是动态联编：迟绑定(C++根据不同的对象选择函数执行)
int main() 
{
	int ret = 0;

	TestParent p1;
	TestChild  c1;
	SoulChallenge(p1, c1);

	TestParent2 p2;
	SoulChallenge(p2, c1);

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}