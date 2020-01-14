#include "iostream"

using namespace std;


// 函数重载
// 函数名相同，参数不一样（类型和个数均不一样）
// 函数返回值的异同不能作为函数重载的判断依据
void  Print(int a)
{
	cout << "a:" << a << endl;
}
void  Print(const char a[])
{
	cout << "a:" << a<< endl;
}

void  Print(int a,int b,int c, int d)
{
	cout << "a:" << a << "  "<<"b:" << b << endl;
}

// 重载函数的调用
// 重载函数本质上是相互独立的不同函数（静态链编）
void main00() 
{
	Print(1);

	Print("aaaasss");

	Print(1, 2,3,4);

	cout << "Hello World!" << endl;
	system("pause");
}

// 当重载遇上默认函数
void Print(int a, int b, int c = 0)
{
	cout << "a:" << a << "  " << "b:" << b << "  c:" << c << endl;
}

void Print(int a, int b)
{
	cout << "a:" << a << "  " << "b:" << b << endl;
}

void main01()
{
	// Print(1, 2); //ERRO 重载函数匹配不明确

	cout << "Hello World!" << endl;
	system("pause");
}

// 函数重载遇上函数指针


// 函数指针
// 声明一个函数类型
// void Print(int a, int b)
typedef void (CPrint)(int a, int b);
// CPrint* pVoid = NULL;

// 声明一个函数指针类型
typedef void (*pCPrint)(int a, int b);
// pCPrint pVoid2 = NULL;

// 定义一个函数指针变量
CPrint* pVoid = NULL;
pCPrint pVoid2 = NULL;

void main() 
{
	pVoid = Print;
	pVoid(12, 23);

	pVoid2 = Print;
	pVoid2(12, 23);

	cout << "Hello World!" << endl;
	system("pause");
}