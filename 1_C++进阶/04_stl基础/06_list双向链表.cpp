
#include "iostream"
using namespace std;

#include <list>

void testVoid0()
{
	list<int> l;
	
	cout << "list 大小 ：" << l.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);  // 尾插法
	}
	cout << "list 大小 ：" << l.size() << endl;

	// 遍历
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// 不能随机访问
	it--;
	// it = it + 6;  // ERROR 

	list<int>::iterator itInsert = l.begin();
	itInsert++; itInsert++; itInsert++;
	// 插入   
	l.insert(itInsert, 50);

	// list下标从0开始
	// list插入时, it位置插入元素，剩余元素下标加1

	it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

// list删除
void testVoid1()
{
	list<int> l;

	cout << "list 大小 ：" << l.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);  // 尾插法
	}
	cout << "list 大小 ：" << l.size() << endl;

	// 遍历
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// 1 erase([begin, end))
	list<int>::iterator itEraseBegin = l.begin();
	list<int>::iterator itEraseEnd = l.begin();
	itEraseEnd++; itEraseEnd++; itEraseEnd++;
	l.erase(itEraseBegin, itEraseEnd);   // [0, 3) 删除时区间左闭右开， 即左删右不删

	it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;


	// 2 erase(pos) 
	itEraseEnd++; itEraseEnd++; itEraseEnd++;
	list<int>::iterator index = l.erase(itEraseEnd);   // 删除pos位置元素， 返回下一个数据位置

	cout << "下一个数据位置： " << *index << endl;
	it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// 3 remove(elem) 
	l.push_back(3);
	l.push_front(3);
	it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	l.remove(3); // 删除list所有数据为elem的项

	it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// 4 clear() 
	l.clear();  // 删除所有元素
	cout << l.size() << endl;
}

int main() 
{
	int ret = 0;

	// testVoid0();
	testVoid1();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}