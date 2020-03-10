
#include "iostream"
using namespace std;
#include "string"
#include "algorithm"

// string 初始化
void testVoid1()
{
	string s1 = "aaaaaaaaa";
	string s2("bbbbbbbb");
	string s3 = s2; // copy 构造
	string s4(10, 'c');

	cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl;

}

// string 遍历
void testVoid2()
{
	string s = "asdklahf jkdha ";

    // 1 数组方式
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;

	// 2 迭代器方式
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 3 at 方式
	for (int i = 0; i < s.length(); i++)
	{
		cout << s.at(i) << " ";     // 与直接使用[]相比，越界抛出异常
	}
	cout << endl;

	// at 和 [] 区别
	try
	{
		cout << "at 异常捕捉：";
		for (int i = 0; i < s.length()+3 ; i++)
		{
			cout << s.at(i) << " ";     // 与直接使用[]相比，越界抛出异常
		}
	}
	catch (...)
	{
		cout << "捕捉到异常！" << endl;
	}
	/*    // 未捕捉到异常, 直接宕机了
	try
	{
		cout << "[] 异常捕捉：";
		for (int i = 0; i < s.length() + 3; i++)
		{
			cout << s[i] << " ";     // 与直接使用[]相比，越界抛出异常
		}
	}
	catch (...)
	{
		cout << "捕捉到异常！" << endl;
	}
	*/
}

// 字符指针和 char * 之间转换
void testVoid3()
{
	// char * ==> string
	string s1 = "cscscscs";

	// string ==> char *
	char* p = const_cast<char*>(s1.c_str());
	cout << p << endl;

	// string copy到buf
	char buf[128] = { 0 };
	s1.copy(buf, 5);  // 只copy 内存数据, 不添加 '\0' 构成从风格字符串手动添加或者buf初始化为0
	cout << "->" << buf << "<-" << endl;
}

// 字符串连接
void testVoid4()
{
	string s1 = "abdcjgbfg";
	string s2 = "adfnasdjkdnf";

	// 使用+
	s1 += s2;
	cout << s1 << endl;

	// 使用append()
	s1.append(s2);
	cout << s1 << endl;
}

// string 的查找和替换
void testVoid5()
{
	string s = "ilu cyp ilu 111 ilu 333 ilu ccc";
	int index;
	index = s.find("ilu", 0);  // 从位置0查找字符串
	cout << index << endl;

	// 查找所有ilu
	index = 0;
	int num = 0;
	index = s.find("ilu", 0);  // 从位置0查找字符串
	while (index != string::npos)
	{
		num++;
		cout << num << "次找到ilu, 位置是：" << index << endl;
		index = s.find("ilu", index + 1);
	}

	// 查找 ilu 并替换为 ILU
	cout << "替换前：" << s << endl;
	index = 0;
	index = s.find("ilu", 0);  // 从位置0查找字符串
	while (index != string::npos)
	{
		s.replace(index, 3, "ILU");
		index = s.find("ilu", index + 1);
	}
	cout << "替换后：" << s << endl;

}

// 删除和插入
void testVoid6()
{
	string s = "ilu cyp ilu 111 ilu 333 ilu ccc";
	int index = 0;
	cout << "删除前：" << s << endl;
	// 删除l
	index = s.find("l", 0);  // 从位置0查找字符串
	while (index != string::npos)
	{
		s.erase(index, 1);
		index = s.find("l", index + 1);
	}
	cout << "删除后：" << s << endl;


	// 插入
	cout << "插入前：" << s << endl;
	s.insert(0, 2, 'Z');
	cout << "插入后：" << s << endl;
}

// string transform
void testVoid7()
{
	string s = "afasdfFAFASDFAS";

	cout << "变换前：" << s << endl;

    // toupper位置参数可以是 1函数入口地址 2函数对象 3预定义函数对象
	transform(s.begin(), s.end(), s.begin(), toupper);

	cout << "转大写：" << s << endl;

	transform(s.begin(), s.end(), s.begin(), tolower);

	cout << "转小写：" << s << endl;
}

int main() 
{
	int ret = 0;

	cout << "string 初始化" << endl;
	testVoid1();

	cout << "string 遍历" << endl;
	testVoid2();

	cout << "字符指针和 char* 之间转换" << endl;
	testVoid3();
	
	cout << "字符串连接" << endl;
	testVoid4();

	cout << "string 的查找和替换" << endl;
	testVoid5();

	cout << "string 删除和插入" << endl;
	testVoid6();

	cout << "string transform" << endl;
	testVoid7();
	
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}