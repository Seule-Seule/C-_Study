#define  _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

#include <set>

// 集合模型 元素确定（唯一）  自动排序（默认从大到小） 不能位置操作
//  红黑树 平衡二叉树

// 添加 插入 遍历 删除
void test_void()
{
	set<int> set1;

	//添加
	for (int i = 0; i < 10; i++)
	{
		int tmp = rand();
		set1.insert(tmp);
	}

	// 插入 验证元素唯一性
	set1.insert(520);
	set1.insert(520);
	set1.insert(520);

	// 遍历
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 删除
	while (!set1.empty())
	{
		set<int>::iterator delete_tmp = set1.begin();
		cout << *delete_tmp << " ";
		set1.erase(delete_tmp);
	}
	cout << endl;

}

// 自动排序
void test_void1()
{
	set<int> set1;   // 默认 从小到大
	set<int, less<int>> set2; // 默认定义的完整定义

	set<int, greater<int>> set3; // 从大到小排序

	//添加
	for (int i = 0; i < 10; i++)
	{
		int tmp = rand();
		set3.insert(tmp);
	}

	// 遍历
	for (set<int, greater<int>>::iterator it = set3.begin(); it != set3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 删除
	while (!set3.empty())
	{
		set<int, greater<int>>::iterator delete_tmp = set3.begin();
		cout << *delete_tmp << " ";
		set3.erase(delete_tmp);
	}
	cout << endl;
}


// set 对复杂数据类型的排序 仿函数
class People
{
public:
	People(const char* name, int age)
	{
		this->age = age;
		strcpy(this->name, name);
	}
public:
	char name[64];
	int age;
private:
};
// 仿函数
struct FuncSetPeople
{
	bool operator() (const People& left, const People& right) const
	{
		if (left.age > right.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

void test_void2()
{
	People p1("p1", 54);
	People p2("p2", 24);
	People p3("p3", 17);
	People p4("p4", 32);
	People p5("p5", 32);
	set<People , FuncSetPeople> set1;
	set1.insert(p1);
	set1.insert(p2);
	set1.insert(p3);


	// 重复插入问题 查看函数返回值以确定是否插入成功 （set排序关键字相同时，插入失败）
	pair<set<People, FuncSetPeople>::iterator, bool> pair_p4 = set1.insert(p4);
	if (pair_p4.second == true)
	{
		cout << "p4 插入成功" << endl;
	}
	else
	{
		cout << "p4 插入失败" << endl;
	}
	pair<set<People, FuncSetPeople>::iterator, bool> pair_p5 = set1.insert(p5);
	if (pair_p5.second == true)
	{
		cout << "p5 插入成功" << endl;
	}
	else
	{
		cout << "p5 插入失败" << endl;
	}
	// 遍历
	for (set<People, FuncSetPeople>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << it->name << "  " << it->age << endl;
	}

}

// set 查找
void test_void3()
{
	set<int> set1;

	//添加
	for (int i = 0; i < 10; i++)
	{
		set1.insert(i + 1);
	}

	// 遍历
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int>::iterator it0 = set1.find(5);   // 返回元素elem的迭代器的位置
	cout << "set1.find(5) it0 : " << *it0 << endl;

	int number = set1.count(5);   // 返回元素elem的个数 1 or 0
	cout << "set1.count(5) number : " << number << endl;

	set<int>::iterator it1 = set1.lower_bound(5);   // 返回第一个大于等于元素elem的迭代器的位置
	cout << "set1.lower_bound(5) it1 : " << *it1 << endl;

	set<int>::iterator it2 = set1.upper_bound(5);   // 返回第一个大于元素elem的迭代器的位置
	cout << "set1.upper_bound(5) it2 : " << *it2 << endl;
	
	set1.erase(5);   // 删除元素 5
	pair<set<int>::iterator, set<int>::iterator> pair_set1 = set1.equal_range(5);   // 返回<lower_bound, upper_bound>
	set<int>::iterator lower_bound_set1 = pair_set1.first;
	set<int>::iterator upper_bound_set1 = pair_set1.second;
	cout << "set1.equal_range(5) lower_bound_set1 : " << *lower_bound_set1 << endl;
	cout << "set1.equal_range(5) upper_bound_set1 : " << *upper_bound_set1 << endl;
}

int main() 
{
	int ret = 0;

	// test_void();
	// test_void1();
	// test_void2();
	test_void3();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}