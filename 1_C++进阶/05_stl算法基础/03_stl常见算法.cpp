
#include "iostream"
#include "string"
#include "vector"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
#include "iterator"   // 为ostem_iterator
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
int main() 
{
	int ret = 0;

	// testVoid_foreach();
	testVoid_transform();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}