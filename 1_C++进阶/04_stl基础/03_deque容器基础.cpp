
#include "iostream"
using namespace std;
#include "deque"
#include "algorithm"


void printD(deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// 双端数组
void testVoid()
{
	deque<int> d1;
	d1.push_back(0);
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_front(-1);
	d1.push_front(-2);
	d1.push_front(-3);  // 构建 -3 -2 -1 0 1 2 3
	printD(d1);

	cout << "首部元素 : " << d1.front() << endl;
	cout << "尾部元素 : " << d1.back() << endl;
	
	d1.pop_back();
	d1.pop_front();
	printD(d1);
	
	// 查找元素0的位置
	deque<int>::iterator it = find(d1.begin(),d1.end(), 0);
	if (it != d1.end())
	{
		cout << "元素 0 下标为 : " << distance(d1.begin(), it) << endl;
	}
	else
	{
		cout << "未找到元素 0 " << endl;
	}
}

int main() 
{
	int ret = 0;

	testVoid();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}