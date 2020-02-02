#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Print(int a)
{
	printf("a: %d\n", a);
	return a;
}

int Print2(int a)
{
	printf("a2: %d\n", a+2);
	return a+2; 
}

int Print3(int a)
{
	printf("a3: %d\n", a+3);
	return a+3;
}

int Print4(int a)
{
	printf("a4: %d\n", a+4);
	return a+4;
}

// typedef int (*pVoidClass)(int a);
void PrintMain(int (*pVoidClass)(int a))
{
	pVoidClass(2);
}

int main()
{
	int	ErroMsg = 0;
	
	PrintMain(Print);
	PrintMain(Print2);
	PrintMain(Print3);
	PrintMain(Print4);

	system("pause");
	return ErroMsg;
}