#include "iostream"

using namespace std;

class A
{
public:
	int a;
	int b;
	int c;
protected:
private:
};
class B
{
public:
	int a;
	int b;
	int c;
	static int d;
	void setA(int _a)
	{
		a = _a;
	}
	int  getA()
	{
		return a;
	}
protected:
private:
};

struct C
{
	int a;
	int b;
	int c;
};
struct D
{
	int a;
	int b;
	int c;
	static int d;
};

// 成员变量和成员函数分开存储
// 普通成员变量的实现和struct一致
void main() 
{
	printf("sizeof(A):%d\n", sizeof(A));//12
	printf("sizeof(B):%d\n", sizeof(B));//12
	printf("sizeof(C):%d\n", sizeof(C));//12
	printf("sizeof(D):%d\n", sizeof(D));//12


	cout << "Hello World!" << endl;
	system("pause");
}