
#include "iostream"
#include "string"
#include "vector"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
#include "iterator"   // 为ostem_iterator
#include "numeric"
using namespace std;


void printElem(vector<int> & _v)
{
	for (vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
	{
		cout << *it << " ";
	}
}

void showElem(int n)
{
	cout << n << " ";
}

class voidShowElem
{
public:
	voidShowElem()
	{
		num = 0;
	}
	void operator()(int n)
	{
		num++;
		cout << n << " ";
	}
	void printNum()
	{
		cout << "num:" << num << endl;
	}
private:
	int num;
};
void testVoid_foreach()
{
	vector<int> v1;
	for (int i = 0;i < 10;i ++)
	{
		v1.push_back(i + 1);
	}
	printElem(v1);
	cout << endl;
	/*
	// FUNCTION TEMPLATE for_each
template <class _InIt, class _Fn>
_Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) { // perform function for each element [_First, _Last)
	_Adl_verify_range(_First, _Last);
	auto _UFirst      = _Get_unwrapped(_First);
	const auto _ULast = _Get_unwrapped(_Last);
	for (; _UFirst != _ULast; ++_UFirst) {
		_Func(*_UFirst);
	}

	return _Func;
}*/

	// for_each 第三个参数是函数对象或者回调函数入口地址 可以修改容器参数
	for_each(v1.begin(), v1.end(), showElem);
	cout << endl;

	for_each(v1.begin(), v1.end(), voidShowElem());
	cout << endl;

	// for_each() 返回第三参数的一个对象，第三参数是值拷贝传参数
	voidShowElem vSE0, vSE1;
	vSE0.printNum(); vSE1.printNum();
	vSE1 = for_each(v1.begin(), v1.end(), vSE1);
	cout << endl;
	vSE0.printNum(); vSE1.printNum(); 

}

int dec10(int& n)
{
	return n * 10;
}

void printElemList(list<int>& l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it ++)
	{
		cout << *it << " ";
	}
}
void testVoid_transform()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	printElem(v1);
	cout << endl;

	// 回调函数型
	transform(v1.begin(), v1.end(), v1.begin(), dec10);
	printElem(v1);
	cout << endl;

	// 函数对象型
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
	printElem(v1);
	cout << endl;

	// 函数适配器
	list<int> l1;
	l1.resize(v1.size());
	transform(v1.begin(), v1.end(), l1.begin(), bind2nd( multiplies<int>(), 10) );
	printElemList(l1);
	cout << endl;

	// 输出到指定缓冲区
	transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "), negate<int>());
	cout << endl;
}

// 查找指定范围内重复元素，返回第一对重复元素的第一个元素的it
void testVoid_adjacent_find()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
	{
		cout << "查找成功！ 元素：" << *it << "  Index:" << distance(v.begin(), it) <<endl;

	}
	else
	{
		cout << "查找失败！" << endl;
	}
}

// 二分法查找，有序序列快，返回bool
void testVoid_binary_search()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	bool b = binary_search(v.begin(), v.end(), 3);
	if (b == true)
	{
		cout << "查找成功！" << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
}


bool daYu3(int& n)
{
	return (n >= 3);
}
// 查找指定序列中指定元素个数
void testVoid_count_countIf()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);

	int num = count(v.begin(), v.end(), 3);
	cout << "num:" << num << endl;

	num = count_if(v.begin(), v.end(), daYu3);
	cout << "num:" << num << endl;
}

// 查找指定元素返回it
void testVoid_find_findIf()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);

	vector<int>::iterator it = find(v.begin(), v.end(), 3);
	if (it != v.end())
	{
		cout << "查找成功！ " << *it << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}

	vector<int>::iterator it2 = find_if(v.begin(), v.end(), daYu3);
	if (it2 != v.end())
	{
		cout << "查找成功！ " << *it2 << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
}

// 合并两个有序序列，存放到另一个序列
void testVoid_merge()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);
	v2.push_back(8);
	vector<int> v3;
	v3.resize(v1.size() + v2.size());
	printElem(v3);
	cout << endl;

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printElem(v3);
	cout << endl;
}

class People
{
public:
	People(string name, int id)
	{
		pv_id = id;
		pv_name = name;
	}
	void printP()
	{
		cout << "name:" << pv_name << "  id:" << pv_id << endl;
	}
public:
	int		pv_id;
	string	pv_name;
};

bool comperaP(People& p1, People& p2)
{
	return (p1.pv_id < p2.pv_id); // 从小到大
}
// 默认升序，可以自定义规则
void testVoid_sort()
{
	People p1("111", 1);
	People p2("222", 2);
	People p3("333", 3);
	People p4("444", 4);

	vector<People> v;
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p1);
	v.push_back(p2);

	for (vector<People>::iterator it = v.begin(); it != v.end(); it ++)
	{
		it->printP();
	}
	cout << endl; 
	sort(v.begin(), v.end(), comperaP);
	for (vector<People>::iterator it = v.begin(); it != v.end(); it++)
	{
		it->printP();
	}
}

// 随机排序
void testVoid_random_shuffle()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	printElem(v1);
	cout << endl;

	random_shuffle(v1.begin(), v1.end());
	printElem(v1);
	cout << endl;

	string str = "asdfasdfs";
	random_shuffle(str.begin(), str.end());
	cout << str << endl;
}

// 倒序
void testVoid_reverse()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	printElem(v1);
	cout << endl;

	reverse(v1.begin(), v1.end());
	printElem(v1);
	cout << endl;
}

// 复制
void testVoid_copy()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	vector<int> v2;
	v2.resize(v1.size());

	copy(v1.begin(),v1.end(), v2.begin());
	printElem(v2);
}

// 替换指定范围内的指定元素为指定值
void testVoid_replace()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	replace(v1.begin(), v1.end(), 3, 1);

	replace_if(v1.begin(), v1.end(), daYu3, 5);

	printElem(v1);
}

// 交换容器值
void testVoid_swap()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	vector<int> v2;
	for (int i = 0; i < 5; i++)
	{
		v2.push_back(i + 1);
	}

	swap(v1, v2);
	
	printElem(v1);
	cout << endl;
	printElem(v2);
	cout << endl;

}

// 范围累加
void testVoid_accumulate()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	int sum = accumulate(v1.begin(), v1.end(), 100);
	cout << "sum:" << sum << endl;
}

// 批量替换
void testVoid_fill()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	fill(v1.begin(), v1.end(), 100);
	printElem(v1);
}

// 两个有序序列的并集
void testVoid_setunion()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(i + 10);
	}

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printElem(v3);
}

int main() 
{
	int ret = 0;
	 
    // testVoid_foreach();
	// testVoid_transform();


	// testVoid_adjacent_find();
	// testVoid_binary_search();
	// testVoid_count_countIf();
	// estVoid_find_findIf();


	// testVoid_merge();
	// testVoid_sort();
	// testVoid_random_shuffle();
	// testVoid_reverse();

	// testVoid_copy();
	// testVoid_replace();
	// testVoid_swap();

	// testVoid_accumulate();
	// testVoid_fill();

	testVoid_setunion();
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}