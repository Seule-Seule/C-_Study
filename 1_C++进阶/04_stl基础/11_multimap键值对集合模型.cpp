
#include "iostream"
using namespace std;
#include "map"
#include "string"

/*
公司按部门分类 
	销售部 2人
	研发部 2人
	财务部 1人
*/
class People
{
public:
	int		age;
	string	name;
public:
	People(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
};

void test_void()
{
	People p1(30, "张1");
	People p2(34, "张2");
	People p3(32, "王1");
	People p4(36, "王2");
	People p5(27, "李1");

	multimap<string, People>  m1;

	m1.insert(make_pair("销售部", p1));
	m1.insert(make_pair("销售部", p2));
	m1.insert(make_pair("研发部", p3));
	m1.insert(make_pair("研发部", p4));
	m1.insert(make_pair("财务部", p5));

	//// 遍历
	//for (multimap<string, People>::iterator it = m1.begin(); it != m1.end(); it++)
	//{
	//	cout << it->first << " -> " << it->second.name << " :" << it->second.age << endl;
	//}

	//修改信息
	for (multimap<string, People>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		// cout << it->first << " -> " << it->second.name << " :" << it->second.age << endl;
		if (it->second.age == 32)
		{
			it->second.name = "32_years";
		}
	}

	// 遍历
	for (multimap<string, People>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << it->first << " -> " << it->second.name << " :" << it->second.age << endl;

	}

	// 部门打印
	cout << "***********查找销售部员工****************" << endl;
	int count_number = m1.count("销售部");
	int flag = 0;
	multimap<string, People>::iterator it2 = m1.find("销售部");
	while (it2 != m1.end() && flag < count_number)
	{
		cout << it2->first << " -> " << it2->second.name << " :" << it2->second.age << endl;
		it2++;
		flag++;
	}

}

int main() 
{
	int ret = 0;

	test_void();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}