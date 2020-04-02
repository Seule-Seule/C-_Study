
#include "iostream"
using namespace std;

#include "set"

// 元素不唯一的set集合
void test_void()
{
	multiset<int> mset;

    // 插入
	int tmp = 0;
	cout << "输入数字 -> ";
	cin >> tmp;
	while (tmp != -1)
	{
		mset.insert(tmp);
		cout << "输入数字 -> ";
		cin >> tmp;
	}

	// 遍历
	for (multiset<int>::iterator it = mset.begin(); it != mset.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 删除
	while (!mset.empty())
	{
		multiset<int>::iterator it1 = mset.begin();
		cout << *it1 << " ";
		mset.erase(it1);
	}
	cout << endl;
}
int main() 
{
	int ret = 0;
	test_void();
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}