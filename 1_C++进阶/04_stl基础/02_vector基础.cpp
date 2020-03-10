
#include "iostream"
using namespace std;
#include "vector"

// vector 尾部插入删除  获取头部尾部元素
void testVoid1() 
{
	 vector <int> v1(10); // 提前分配内存 

	 for (int i = 0; i < 10; i++)
	 {
		 v1.push_back(i);  // 尾部插入
	 }
	 cout << "头部元素：" << v1.front() << endl; // 获取头部元素
	 for (int i = 0; i < 10; i++)
	 { 
		 cout << "尾部元素" << v1.back() << endl;  // 获取尾部元素
		 v1.pop_back(); // 删除尾部元素  
	 }
}

void printV(vector<int>& vInt)
{
	/*
	for (int i = 0; i < vInt.size(); i++)
	{
		cout << vInt[i] << "  ";
	}
	*/
	for (int i = 0; i < vInt.size(); i++)
	{
		cout << vInt.at(i) << " ";
	}
	cout << endl;
}

// vector 初始化
void testVoid2()
{
	vector <int > v1; // 无参构造函数
	v1.push_back(22);
	v1.push_back(23);
	v1.push_back(245);
	v1.push_back(26);
	v1.push_back(27);

	vector<int> v2 = v1; // copy 构造函数
	vector<int> v3(v1.begin(), v1.end() - 2);  // 带参构造函数 从v1头到v1尾-2赋值给v3

	vector<int> v4(4, 5);  // 带参构造函数 v4尾部插入4个5

	printV(v1);
	printV(v2);
	printV(v3);
	printV(v4);
}

// 迭代器
// 1 正逆序指针值
//   正序时， begin()指向首元素，end()指向尾元素的后一个地址
//   逆序时， rbegin()指向为元素，rend()指向首元素的前一个地址
// 2 迭代器分类
/*
	using iterator               = _Vector_iterator<_Scary_val>; 
	using const_iterator         = _Vector_const_iterator<_Scary_val>;  
	using reverse_iterator       = _STD reverse_iterator<iterator>;
	using const_reverse_iterator = _STD reverse_iterator<const_iterator>;
*/
void testVoid3()
{
	vector <int > v1(10);

	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	// 正序遍历
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 倒序遍历
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++)
	{
		cout << *rit << " ";
	}
	cout << endl;
}

// vector 插入删除操作
void testVoid4()
{
	vector <int > v1(10);

	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}
	printV(v1);

	// 指定序列删除  删除前两个元素
	v1.erase(v1.begin(), v1.begin() + 2);
	printV(v1);

	// 指定位置删除  删除第三个元素
	v1.erase(v1.begin() + 2);
	printV(v1);

	v1[v1.front()] = 3;
	v1[v1.front() + 2] = 3;
	// 指定元素删除  删除3 
	for (vector<int>::iterator it = v1.begin(); it != v1.end();)
	{
		if (*it == 3)  
		{
			it = v1.erase(it); // erase 删除迭代器位置时，返回下一个被删除元素的下一个元素的迭代器(即 默认执行 it++ 操作) 
		}
		else
		{
			it++;
		}
	}
	printV(v1);

	// 插入 头插22 尾插23
	v1.insert(v1.begin(), 22);
	v1.insert(v1.end(), 23);
	printV(v1);
}

int main() 
{
	int ret = 0;

	// testVoid1();
	// testVoid2();
	// testVoid3();
	testVoid4();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}