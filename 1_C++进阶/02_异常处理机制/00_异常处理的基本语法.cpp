
#include "iostream"
using namespace std;

// 1 异常的基本语法
// 2 异常跨函数
// 3 接收异常之后可以不处理， 继续向上抛出
void divVoid(int x, int y)
{
	if (0 == y)
	{
		throw x;  // 抛出 int 类型异常
	}
	cout << "Result: " << x / y << endl;
}

void divTest()
{
	// divVoid(10, 0);  // 异常跨函数
	try
	{
		divVoid(10, 0);  // 接收异常不处理，继续上抛
	}
	catch (int e)
	{
		cout << "接收异常不处理，继续上抛" << endl;
		throw;
	}
	catch (...)
	{
	}

}

int main() 
{
	int ret = 0;

	// divVoid(10, 0);  // 未接收异常并处理 ERROR
	try
	{
		divVoid(10, 2);
		//divVoid(10, 0);   // 接收异常并处理

		divTest();
	}
	catch (int e)
	{
		cout << e << " 不能被 0 除！！";
	}
	catch (...)
	{

	}
	

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}