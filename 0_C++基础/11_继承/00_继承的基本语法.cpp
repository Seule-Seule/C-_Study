#define   _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

class People
{
public:
	int age;  
	char name[30];

public:
	void Print()
	{
		cout << "age: " << age << "  name: " << name << endl;
	}
protected:
private:
};


//class Student :private People
//class Student :protected People
class Student :public People
{
public:
	int studyAge;
protected:
private:
};

void main() 
{
	Student s1;
	s1.age = 20;
	s1.studyAge = 3;
	strcpy(s1.name, "name:s1");
	s1.Print();
	cout << "Hello World!" << endl;
	system("pause");
}