#include "iostream"

using namespace std;

class Complex
{
private:
	int Im;
	int Re;
public:
	Complex(int Im = 0, int Re = 0)
	{
		this->Im = Im;
		this->Re = Re;
	}
	void PrintComplex()
	{
		cout << Im << "+" << Re << "i" << endl;
	}
public:
	friend Complex operator+(const Complex& z1, const Complex& z2);
	Complex  operator-(const Complex& z2)
	{
		Complex tmp(this->Im-z2.Im, this->Re-z2.Re);
		return tmp;
	}
};

/*
操作符重载函数的确定：
 1 确定函数名， operator重载运算符()
 2 确定参数：运算符运算对象
 3 确定返回值： 根据实际需要确定
*/

Complex operator+(const Complex& z1, const Complex& z2)
{
	Complex tmp(z1.Im+z2.Im, z1.Re+z2.Re);
	return tmp;
}

void main() 
{
	Complex z1(1, 2), z2(3, 4);
	 
	// 友元函数重载 + 操作符
	// Complex operator+(const Complex & z1, const Complex & z2);
	Complex z3 = z1 + z2;
	z3.PrintComplex();


	// 成员函数重载 - 操作符
	//Complex  operator-(this, z2);
	//Complex  operator-(const Complex & z2);
	Complex z4 = z1 - z2;
	z4.PrintComplex();

	cout << "Hello World!" << endl;
	system("pause");
}