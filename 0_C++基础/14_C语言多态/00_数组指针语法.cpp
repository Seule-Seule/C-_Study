#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 数组指针语法

//   定义一个数组类
//   定义一个数组指针类
//   定义一个数组指针

int main()
{
	int	ErroMsg = 0;
	
	int a[10];  //  定义一个数组 a 是数组首元素地址(步长4)， &a 是数组地址(步长40)

	{
		//   定义一个数组类
		typedef int(myTypeArray)[10];   
		myTypeArray myArray;
		myArray[0] = 100;
		printf("myArray[0]: %d\n", myArray[0]);
	}

	{
		//   定义一个数组指针类
		typedef int (*pArray)[10];
		pArray myPArray = &a;
		(*myPArray)[0] = 200;
		printf("a[0]: %d\n", a[0]);
	}

	{
		//   定义一个数组指针
		int (*p)[10];
		p = &a;
		(*p)[0] = 300;
		printf("a[0]: %d\n", a[0]);
	}
	system("pause");
	return ErroMsg;
}