#include "iostream"

using namespace std;

#include "05_Array.h"

void main() 
{
	// 定义
	Array IntArray(20);

	// 赋值
	for (int i = 0; i < IntArray.getLenght(); i++)
	{
		IntArray.setData(i, i);
	}
	//打印
	for (int i = 0; i < IntArray.getLenght(); i++)
	{
		//cout << "IntArray[" << i << "]\t" << IntArray.getData(i) << endl;
	}

	Array IntArray2 = IntArray;

	//打印
	for (int i = 0; i < IntArray2.getLenght(); i++)
	{
		//cout << "IntArray2[" << i << "]\t" << IntArray2.getData(i) << endl;
	}

	
	// 重载[] 操作符
	// int operator[](int index)
	// 返回引用
	// int& operator[](int index)
	for (int i = 0; i < IntArray.getLenght(); i++)
	{
		IntArray[i] = i;
	}
	for (int i = 0; i < IntArray.getLenght(); i++)
	{
		//cout << IntArray[i] << endl;
	}


	// 重载等号操作符 = 
	// Array& operator=(Array& IntArray)
	Array IntArray3 = IntArray;
	IntArray3 = IntArray2 = IntArray;
	for (int i = 0; i < IntArray.getLenght(); i++)
	{
		// cout << IntArray[i] << IntArray2[i] << IntArray3[i] << endl;
	}

	// 重载等号操作符 ==
	// IntArray.operator==(IntArray3)
	//bool operator==(Array &IntArray3)
	if (IntArray == IntArray3)
	{
		//cout << "相等" << endl;
	}
	else
	{
		//cout << "不相等" << endl;
	}

	// 重载不等号操作符 !=
	//IntArray.operator!=(IntArray3)
	//bool operator!=(Array& IntArray3)
	if (IntArray != IntArray3)
	{
		//cout << "不相等" << endl;
	}
	else
	{
		//cout << "相等" << endl;
	}

	//重载左移操作符 <<
	// cout.operator<<(IntArray)
	// operator<<(cout, IntArray)
	// ostream& operator<<(ostream& out, Array& IntArray)
	cout << IntArray << IntArray3;
	 
	//重载右移操作符 >>
	// cin.operator>>(IntArray)
	//istream&  operator>>(istream& in, Array& IntArray)
	cin >> IntArray >> IntArray3;
	cout << IntArray << IntArray3;

	cout << "Hello World!" << endl;
	system("pause");

}