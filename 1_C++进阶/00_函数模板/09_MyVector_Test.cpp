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

int main() 
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