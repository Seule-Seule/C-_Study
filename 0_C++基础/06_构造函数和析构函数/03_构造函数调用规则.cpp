#include "iostream"

using namespace std;

class  Test
{
public:
// 	Test(int a, int b)
// 	{
// 		;
// 	}
	Test(const Test& t)
	{
		;
	}
public:
	void Print()
	{
		cout << "a: " << a << "  b: " << b << endl;
	}
	int getA() { return a; }; int getB() { return b; }
private:
	int a;
	int b;
};

// 在定义类时，C++编译器自动提供无参构造函数和无参析构函数
// 若定义有参构造函数，则C++编译器不提供无参构造函数
// 若定义赋值(复制|copy),则C++编译器不提供无参构造函数

// ！！！只要自定义构造函数，就必须使用，C++编译器不在提供默认构造函数
void main() 
{
	Test t1; // 调用无参构造函数

	cout << "Hello World!" << endl;
	system("pause");
}