
#include "iostream"
using namespace std;

// 需求:实现 int 和 char 类型的数据交换函数

void intSwap(int &a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void charSwap(char& a, char& b)
{
	char c = a;
	a = b;
	b = c;
}

// 两函数功能相似， 参数类型不同重载？？
// 泛型编程， 定义参数类型不同(不确定)的函数

//  函数模板本质:类型参数化

template <typename T>
void Swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

int main() 
{
	int ret = 0;

	// 一般函数
	{
		int a = 100; 
		int b = 200;
		cout << "a: " << a << "  b: " << b << endl;
		intSwap(a, b);
		cout << "a: " << a << "  b: " << b << endl;
	}
	{
		char x = 'x';
		char y = 'y';
		cout << "x: " << x << "  y: " << y << endl;
		charSwap(x, y);
		cout << "x: " << x << "  y: " << y << endl;
	}

	// 函数模板调用
	//   显示类型转换
	//   隐式类型转换
	{
		int a = 100;
		int b = 200;
		cout << "a: " << a << "  b: " << b << endl;

		Swap<int>(a, b);		//   显示类型转换
		cout << "a: " << a << "  b: " << b << endl;

		Swap(a, b);				//   隐式类型转换
		cout << "a: " << a << "  b: " << b << endl;
	}
	{
		char x = 'x';
		char y = 'y';
		cout << "x: " << x << "  y: " << y << endl;

		Swap<char>(x, y);		//   显示类型转换
		cout << "x: " << x << "  y: " << y << endl;

		Swap(x, y);				//   隐式类型转换
		cout << "x: " << x << "  y: " << y << endl;
	}

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}