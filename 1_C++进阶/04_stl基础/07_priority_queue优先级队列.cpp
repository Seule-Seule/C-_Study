
#include "iostream"
using namespace std;

#include <queue>

void testVoid()
{
	priority_queue<int> p1;   // 优先级队列 默认最大值优先
	priority_queue < int  , vector<int>, less<int >> p2;  // 最大值优先的优先级队列完整定义
	priority_queue< int, vector<int>, greater<int> > p3;  // 最小值优先的优先级队列定义

	p1.push(5);
	p1.push(4);
	p1.push(3);
	p1.push(2);

	cout << "最大值优先 size ->" << p1.size() << endl;
	cout << "最大值优先 top  ->" << p1.top() << endl;

	// 遍历
	while (p1.size() > 0)
	{
		cout << p1.top() << "  ";
		p1.pop();
	}
	cout << endl;

	p3.push(1);
	p3.push(2);
	p3.push(3);
	p3.push(4);

	cout << "最小值优先 size ->" << p3.size() << endl;
	cout << "最小值优先 top  ->" << p3.top() << endl;

	// 遍历
	while (p3.size() > 0)
	{
		cout << p3.top() << "  ";
		p3.pop();

	}
	cout << endl;
}
int main() 
{
	int ret = 0;

	testVoid();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}