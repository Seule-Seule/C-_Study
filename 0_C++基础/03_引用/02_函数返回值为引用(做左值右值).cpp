#include "iostream"

using namespace std;


// 引用做右值
// 临时堆栈变量不能使用函数返回引用初始化引用
// 静态变量或全局变量可以使用函数返回引用初始化引用(既可以做左值也可以做右值)

int GetVar0()
{
	int a = 10;
	return a;
}

int* Getvar1()
{
	int a = 100;
	return &a;
}

int& Getvar2()
{
	int a = 200;
	return a;
}

int& GetVar3()
{
	static int a = 300;
	a++;
	return a;
}

void main00()
{
	
	int a1 = GetVar0();

	int* a2 = Getvar1(); //ERRO 返回临时变量

	int a3 = Getvar2();  // 完成变量值拷贝

	int& a4 = Getvar2();  // 临时堆栈变量不能使用函数返回引用初始化引用

	int a5 = GetVar3(); 

	int a6 = GetVar3(); //   静态变量或全局变量可以使用函数返回引用初始化引用
	printf("a1:%d\t*a2:%d\ta3:%d\ta4:%d\ta5:%d\ta6:%d\t",a1,*a2,a3,a4,a5,a6);
	cout << "Hello World!" << endl;
	system("pause");
}


// 引用做右值
int RetVar0() // 返回a的值
{
	int b = 100;
	return b;
}
int& RetVar1() // 返回a本身--可以做左值,必须是静态变量或者全局变量
{
	static int b = 100;
	printf("%d\n", b);
	return b;
}

void  main()
{
	// RetVar0() = 100; // ERROR -> 常量不能做左值

	RetVar1() = 200;

	RetVar1();
	cout << "Hello World!" << endl;
	system("pause");

}