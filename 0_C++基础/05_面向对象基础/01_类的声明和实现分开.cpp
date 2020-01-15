#include "iostream"

using namespace std;

#include "01_Student.h"

void main() 
{
	Student s;
	s.setAge(20);
	cout << "s.age:" << s.getAge() << endl;

	cout << "Hello World!" << endl;
	system("pause");
}