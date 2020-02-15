
#include "iostream"
using namespace std;

//传统异常处理
int myStrcpy0(char* to, char* from)
{
	if (NULL == to)
	{
		return 1;
	}
	if (NULL == from)
	{
		return 2;
	}
	while (*from++ = *to++);
	return 0;
}

int main00() 
{
	int ret = 0;
	char bufTo[] = "abcdefgh";
	char bufFrom[1024] = { 0 };
	ret = myStrcpy0(bufTo, bufFrom);
	if (0 != ret)
	{
		switch (ret)
		{
		case 1:
			cout << "源地址出错！" << endl;
			break;
		case 2:
			cout << "目的地址出错！" << endl;
			break;
		default:
			cout << "未知类型错误！" << endl;
			break;
		}
	}
	cout << "bufFrom : " << bufFrom << endl;

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}

// C++异常处理机制 int 、const char * 
void myStrcpy1(char* to, char* from)
{
	if (NULL == to)
	{
		throw 1;
	}
	if (NULL == from)
	{
		throw "目的地址错误！";
	}
	while (*from++ = *to++);
}

int main01()
{
	int ret = 0;
	char bufTo[] = "abcdefgh";
	char bufFrom[1024] = { 0 };
	try
	{
		// myStrcpy1(NULL, bufFrom); // int类型异常
		myStrcpy1(bufTo, NULL);  // const char* 类型异常
	}
	catch (int e)
	{
		cout << "int 类型异常出错！" << e << endl;
	}
	catch (const char* e)
	{
		cout << "const char* 类型异常出错！" << e << endl;
	}
	catch (...)
	{
		cout << "未知类型错误！" << endl;
	}
	
	cout << "bufFrom : " << bufFrom << endl;

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}

// C++异常处理机制 类对象异常
class ErrorTest
{
public:
	ErrorTest()
	{
		cout << "构造函数！" << endl;
	}
	ErrorTest(const ErrorTest& ET)
	{
		cout << "拷贝构造函数！" << endl;
	}
	~ErrorTest()
	{
		cout << "析构函数！" << endl;
	}
};

void myStrcpy2(char* to, char* from)
{
	if (NULL == to)
	{
		throw 1;
	}
	if (NULL == from)
	{
		cout << "引发异常" << endl;
		// throw ErrorTest();// 捕捉变量|引用 注意特殊写法  // 创建匿名对象
		// throw &(ErrorTest()); // 捕捉指针异常变量  返回时析构，返回野指针
		throw new ErrorTest;  // 捕捉指针异常变量  放到堆上
	}
	while (*from++ = *to++);
}

int main()
{
	int ret = 0;
	char bufTo[] = "abcdefgh";
	char bufFrom[1024] = { 0 };
	try
	{
		myStrcpy2(bufTo, NULL);  // 类对象异常
	}
	catch (int e)
	{
		cout << "int 类型异常出错！" << e << endl;
	}
	// 1 利用匿名对象拷贝构造异常变量
	/*catch (ErrorTest e)
	{
		cout << "ErrorTest 类型异常出错！" << endl;
	}*/
	// 2 引用异常变量会使用 throw 的匿名对象
	catch (ErrorTest& e)
	{
		cout << "ErrorTest& 类型异常出错！" << endl;
	}
	// 指针异常变量的捕捉与变量或者引用可以同时存在， 引用个变量不能同时存在
	// 3 为避免野指针， 异常变量放在堆上
	catch (ErrorTest* e)  
	{
		cout << "ErrorTest* 类型异常出错！" << endl;
		delete e;  // 释放空间， 避免内存泄漏
	}

	catch (...)
	{
		cout << "未知类型错误！" << endl;
	}

	cout << "bufFrom : " << bufFrom << endl;

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}
