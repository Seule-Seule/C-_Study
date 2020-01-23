
#include "iostream"
using namespace std;

class Test1
{
public:
	int a;
	int b;
	static int d;
	void Print()
	{
		cout << "Test1" << b << endl;
	}
};

int Test1::d = 20;   /// !!!!分配内存，如果不写，编译不报做，使用的时候报错
class Tset2 :public Test1
{
public:
	int b;
	int c;
	void Print()
	{
		cout << "Test2" << b << endl;
	}
};

int main() 
{
	int ret = 0;
	Tset2 t2;
	t2.Print();
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}