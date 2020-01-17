#include "iostream"

using namespace std;

#include "00_Array.h"

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
		cout << "IntArray[" << i << "]\t" << IntArray.getData(i) << endl;
	}

	Array IntArray2 = IntArray;

	//打印
	for (int i = 0; i < IntArray2.getLenght(); i++)
	{
		cout << "IntArray2[" << i << "]\t" << IntArray2.getData(i) << endl;
	}
	cout << "Hello World!" << endl;
	system("pause");
}