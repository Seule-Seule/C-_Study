#include "iostream"

using namespace std;



// C语言和C++语言对表达式做左值的处理不一样
// C语言返回值，C++返回变量本身
// 本质上C++返回内存空间的地址
// C语言返回变量本身的实现：   // *(a < b ? &a : &b) = 30;


// {
// 	int		a = 10;
// 	int		b = 20;
// 	(a < b ? a : b) = 30;  // C语言会报错，表达式不能做左值，C++可以
//  // *(a < b ? &a : &b) = 30;
//
// 	cout << "a:" << a << "  b:" << b << endl;
// }

void main() 
{
	int		a = 10;
	int		b = 20;
	(a < b ? a : b) = 30;

	cout << "a:" <<a << "  b:" << b<< endl;

	cout << "Hello World!" << endl;
	system("pause");
}