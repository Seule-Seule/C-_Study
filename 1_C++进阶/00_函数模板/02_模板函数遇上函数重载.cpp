
#include "iostream"
using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

void Swap(int a, char b)
{
	cout << "a: " << a << "  b: " << b << endl;
}


int main00() 
{
	int		ret = 0;
	int		a = 20;
	char	b = 'b';

	Swap(a, b);  // 普通函数类型检查相对宽松，可以进行隐式类型转换

	Swap(b, a);

	Swap(a, a);  // 模板函数有极其严格的类型检查,不允许自动类型转换

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}

int Max(int a, int b)
{
	cout << "a: " << a << "  b: " << b << "  Max: ";
	return (a > b) ? a : b;
}

template <typename T>
T Max(T a, T b)
{
	cout << "a: " << a << "  b: " << b << "  Max: ";
	return (a > b) ? a : b;
}

template <typename T>
T Max(T a, T b,T c)
{
	cout << "a: " << a << "  b: " << b << "  c: " << c << "  Max: ";
	T d =  (a > b) ? a : b;
	return (d > c) ? d : c;
}


// 模板函数可以像普通函数一样被重载
// C++编译器优先考虑普通函数
// 如果模板函数可以产生一个更好的匹配，则选择模板函数
// 可以通过空模板实参列表的语法限制编译器选择模板函数匹配

int main()
{
	int		ret = 0;
	int		a = 20;
	int		b = 10;
	int		c = 0;

	cout << Max(a, b) << endl;			// C++编译器优先考虑普通函数
	cout << Max<>(a, b) << endl;		// 可以通过空模板实参列表的语法限制编译器选择模板函数匹配

	cout << Max(3.0, 4.0) << endl;		// 如果模板函数可以产生一个更好的匹配，则选择模板函数

	cout << Max(a, b, c) << endl;		// 模板函数可以像普通函数一样被重载

	cout << Max('a', b) << endl;		

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}
