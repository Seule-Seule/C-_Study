
#include "iostream"
using namespace std;



//..........Test1.........
//........./.....\........
//......Tset3...Test2.....
//.........\..../.........
//...........Test.........


//virtual 虚继承


class Test1
{
public:
	int b;
};

class Test2:virtual public Test1
{
public:
	int b2;
};


class Test3:virtual public Test1
{
public:
	int b3;
};

class Test :public Test2, public Test3
{
public:
	int bt;
};



int main() 
{
	int ret = 0;

	Test t1;
	t1.b2 = 2; 
	t1.b3 = 3;
	t1.bt = 4; 

	t1.b = 10; // 未加 virtual 时访问不明确

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}