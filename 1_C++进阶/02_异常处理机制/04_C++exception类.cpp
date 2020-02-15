
#include "iostream"
using namespace std;
#include "exception"

// 使用C++ 异常类
class TestA
{
public:
	TestA(int a)
	{
		if (a > 1000)
		{
			throw out_of_range("大于1000");
		}
	}
private:
	int a;
};

// 继承并使用C++异常类
class TestB : public exception
{
public:
	TestB(const char* p)
	{
	 	this->p = p;
	}
	_NODISCARD virtual char const* what() const
	{
		return p;
	}
private:
	const char* p;
};
void testTestB()
{
	throw TestB("异常");
}
int main() 
{
	int ret = 0;

	try
	{
		// TestA a(1001);
		TestA a(100);
	}
	catch (out_of_range & e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}

	try
	{
		testTestB();
	}
	catch (TestB e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}