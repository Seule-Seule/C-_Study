#include "iostream"

using namespace std;

void testmain();

class Test
{
public:
	Test(int _a)
	{
		a = _a;
		cout << "构造函数" << endl;
	}
	~Test()
	{
		cout << "析构函数" << endl;
	}
protected:
private:
	int a;
};

// new 和 delete 
// new 基础类型 数组类型 复杂对象（类、结构体）

void main() 
{
	// 基础类型
	int* pInt = (int*)malloc(sizeof(int));
	*pInt = 10;

	int* pInt2 = new int(2);

	cout << "*pInt:" << *pInt << "\t*pInt2" << *pInt2 << endl;
	free(pInt);
	delete pInt2;

	// 数组类型 
	char* pChar = (char*)malloc(sizeof(char) * 20); // char pChar[20];
	pChar[0] = 10;

	char* pChar2 = new char[20];
	pChar2[0] = 20;

	cout << "pChar[0]:" << pChar[0] << "\tpChar2[0]" << pChar2[0] << endl;
	free(pChar);
	delete [] pChar2;  // 释放数组，加[]

	// 复杂对象（类、结构体）
	Test* pTest = (Test*)malloc(sizeof(Test)); // 只分配内存，不调用构造函数初始化
	
	Test* pTest2 = new Test(2); // 分配内存并调用构造函数初始化

	free(pTest);    // 只释放内存
	delete pTest2;  // 释放内存并调用析构函数销毁类对象

	testmain();
	
	cout << "Hello World!" << endl;
	system("pause");
}

void testmain()
{
	// 基础类型
	int* pInt = (int*)malloc(sizeof(int));
	*pInt = 10;

	int* pInt2 = new int(2);

	cout << "*pInt:" << *pInt << "\t*pInt2" << *pInt2 << endl;
	//free(pInt);
	//delete pInt2;
	delete pInt;
	free(pInt2);

	// 数组类型 
	char* pChar = (char*)malloc(sizeof(char) * 20); // char pChar[20];
	pChar[0] = 10;

	char* pChar2 = new char[20];
	pChar2[0] = 20;

	cout << "pChar[0]:" << pChar[0] << "\tpChar2[0]" << pChar2[0] << endl;
	//free(pChar);
	//delete[] pChar2;  // 释放数组，加[]
	delete[] pChar;
	free(pChar2);

	// 复杂对象（类、结构体）
	Test* pTest = (Test*)malloc(sizeof(Test)); // 只分配内存，不调用构造函数初始化

	Test* pTest2 = new Test(2); // 分配内存并调用构造函数初始化

	//free(pTest);    // 只释放内存
	//delete pTest2;  // 释放内存并调用析构函数销毁类对象
	delete pTest;
	free(pTest2);

	
	cout << "Hello World!" << endl;
	system("pause");
}