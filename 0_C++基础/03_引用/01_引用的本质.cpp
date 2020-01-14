#include "iostream"

using namespace std;


// 引用必须初始化 // 类似 const
// 引用变量地址与原变量一致，是一个指针？
// 
// 引用本质： TYPE * cosnt var;
void main00() 
{
	int const a = 10;
	int b = 20;
	int& c = b;

	printf("&b:%d\n", &b);
	printf("&c:%d\n", &c);  // 一样的值


	cout << "Hello World!" << endl;
	system("pause");
}

// 引用占用空间
struct stud
{
	char name[20];  // 20字节
	int age;  // 4字节

	int& a;  // 4字节
	int& b;  // 4字节
};

void main01()
{
	printf("sizeof(stud):%d\n", sizeof(stud));


	system("pause");
}



// 间接赋值 与引用 ？？？ 具有一样的操作，引用由指针实现
void change0(int* const a)
{
	*a = 1000;
}

void change1(int& a)
{
	a = 2000;
}

void main()
{
	int a = 10;

	printf("a:%d\n", a);

	change0(&a);  // 间接赋值
	printf("a:%d\n", a);
	 
	change1(a);
	printf("a:%d\n", a); // 引用  

	system("pause");
}