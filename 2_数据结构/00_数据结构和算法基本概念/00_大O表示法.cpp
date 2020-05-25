#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sum1(int n) // n+2 ====> O(n)
{
	int ret = 0; //1
	int i = 0;//1
	for (i = 0; i <= n; i++)//n
	{
		ret = ret + i;
	}

	return ret;
}

int sum2(int n)//2 ====> O(1)
{
	int ret = 0;//1

	if (n > 0)
	{
		ret = (n + 1) * n / 2;//1
	}
	return ret;
}

int main()
{
	int	ErroMsg = 0;
	

	printf("%d\n",sum1(1000));
	printf("%d\n",sum2(1000));
	system("pause");
	return ErroMsg;
}