
#include "iostream"
using namespace std;

// 类模板
template <typename Type>
class Test
{
public:
	Test(Type a)
	{
		this->a = a;
	}
	void PrintA()
	{
		cout << " a: " << a << endl;
	}
 private:
	Type a;
};

// 类模板做函数参数 也需要具体化
void useTest(Test <int> a)
{
	a.PrintA();
}

int main() 
{
	int ret = 0;

	// 类模板定义: 类模板是抽象的  需要具体化
	Test <int> a1(10), a2(20), a3(30);  // 类模板使用 必须初始化参数
	a1.PrintA();

	useTest(a2);
	useTest(a3);


	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}