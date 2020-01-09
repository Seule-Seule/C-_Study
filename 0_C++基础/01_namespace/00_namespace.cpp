#include "iostream"
//using namespace std;
// 文件iostream中没有引入标准命名空间，需要单独引入

void main_00() 
{

	std::cout << "Hello World!" << std::endl;
	system("pause");
}

using namespace std;

void main01() 
{
	std::cout << "Hello World!" << std::endl;
	system("pause");
}


// namespace 定义和使用
namespace namespaceA
{
	int		a = 100;
}

namespace namespaceB
{
	int		a = 90;
	namespace namespaceC
	{
		struct stud 
		{
			char	name[20];
			int		agg;
		};
	}
}

void main_02() 
{
	using namespace namespaceA;
	cout << a << endl;

	using namespace namespaceB;
	cout << namespaceB::a << endl;

	using namespaceB::namespaceC::stud;
	stud t1;

	using namespace namespaceB::namespaceC;
	stud t2;

	cout << "Hello World!" << endl;
	system("pause");
}


