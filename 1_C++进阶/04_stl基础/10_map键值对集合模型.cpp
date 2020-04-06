
#include "iostream"
using namespace std;
#include "map"
#include "string"


void test_void0()
{
	map<int, string> m1;

	// map 插入
	// 方法一
	m1.insert(pair<int, string>(1, "01"));
	m1.insert(pair<int, string>(2, "02"));

	// 方法二
	m1.insert(make_pair(3, "03"));
	m1.insert(make_pair(4, "04"));

	// 方法三
	m1.insert(map<int, string>::value_type(5, "05"));
	m1.insert(map<int, string>::value_type(6, "06"));

	// 方法四
	m1[7] = "07";
	m1[8] = "08";


	// map 遍历
	cout << "遍历" << endl;
	for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << "\t" << it->first << "<->" << it->second << endl;
	}

	// map 删除
	cout << "删除" << endl;
	while (!m1.empty())
	{
		map<int, string>::iterator it = m1.begin();
		cout << "\t" << it->first << "<->" << it->second << " Delete ok" << endl;
		m1.erase(it);
	}
}

// 四种插入方法的 异同
// 前三种方法返回 pair<iterator, bool>
// 第四种方法插入时覆盖已有相同项
void test_void1()
{
	map<int, string> m1;

	// map 插入
	// pair<iterator, bool> insert(_Valty&& _Val) 
	// 方法一
	m1.insert(pair<int, string>(1, "01"));
	pair<map<int, string>::iterator, bool> insert_ret2 = m1.insert(pair<int, string>(2, "02"));
	if (insert_ret2.second == false)
	{
		cout << insert_ret2.first->first << "  " << insert_ret2.first->second << "  insert fail!" << endl;
	}
	else
	{
		cout << insert_ret2.first->first << "  " << insert_ret2.first->second << "  insert success!" << endl;
	}


	// 方法二
	m1.insert(make_pair(3, "03"));
	m1.insert(make_pair(4, "04"));

	// 方法三
	m1.insert(map<int, string>::value_type(5, "05"));
	// 插入失败 未对容器产生影响
	pair<map<int, string>::iterator, bool> insert_ret6 = m1.insert(map<int, string>::value_type(5, "06"));
	if (insert_ret6.second == false)
	{
		cout << insert_ret6.first->first << "  " << insert_ret6.first->second << "  insert fail!" << endl;
	}
	else
	{
		cout << insert_ret6.first->first << "  " << insert_ret6.first->second << "  insert success!" << endl;
	}


	// 方法四  两次都插入成功 后一次覆盖前一次的值
	m1[7] = "07";
	m1[7] = "08";


	// map 遍历
	cout << "遍历" << endl;
	for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << "\t" << it->first << "<->" << it->second << endl;
	}
}

void test_void2()
{
	map<int, string> m1;

	// map 插入
	// 方法一
	m1.insert(pair<int, string>(1, "01"));
	m1.insert(pair<int, string>(2, "02"));

	// 方法二
	m1.insert(make_pair(3, "03"));
	m1.insert(make_pair(4, "04"));

	// 方法三
	m1.insert(map<int, string>::value_type(5, "05"));
	m1.insert(map<int, string>::value_type(6, "06"));

	// 方法四
	m1[7] = "07";
	m1[8] = "08";


	// map 遍历
	cout << "遍历" << endl;
	for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << "\t" << it->first << "<->" << it->second << endl;
	}
	
	// map 查找 
	// 方法一 find(elem)
	// _NODISCARD iterator find(const key_type& _Keyval) {
	map<int, string>::iterator it1 = m1.find(10);
	if (it1 != m1.end())
	{
		cout << it1->first << "  " << it1->second << " 查找成功！"<<endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}


	// 方法二 equal_range(elem)
	// _NODISCARD pair<iterator, iterator> equal_range(const key_type & _Keyval)
	// pari.first >= elem   pari.second > elem
	pair<map<int, string>::iterator, map<int, string>::iterator> equal_range_pair = m1.equal_range(5);
	if (equal_range_pair.first != m1.end())
	{
		cout << equal_range_pair.first->first << "  " << equal_range_pair.first->second << " 查找成功！" << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}

	if (equal_range_pair.second != m1.end())
	{
		cout << equal_range_pair.second->first << "  " << equal_range_pair.second->second << " 查找成功！" << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
}

int main() 
{
	int ret = 0;

	// test_void0();
	// test_void1();
	test_void2();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}