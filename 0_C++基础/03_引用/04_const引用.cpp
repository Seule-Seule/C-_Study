#include "iostream"

using namespace std;

// 常引用有两种类型
//   const 修饰变量引用
//   const 修饰常量（字面量）引用

void main() 
{
	//   const 修饰变量引用
	int a = 10;
	const int& b = a; // 给变量设置只读属性
	a = 20;
	// b = 30; //ERRO 变量只读

	//   const 修饰常量（字面量）引用
	// int& c = 50; // 常量（字面量）没有显式的分配内存，不能定义引用
	const int& c = 50; // C++ 分配内存了

	cout << "Hello World!" << endl;
	system("pause");
}