#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;
#include "vector"

// 要确保装入容器的元素可以被拷贝
//    重写 拷贝构造函数
//    重载 =操作符

class People
{
public:
	int	age;
	char* name;
public:
	People(const char* name, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}

	// 没有可用的复制构造函数或复制构造函数声明为“explicit”
	// 解决方法： 形参前加上 const
	People(const People& obj)  
	{
		this->name = new char[strlen(obj.name) + 1];
		strcpy(this->name, obj.name);
		this->age = obj.age;
	}
public:
	// p1 = p2 = p3
	People& operator=(People& obj)
	{
		// 释放资源
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
			this->age = 0;
		}
		// 申请空间
		this->name = new char[strlen(obj.name)];
		// 拷贝数据
		strcpy(this->name, obj.name);
		this->age = obj.age;

		return *this;
	}
};

void test_void()
{
	People p1("name", 32);
	vector<People> v;
	v.push_back(p1);
}

int main() 
{
	int ret = 0;

	test_void();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}