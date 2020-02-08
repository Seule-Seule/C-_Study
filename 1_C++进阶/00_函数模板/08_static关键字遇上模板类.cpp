
#include "iostream"
using namespace std;

template <typename Type>
class Test
{
public:
	static Type staticVal;
};

template <typename Type>
Type Test<Type>::staticVal;


// 模板类的静态成员变量每个类都拥有自己的静态成员变量 --  模板类的编译机制吻合
int main() 
{
	int ret = 0;

	Test<int> t1, t2, t3;

	cout << t1.staticVal << endl;
	t2.staticVal++;
	t3.staticVal++;
	cout << t1.staticVal << endl;

	Test<char> c1, c2, c3;
	c1.staticVal = 4;
	cout << c1.staticVal << endl;
	c2.staticVal++;
	cout << c1.staticVal << endl;
	cout << t1.staticVal << endl;

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}