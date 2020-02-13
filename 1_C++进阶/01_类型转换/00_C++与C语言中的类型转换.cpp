
#include "iostream"
using namespace std;



/*
C 语言中的类型转换：（强制类型转换）
	TYPE b = (TYPE) a;
	6
C++ 语言中的类型转换：（4种、应对不同场合）
	1 static_cast
		静态类型转换所有C语言支持都不会报错， 不支持的会报错
	2 reinterpret_cast
		重新解释类型
	3 dynamic_cast
		动态类型转换， 如父类和子类之间的多态类型转换
	4 const_cast
		去 const 属性
*/

int main_static_cast_reinterpret_cast()
{
	int ret = 0;

	double pi = 3.1415926; 
	
	int cIntPi = (int)pi;   // C 语言
	
	int cPlusIntPi = static_cast<int>(pi);  // C++类型转换   编译器编译时做静态类型检查， 仅支持C语言支持类型
	int cPlusIntPi2 = pi;// C 语言中支持隐式类型转换的地方均支持 static_cast<>();做类型转换
	
	//char * -> int *
	char* charPoint= (char*)"test";
	int* intPoint = NULL;
	// intPoint = static_cast<int*>(charPoint);  // ERROR
	intPoint = reinterpret_cast<int*>(charPoint);  // 不同类型之间强制类型转换使用 reinterpret_cast<>() 重新解释

	cout << "charPoint : " << charPoint << endl;  //%s
	cout << "intPoint  : " << intPoint << endl;   //%d

	// ！！！ 通过 static_cast<>() 和 reinterpret_cast<>() 把C语言中的强制类型转换都覆盖了
	
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}

class People
{
public:
	People(int age)
	{
		this->age = age;
	}
public:
	virtual void PrintAge() = 0;
public:
	int age;
};

class Student : public People
{
public:
	Student(int age) :People(age)
	{

	}
public:
	virtual void PrintAge()
	{
		cout << "student age: " << age << endl;
	}
	void study()
	{
		cout << "学习" << endl;
	}
};

class Teacher : public People
{
public:
	Teacher(int age) :People(age)
	{

	}
	virtual void PrintAge()
	{
		cout << "teacher age: " << age << endl;
	}
	void teach()
	{
		cout << "教书" << endl;
	}

};

void school(People* base)
{
	base->PrintAge(); // 1 继承 2 虚函数重写 3 父类指针指向子类对象  --> 多态

	// dynamic_cast   能识别子类对象
	// 父类对象转向子类对象   向下转型   把老子 转成 小子

	Student* pStudent = dynamic_cast<Student*>(base);
	if (NULL != pStudent)
	{
		pStudent->study();
	}
	Teacher* pTeacher = dynamic_cast<Teacher*>(base);
	if (NULL != pTeacher)
	{
		pTeacher->teach();
	}
}

int main_dynamic_cast()
{
	int ret = 0;

	Student s1(21);
	Teacher t1(34);

	school(&s1);
	school(&t1);

	{
		Student* ps2 = &s1;
		Teacher* pt2 = &t1;
		//ps2 = static_cast<Student*>(pt2);  // 类型转换无效
		ps2 = reinterpret_cast<Student*>(pt2);  // 强制类型转换
	}
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}

void PrintBuf(const char* pBuf)
{
	// pBuf[0] = 'Z';  // ERROR 不可修改
	char* pTmp = NULL;

	// 去掉只读属性
	// const char * -> char *
	pTmp = const_cast<char *>(pBuf);
	pTmp[0] = 'Z';
	cout << pTmp << endl;
}
int main() 
{
	int ret = 0;

	char buf[] = "abcdefg";

	PrintBuf(buf);
	// ！！！去掉const属性时程序员要确保内存空间是可修改的！！！
	// 常量区
	char* pErro = (char *)"abcdegfh";
	// PrintBuf(pErro);  // ERROR 常量区数据不能修改

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}