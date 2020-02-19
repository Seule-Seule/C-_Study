
#include "iostream"
using namespace std;
#include <iomanip>
#include <iostream>


int main00() 
{
	int ret = 0;

	cout << "双精度数输出" << endl;
	double a = 123.456789012345;  // 对a赋初值
	cout << a << endl;;  //输出： 123.456
	cout << setprecision(9) << a << endl;  //输出： 123.456789
	cout << setprecision(6) << a << endl;;  //恢复默认格式(精度为6)
	cout << setiosflags(ios::fixed) << a << endl;;  //输出： 123.456789
	cout << setiosflags(ios::fixed) << setprecision(8) << a << endl;;  //输出： 123.45678901
	cout << setiosflags(ios::scientific) << a << endl;;  //输出： 1.234568e+02
	cout << setiosflags(ios::scientific) << setprecision(4) << a << endl;;  //输出： 1.2346e02

	cout << "整形数输出" << endl;
 	int b = 123456;  // 对b赋初值
// 	cout << b << endl;   // 输出： 123456
// 	cout << hex << b << endl;  // 输出： 1e240
// 	cout << setiosflags(ios::uppercase) << b << endl; // 输出： 1E240
// 	cout << setw(10) << b << '，' << b << endl;  // 输出：  123456，123456
// 	cout << setfill('*') << setw(10) << b << endl;  //输出：**** 123456
	cout << setiosflags(ios::showpos) << b << endl;   //输出： + 123456

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}



int main() 
{
	int ret = 0;

	cout << "Hello " << endl;
	cout.put('a').put('b');  // 单个字符输出
	cout.flush();            // 刷新缓存

	char buf[] = "asdasfd";
	cout.write(buf, strlen(buf)) << endl;
	cout.write(buf, strlen(buf) - 4) << endl;
	cout.write(buf, strlen(buf) + 8) << endl;   // 注意越界

	cout << "Test : ->" ;
	cout.width(30);           // 控制输出长度
	cout.fill('&');
	cout.setf(ios::showbase);
	cout.setf(ios::internal);
	cout << buf << "<- " << endl;

	system("pause");
	return ret;
}
