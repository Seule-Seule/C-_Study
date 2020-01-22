
#include "iostream"
using namespace std;

class People
{
public:
	int age;
protected:
private:
};


class Student :public People
{
public:
	int atudyAge;
protected:
private:
};

void Print(People* p)
{
	cout << p->age << endl;
}

void Print2(People& p)
{
	cout << p.age << endl;
}

int main() 
{
	int ret = 0;

	People p1;
	Student s1;

	// 赋值兼容
	// 基类指针赋值子类对象
	Print(&p1);
	Print(&s1);
	
	// 基类引用赋值子类对象
	Print2(p1);
	Print2(s1);

	// 基类对象赋值给子类？？
	Student* ps2;
	//ps2 = &p1;  // ERRO 不行

	// 子类对象copy构造基类对象
	People p2 = s1;
	p2.age = 20;

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}