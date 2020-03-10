#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

// 容器装基本数据类型
void testVoid1()
{
	vector<int> v1; //  容器 把数据copy到容器中 实现了 数据结构 和 算法 的有效分离
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(3);
	v1.push_back(3);

	// 迭代器  相当于一个指针
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}

	// 算法和容器无缝连接 
	int num = count(v1.begin(), v1.end(), 3);
	cout << "num: " << num << endl;
}

class People
{
public:
	int		age;
	char	name[32];
public:
	People(int age, const char* name)
	{
		this->age = age;
		strcpy(this->name, name);
	}
	void Printf()
	{
		cout << "name: " << name << " age: " << age << endl;
	}
};

// 容器装类对象
void testVoid2()
{
	People p1(32, "name1");
	People p2(33, "name2");
	People p3(34, "name3");

	vector<People> v1; //  容器 把数据copy到容器中
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);

	// 迭代器  相当于一个指针
	for (vector<People>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		(*it).Printf();
	}

	// 算法和容器无缝连接 
	//int num = count(v1.begin(), v1.end(), 3);
	//cout << "num: " << num << endl;
}

// 容器装指针
void testVoid3()
{
	People p1(32, "name1");
	People p2(33, "name2");
	People p3(34, "name3");
	
	People* pp1 = &p1;
	People* pp2 = &p2;
	People* pp3 = &p3;

	vector<People *> v1; //  容器 把数据copy到容器中
	v1.push_back(pp1);
	v1.push_back(pp2);
	v1.push_back(pp3);

	// 迭代器  相当于一个指针
	for (vector<People*>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		(*it)->Printf();
	}

	// 算法和容器无缝连接 
	//int num = count(v1.begin(), v1.end(), 3);
	//cout << "num: " << num << endl;
}

int main() 
{
	int ret = 0;

	cout << "testVoid1();" << endl;
	testVoid1();
	cout << "testVoid2();" << endl;
	testVoid2();
	cout << "testVoid3();" << endl << endl << endl;
	testVoid3();


	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}