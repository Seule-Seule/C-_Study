#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
using namespace std;
#include "09_MyVector.cpp"


int mainInt() 
{
	int ret = 0;

	MyVector<int> intArray(10);

	// 赋值
	for (int i = 0; i < 10; i++)
	{
		intArray[i] = i;
	}

	// 打印
	for (int i = 0; i < 10; i++)
	{
		cout << intArray[i] << " ";
	}
	cout << endl;

	cout << intArray;

	MyVector<int> intArray2 = intArray;
	
	cout << intArray2;

	return ret;
}


int mainChar() 
{
	int ret = 0;

	MyVector<char> intArray(10);

	// 赋值
	for (int i = 97; i < 107; i++)
	{
		intArray[i] = i;
	}

	// 打印
	for (int i = 97; i < 107; i++)
	{
		cout << intArray[i] << " ";
	}
	cout << endl;

	cout << intArray;

	MyVector<char> intArray2 = intArray;

	cout << intArray2;

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}


class Teacher
{
public:
	Teacher()
	{
		age = 0;
		name[0] = 0;
	}
	Teacher(int age, const char* name )
	{
		this->age = age;
		strcpy(this->name, name);
	}
	~Teacher()
	{
		this->age = 0;
		strcpy(this->name, "");
	}
	void Print()
	{
		cout << name << " : " << age << endl;
	}
private:
	int age;
	char name[30];
};

int mainTeacher()
{
	int ret = 0;

	Teacher TeacherArray[3] = { Teacher(12,"name1"),Teacher(14,"name2"),Teacher(13,"name3") };

	MyVector<Teacher> Tarray(3);

	for (int i = 0; i < 3; i++)
	{
		Tarray[i] = TeacherArray[i];
	}

	for (int i = 0; i < 3; i++)
	{
		Tarray[i].Print();
	}

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}


//  带有指针时必须重写的函数
//  1  拷贝构造函数
//  2  重载等号操作符
//  3  重载左移操作符

class Teacher1
{
public:
	Teacher1()
	{
		age = 0;
		name = NULL;
	}
	Teacher1(int age, const char* name)
	{
		int len = strlen(name);
		this->name = new char[len + 1];
		this->age = age;
		strcpy(this->name, name);
	}
	Teacher1(Teacher1& _T)
	{
		// 释放资源
		if (this->name != NULL)
		{
			delete[] name;
			this->name = NULL;
			this->age = 0;
		}
		// 申请空间
		int tmpLen = strlen(_T.name);
		this->name = new char[tmpLen + 1];
		// 进行深拷贝
		this->age = _T.age;
		strcpy(this->name, _T.name);
	}
	~Teacher1()
	{
		if (name != NULL) {
			delete[] name;
			name = NULL;
			this->age = 0;
		}
	}
public:
	friend ostream& operator<<(ostream& out, Teacher1& _T);
	Teacher1& operator=(Teacher1& _T)
	{
		// 释放资源
		if (this->name != NULL)
		{
			delete[] name;
			this->name = NULL;
			this->age = 0;
		}
		// 申请空间
		int tmpLen = strlen(_T.name);
		this->name = new char[tmpLen + 1];
		// 进行深拷贝
		this->age = _T.age;
		strcpy(this->name, _T.name);
		return *this;
	}
public:
	void Print()
	{
		cout << name << " : " << age << endl;
	}
private:
	int age;
	char *name;
};
ostream& operator<<(ostream& out, Teacher1& _T)
{
	out << "age: " << _T.age << "  name: " << _T.name << endl;
	return out;
}

int mainTeacher1()
{
	int ret = 0;

	//Teacher1 TeacherArray[3] = { Teacher1(12,"name1"),Teacher1(14,"name2"),Teacher1(13,"name3") };

	Teacher1 T1(23, "NAME1");
	Teacher1 T2(22, "NAME2");
	Teacher1 T3(21, "NAME3");
	
	MyVector<Teacher1> Tarray(3);

	Tarray[0] = T1;
	Tarray[1] = T2;
	Tarray[2] = T3;

	for (int i = 0; i < 3; i++)
	{
		Tarray[i].Print();
	}

	cout << Tarray;

	Tarray[0] = T2;

	cout << Tarray;

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}

int main()
{
	int ret = 0;

	//Teacher1 TeacherArray[3] = { Teacher1(12,"name1"),Teacher1(14,"name2"),Teacher1(13,"name3") };

	Teacher1 T1(23, "NAME1");
	Teacher1 T2(22, "NAME2");
	Teacher1 T3(21, "NAME3");

	MyVector<Teacher1 *> Tarray(3);

	Tarray[0] = &T1;
	Tarray[1] = &T2;
	Tarray[2] = &T3;

	for (int i = 0; i < 3; i++)
	{
		Tarray[i]->Print();
	}

	//cout << Tarray;

	Tarray[0] = &T2;

	// cout << Tarray;
	for (int i = 0; i < 3; i++)
	{
		Tarray[i]->Print();
	}

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}

