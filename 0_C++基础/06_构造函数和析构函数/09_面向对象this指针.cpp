#include "iostream"

using namespace std;

class Test
{
public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void PrintTest()
	{
		cout << "a:" << a << "\tb:" << b << endl;
	}


	// 此处 const 与位置无关 const void ConstPrint(int a, int b);void const ConstPrint(int a, int b);  
	// const 修饰谁？？
	// const 修饰this指针 //void ConstPrint(const Test* const thisint a, int b)
 // 未加const时函数原型：// void ConstPrint(const Test* const thisint a, int b)
	// this 指针所指的内存空间不能被修改
	void ConstPrint(int a, int b) const
	{
		a = a + 100;
		b = b + 20;
		cout << "a:" << a << "\tb:" << endl;
	}
protected:
private:
	int a;
	int b;
};


void main() 
{
	Test t1(1, 2);
	t1.PrintTest();

	cout << "Hello World!" << endl;
	system("pause");
}