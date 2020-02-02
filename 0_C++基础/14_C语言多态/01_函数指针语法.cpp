#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 函数指针语法梳理
//     定义一个函数类型
//     定义一个函数指针类型
//     定义一个指向函数的指针

int Print(int a)
{
	printf("a: %d\n", a);
	return a;
}

int main()
{
	int	ErroMsg = 0;
	// 定义一个函数类型
	{
		typedef int (VoidClass)(int a);
		VoidClass* pVoidClass;
		pVoidClass = &Print;
		pVoidClass(4);
	}
	// 定义一个函数指针类型
	{
		typedef int (*pVoid)(int a);
		pVoid voidPointer;
		voidPointer = &Print;
		voidPointer(5);
	}
	// 定义一个指向函数的指针
	{
		int (*pPrint)(int a);
		pPrint = &Print;
		pPrint(7);
	}

	system("pause");
	return ErroMsg;
}