
#include "iostream"
#include "string"
#include "vector"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
using namespace std;

// 函数对象 重载了函数调用操作符()的类
template <typename T>
class VoidShowElem
{
public:
	VoidShowElem()
	{
		number = 0;
	}
	void operator()(T& t)
	{
		number++;
		cout << t << " ";
	}
	void ptinN()
	{
		cout << number << endl;
	}
protected:
private:
	int number;
};

template <typename T>
void VoidShowElem1(T& t)
{
	cout << t << " ";
}

void VoidShowElem2(int& t)
{
	cout << t << " ";
}

void test_void()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	int a = 100;
	VoidShowElem<int> showElem;
	showElem(a);            // 函数对象的()的执行， 很像一个函数 -> 仿函数
	VoidShowElem1<int>(a);
	VoidShowElem2(a);

	/*  函数对象 做函数参数  返回函数对象 for_each 采用值传递， 不是引用 函数执行完成时返回匿名函数
	template <class _InIt, class _Fn>
	_Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) { // perform function for each element [_First, _Last)
		_Adl_verify_range(_First, _Last);
		auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		for (; _UFirst != _ULast; ++_UFirst) {
			_Func(*_UFirst);
		}

		return _Func;
	}
	*/

	for_each(v.begin(), v.end(), showElem);  // 函数对象是类对象，突破函数的概念，可以携带运行数据 好处
	showElem.ptinN();
	showElem = for_each(v.begin(), v.end(), showElem);// for_each 是返回 函数对象 
	showElem.ptinN();


	for_each(v.begin(), v.end(), VoidShowElem<int>());  // 匿名对象使用仿函数

	for_each(v.begin(), v.end(), VoidShowElem1<int>);  // 回调函数

	for_each(v.begin(), v.end(), VoidShowElem2);   // 回调函数 谁使用for_each , 谁编写回调函数
}

// 谓词， 返回值为bool类型的函数对象 
// 一元函数对象 参数只有一个的函数 
// 一元谓词 参数只有一个且返回bool类型的函数
template <typename Type>
class IsDiv
{
public:
	IsDiv(Type& divi)
	{
		this->divi = divi;
	}

	bool operator()(Type& t)
	{
		return (t % divi == 0);
	}
protected:
private:
	Type divi;
};

void test_void2()
{ 
	vector<int> v;
	for (int i = 1; i < 12; i++)
	{
		v.push_back(i + 20);
	}

	int a = 4;
	IsDiv<int>  is_div(a);
	/* 查找符合条件的值 返回迭代器 
	// FUNCTION TEMPLATE find_if
template <class _InIt, class _Pr>
_NODISCARD _InIt find_if(_InIt _First, const _InIt _Last, _Pr _Pred) { // find first satisfying _Pred
	_Adl_verify_range(_First, _Last);
	auto _UFirst      = _Get_unwrapped(_First);
	const auto _ULast = _Get_unwrapped(_Last);
	for (; _UFirst != _ULast; ++_UFirst) {
		if (_Pred(*_UFirst)) {
			break;
		}
	}

	_Seek_wrapped(_First, _UFirst);
	return _First;
}
*/
	vector<int>::iterator it;
	it = find_if(v.begin(), v.end(), is_div);
	if (it == v.end())
	{
		cout << "查找失败！" << endl;
	}
	{
		cout << "查找成功！第一个值为：" << *it << endl;
	}

}

// 二元函数对象
template <typename Type>
class SumAdd
{
public:
	Type operator()(Type t1, Type t2)
	{
		return t1 + t2;
	}
};

void test_void3()
{
	vector<int> v1, v2;
	vector<int> v3;

	for (int i = 0; i < 10; i++)
	{
		int tmp = rand() % 100;
		v1.push_back(tmp);

		tmp = rand() % 10;
		v2.push_back(tmp);
	}

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	v3.resize(10);              // 重置v3大小

	// 
	/*返回输出迭代器的位置
	template <class _InIt1, class _InIt2, class _OutIt, class _Fn>
_OutIt transform(const _InIt1 _First1, const _InIt1 _Last1, const _InIt2 _First2, _OutIt _Dest, _Fn _Func) {
	// transform [_First1, _Last1) and [_First2, ...) with _Func
	_Adl_verify_range(_First1, _Last1);
	auto _UFirst1      = _Get_unwrapped(_First1);
	const auto _ULast1 = _Get_unwrapped(_Last1);
	const auto _Count  = _Idl_distance<_InIt1>(_UFirst1, _ULast1);
	auto _UFirst2      = _Get_unwrapped_n(_First2, _Count);
	auto _UDest        = _Get_unwrapped_n(_Dest, _Count);
	for (; _UFirst1 != _ULast1; ++_UFirst1, (void) ++_UFirst2, ++_UDest) {
		*_UDest = _Func(*_UFirst1, *_UFirst2);
	}

	_Seek_wrapped(_Dest, _UDest);
	return _Dest;
}
*/
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());
	
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

// 二元谓词
template <typename Type>
bool v1_sort(Type& t1, Type& t2)
{
	return t1 < t2;  // 从小到大
}

void test_void4()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		int tmp = rand() % 100;
		v1.push_back(tmp);
	}

	//for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
	
	for_each(v1.begin(), v1.end(), VoidShowElem2);   // 
	cout << endl;

	sort(v1.begin(), v1.end(), v1_sort<int>);

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

struct CompareNoCase
{
	bool operator()(const string str1, const string str2) const
	{
		string str1_ = str1;
		str1_.resize(str1.size());
		transform(str1.begin(), str1.end(), str1_.begin(), tolower);

		string str2_ = str2;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower);

		return (str1_ < str2_);

	}
};

void test_void5()
{
	set<string> set1;
	set1.insert("aaaa");
	set1.insert("bbbb");
	set1.insert("cccc");
	//  _NODISCARD iterator find(const key_type& _Keyval) 
	// find 默认区分大小写
	set<string>::iterator it = set1.find("aaAa");
	if (it == set1.end())
	{
		cout << "没有找到aaaa" << endl;
	}
	else
	{
		cout << "查找成功" << endl;
	}

	
	set<string, CompareNoCase> set2;
	set2.insert("aaaa");
	set2.insert("bbbb");
	set2.insert("cccc");
	// 不区分大小写的find函数使用
	set<string, CompareNoCase>::iterator it2 = set2.find("aaAa");
	if (it2 == set2.end())
	{
		cout << "没有找到aaaa" << endl;
	}
	else
	{
		cout << "查找成功" << endl;
	}
}

int main() 
{
	int ret = 0;

	// test_void();   // 一元函数对象
	// test_void2();    // 一元谓词
	// test_void3();    // 二元函数对象
	// test_void4();    // 二元谓词
	test_void5();    // 二元谓词在set中的应用

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}