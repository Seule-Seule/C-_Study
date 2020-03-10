
#include "iostream"
using namespace std;
#include "stack"

void testVoid1()
{
	stack<int> s;
	s.push(0); // 入栈
	s.push(1);
	s.push(2);

	cout << "栈大小 : " << s.size() << endl;

	while (!s.empty())
	{
		cout << s.top() << " "; // 获取栈顶元素
		s.pop();  // 出栈
	}
}

class People
{
public:
	int age;
	char name[32];
public:
	void printA()
	{
		cout << "age : " << age << endl;
	}
};

void testVoid2()
{
	People p1;
	People p2;
	People p3;
	p1.age = 11;
	p2.age = 12;
	p3.age = 13;

	stack<People> s;
	s.push(p1); // 入栈
	s.push(p2);
	s.push(p3);

	cout << "栈大小 : " << s.size() << endl;

	while (!s.empty())
	{
		s.top().printA(); // 获取栈顶元素
		s.pop();  // 出栈
	}
}

void testVoid3()
{
	People p1;
	People p2;
	People p3;
	p1.age = 11;
	p2.age = 12;
	p3.age = 13;

	stack<People *> s;
	s.push(&p1); // 入栈
	s.push(&p2);
	s.push(&p3);

	cout << "栈大小 : " << s.size() << endl;

	while (!s.empty())
	{
		s.top()->printA(); // 获取栈顶元素
		s.pop();  // 出栈
	}
}

int main() 
{
	int ret = 0;

	// testVoid1();
	testVoid2();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}