
#include "iostream"
using namespace std;

#include <queue>


void testVoid()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	cout << "队头元素：" << q.front() << endl;
	cout << "队列长度：" << q.size() << endl;

	while (! q.empty())
	{
		cout << q.front() << " ";
		q.pop();
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

// 复杂对象
void testVoid1()
{
	People p1, p2, p3;
	p1.age = 11;
	p2.age = 12;
	p3.age = 13;
	queue<People *> q;
	q.push(&p1);
	q.push(&p2);
	q.push(&p3);

	while (!q.empty())
	{
		People *tmp = q.front();
		tmp->printA();
		q.pop();
	}

}

void testVoid2()
{
	People p1, p2, p3;
	p1.age = 11;
	p2.age = 12;
	p3.age = 13;
	queue<People> q;
	q.push(p1);
	q.push(p2);
	q.push(p3);

	while (!q.empty())
	{
		People tmp = q.front();
		tmp.printA();
		q.pop();
	}

}


int main() 
{
	int ret = 0;

	//testVoid();
	//testVoid1();
	testVoid2();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}