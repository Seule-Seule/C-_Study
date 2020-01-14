#include "iostream"

using namespace std;


// 函数的默认参数
// 函数的默认参数可以不传递，不传递则使用默认值
// 默认参数必须放在非默认参数后面
void PrintInt0(int x, int y = 5)
{
	cout << "x:" << x << "  y:" << y << endl;
}



// 函数占位参数
// 必须传递占位参数
void PrintInt1(int a, int b, int)
{
	cout << "a:" << a << "  b:" << b << endl;
 }

// 默认参数和占位参数
// 为以后业务开发留下线索？？
void PrintInt2(int a, int b, int = 0)
{
	cout << "a:" << a << "  b:" << b << endl;
}
void main() 
{
	PrintInt0(5);

	PrintInt1(1, 2, 3);

	PrintInt2(1, 2);
	PrintInt2(1, 2, 3);
	cout << "Hello World!" << endl;
	system("pause");
}