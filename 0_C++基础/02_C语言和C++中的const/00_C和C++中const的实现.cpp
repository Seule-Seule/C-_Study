#include "iostream"

using namespace std;



// C 语言中的 const 为假常量
// 可以通过指针简介修改const变量的值
// {
// 	cosnt int a = 0;
// 	int* p = &a;
// 	*p = 10;
// }

// C++中 const 实现
// 由符号表实现，通过键值对存储，是真正的常量
// C++中 const 修饰的变量不能做左值

// 只有在对 const 取地址或者定义为全局变量时才临时分配内存，内存可修改，原变量值依旧没变 
// 临时分配内存在编译时完成，属于静态存储


void main00() 
{
	const int a = 1;
	
	int* p = (int *)&a;  // E0144	"const int *" 类型的值不能用于初始化 "int *" 类型的实体	02_C语言和C++中的const

	*p = 10;

	cout << a << endl;  // a =1;并没有被修改
	cout << "Hello World!" << endl;
	system("pause");
}

// C++中 const 也可以代替 #define 使用

// const 和 #define 的相同点

void main01() {
// 	int a = 10;
// 	int b = 20;
// 	int array1[a + b];  // C++编译器不持支，LINUX内核中支持，gcc提供支持


#define c  10
	const int d = 20;
	int array2[c + d];

}

// const 和 #define 的不同点
// const 由编译器提供处理，有变量检查和作用域
// #define 由预处理器处理，只实现文本处理功能
void fun1()
{
#define funv1 10
	const int fun1v2 = 20;
// #undef funv1
// #undef 
}
void fun2()
{
	//cout << fun1v2 << endl;
	cout << funv1 << endl;

}
void main() {
	fun1();
	fun2();
	system("pause");
}