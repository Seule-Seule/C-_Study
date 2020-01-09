// C 语言中有太多灰色地带
// 函数可以没有返回值类型？？


/*
f(i){       // 函数没有返回值类型，参数也没有类型，C语言不报错
	return 5;
}
*/

#include "iostream"

using namespace std;

int f(int i) {       // 函数没有返回值类型，参数也没有类型，C++语言报错,必须有
	return 5;
}
void main_51() 
{

	cout << "Hello World!" << endl;
	system("pause");
}