
#include "iostream"
using namespace std;
#include "07_Complex.hpp"


int main() 
{
	int ret = 0;

	Complex<int>	z1(12, 30);
	Complex<int>	z2(13, 40);

	Complex<int>	z3 = z1 + z2;

	cout << z3 << "  " << z1 << "  " << z2 << endl;

	// 友元函数滥用

	Complex<int>	z4(0, 0);
	z1 = Sub(z4, z3);  // 友元函数滥用
	cout << z3 << "  " << z1 << "  " << z2 << endl;


	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}