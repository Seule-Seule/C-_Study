#include "iostream"

using namespace std;

// C 语言中二级指针的使用
struct stud
{
	char name[20];
	int age;
};

int Getstud1(stud** p)
{
	stud* tmp;
	if (p == NULL)
	{
		return -1;
	}
	tmp = (stud *)malloc(sizeof(stud));
	if (tmp == NULL)
	{
		return -2;
	}
	tmp->age = 20;
	*p = tmp;
	return 0;
}

void FreeStud(stud* p)
{
	if (p == NULL)
	{
		return;
	}
	free(p);
}

// C++ 语言中的引用
int Getstud2(stud*& p)
{
	if (p == NULL)
	{
		return -1;
	}
	p = (stud*)malloc(sizeof(stud));
	if (p == NULL)
	{
		return -2;
	}
	p->age = 30;
	return 0;
}

void main() 
{
	stud* s1 = NULL;
    Getstud1(&s1);
	cout << "s1.age:" << s1->age << endl;
	FreeStud(s1);

	Getstud2(s1);
	cout << "s1.age:" << s1->age << endl;
	FreeStud(s1);

	cout << "Hello World!" << endl;
	system("pause");
}