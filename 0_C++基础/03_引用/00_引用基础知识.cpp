#include "iostream"

using namespace std;

// 引用： 已定义变量的别名
// 语法：  TYPE& name = var;



void main00() 
{
	int		a = 10;
	int&	b = a;
	// int& c; // ERRO 普通引用必须初始化
	b = 20;

	cout << a << endl;
	cout << "Hello World!" << endl;
	system("pause");
}

// 引用做函数参数不用初始化
void IntSwap0(int a, int b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}
void IntSwap1(int *a,int *b)
{
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

void IntSwap2(int& a, int& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void main01()
{
	int a = 10;
	int b = 20;

	IntSwap0(a, b);
	cout <<"a:"<< a << "  b:" << b<<  endl;

	IntSwap1(&a, &b);
	cout << "a:" << a << "  b:" << b << endl;

	IntSwap2(a, b);
	cout << "a:" << a << "  b:" << b << endl;

	cout << "Hello World!" << endl;
	system("pause");
}

// 对复杂数据类型的引用

struct stud
{
	int age;
	int name[20];
};

void PrintStud0(stud* s)
{
	printf("PrintStud0(stud* s) s.age:%d\n", s->age);
	s->age = 21;   //指针间接修改
}

void PrintStud1(stud s)
{
	printf("rintStud1(stud s) s.age:%d\n", s.age);
	s.age = 22;   // ERRO，修改形参，无效修改
}

void PrintStud2(stud &s)
{
	printf("PrintStud2(stud &s) s.age:%d\n", s.age);
	s.age = 23;   // 通过引用修改参数，有效操作
}


void main()
{
	stud s1;
	s1.age = 20;

	PrintStud0(&s1);
	printf("PrintStud0(&s1); s1.age:%d\n", s1.age);

	PrintStud1(s1);
	printf("PrintStud1(s1); s1.age:%d\n", s1.age);

	PrintStud2(s1);
	printf("PrintStud2(s1); s1.age:%d\n", s1.age);
	
	system("pause");

}