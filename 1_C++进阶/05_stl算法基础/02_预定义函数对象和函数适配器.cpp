
#include "iostream"
#include "string"
#include "vector"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
using namespace std;

void test_void0()
{
	// 预定义函数对象：stl定义好的函数对象， 放在functional中 
	// 例：plus<Type> 能实现不同类型数据的相加运算
	plus<int> intAdd;
	int x = 20;
	int y = 30;
	int z = intAdd(x, y);
	cout << "z:" << z << endl;

	plus<string> stringAdd;
	string str1 = "asas";
	string str2 = "vsdvg";
	string str3 = stringAdd(str1, str2);
	cout << "str3:" << str3 << endl;

	vector<string> v1;
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("ccc");
	v1.push_back("ccc");
	v1.push_back("ccc");
	v1.push_back("bbb");
	v1.push_back("sss");

	/*
	// STRUCT TEMPLATE greater
template <class _Ty = void>
struct greater {
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty first_argument_type;
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty second_argument_type;
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool result_type;

	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
		return _Left > _Right;
	}
}; 
*/
	// sort 默认从小到大， greater 从大到小
	sort(v1.begin(), v1.end(), greater<string>());
	for (vector<string>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}
	
	/*
	// STRUCT TEMPLATE equal_to
template <class _Ty = void>
struct equal_to {
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty first_argument_type;
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty second_argument_type;
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool result_type;

	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
		return _Left == _Right;
	}
};
	*/
	// 求ccc出现的个数
	// qual_to<string>()的两个参数一个来自容器， 另一个来自sc
	// bind2nd将sc与qual_to<string>()相联系
	string sc = "ccc";
	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(),sc));
	cout << "num: " << num << endl;

}

class IsGreat
{
public:
	IsGreat(int i)
	{
		_Left = i;
	}
	bool operator()(int _Right)
	{
		return (_Right > _Left);
	}
private:
	int _Left;
};
void test_void1()
{
	vector<int> v1;
	for (int i = 0; i < 20; i++)
	{
		v1.push_back(i + 1);
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	


	// 查找vector中3的个数
	int num1 = count(v1.begin(), v1.end(), 3);
	cout << "num1: " << num1 << endl;

	// 查找大于2 数的个数
	int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
	cout << "num2: " << num2 << endl;

	// 预定义函数对象查找大于2 的个数
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
	cout << "num3: " << num3 << endl;

	// 查找奇数个数
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "num4: " << num4 << endl;

	// 查找偶数个数
	int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "num5: " << num5 << endl;
}

int main() 
{
	int ret = 0;

	// test_void0();
	test_void1();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}