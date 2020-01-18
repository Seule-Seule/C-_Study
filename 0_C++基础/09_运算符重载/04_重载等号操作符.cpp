#define _CRT_SECURE_NO_WARNINGS
#include "iostream"

using namespace std;

class Student
{
public:
	Student(const char* p)
	{
		nameLen = strlen(p);
		name = (char*)malloc(nameLen + 1);  // 为字符串结尾符"\0"加一
		strcpy(name, p);
	}

	// 为进行深拷贝重写的拷贝构造函数
	Student(const Student& obj)
	{
		nameLen = obj.nameLen;
		name = (char*)malloc(nameLen + 1);
		strcpy(name, obj.name);
	}
	/*void operator=(Student& s1)
	{
		// 1 先释放资源
		if (this->name != NULL)
		{
			free(this->name);
			this->nameLen = 0;
		}
		// 2  申请空间
		this->nameLen = s1.nameLen;
		this->name = (char*)malloc(s1.nameLen + 1);
		// 3 copy 数据
		strcpy(name, s1.name);
		return;
	}
	*/
	Student& operator=(Student& s1)
	{
		// 1 先释放资源
		if (this->name != NULL)
		{
			delete this->name;
			//free(this->name); // 都可以，对char指针操作，不是对this指针操作
			this->nameLen = 0;
		}
		// 2  申请空间
		this->nameLen = s1.nameLen;
		this->name = (char*)malloc(s1.nameLen + 1);
		// 3 copy 数据
		strcpy(name, s1.name);
		return *this;
	}
	~Student()
	{
		if (name != NULL)
		{
			free(name);
			name = NULL;
		}
		nameLen = 0;
	}

private:
	char* name;
	int nameLen;
};


void testStudentClass()
{
	Student s1("name1");
	Student s2 = s1; // 浅拷贝，析构时free野指针宕机，编写拷贝构造函数进行深拷贝
	Student s3(s1);
	Student s4("name4");

	// 重载等号操作符
	// s4.operator=(s1)
	// void operator=(Student & s1);
	s4 = s1;  // 赋值操作， 浅拷贝， 需要对等号操作符重载

	// Student &operator=(Student & s1);
	s3 = s4 = s1; // 返回一个引用
}

void main()
{
	testStudentClass();
	cout << "Hello World!" << endl;
	system("pause");
	return;
}