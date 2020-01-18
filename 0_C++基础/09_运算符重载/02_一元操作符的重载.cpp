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
	// 重载 + 操作符
	friend Complex operator+(const Complex& z1, const Complex& z2);
	//重载 前置++ 操作符
	friend Complex& operator++(Complex& z1);
	// 重载 后置++ 操作符
	friend Complex operator++(Complex& z1, int);
	// 重载 - 操作符
	Complex  operator-(const Complex& z2)
	{
		Complex tmp(this->Im - z2.Im, this->Re - z2.Re);
		return tmp;
	}
	// 重载 前置-- 操作符
	Complex& operator--()
	{
		this->Im--;
		this->Re--;
		return *this;
	}
	// 重载 后置-- 操作符
	Complex operator--(int)
	{
		Complex tmp = *this;
		this->Im--;
		this->Re--;
		return tmp;
	}
};

/*
操作符重载函数的确定：
 1 确定函数名， operator重载运算符()
 2 确定参数：运算符运算对象
 3 确定返回值： 根据实际需要确定
*/

// 重载 + 操作符
Complex operator+(const Complex& z1, const Complex& z2)
{
	Complex tmp(z1.Im + z2.Im, z1.Re + z2.Re);
	return tmp;
}
//重载 前置++ 操作符 
Complex& operator++(Complex& z1)
{
	z1.Im++;
	z1.Re++;
	return z1;
}
// 重载 后置++ 操作符
Complex operator++(Complex& z1, int)
{
	Complex  tmp = z1;
	z1.Im++;
	z1.Re++;
	return tmp;
}
void main() 
{
	Complex z1(1, 2), z2(3, 4);

	// 前置++ 重载,友元函数
	//Complex& operator++(Complex & z1)
	++z1;
	z1.PrintComplex();

	// 前置-- 重载，成员函数
	//Complex& z1.operator--(this)
	// Complex&  operator--();
	--z1;
	z1.PrintComplex();

	// 后置++ 重载， 友元函数
	// Complex operator++(Complex & z1, int)  // 后置int 占位参数
	z1++;
	z1.PrintComplex();

	// 后置-- 重载， 成员函数
	// Complex z1.operator--(this, int);  // 后置int 占位参数
	// Complex operator--(int);          // 后置int 占位参数
	z1--;
	z1.PrintComplex();

	cout << "Hello World!" << endl;
	system("pause");
}