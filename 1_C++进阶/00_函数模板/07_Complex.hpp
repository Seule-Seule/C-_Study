#include "07_Complex.h"

#include "iostream"
using namespace std;

// template <typename ComplexType>
// class Complex;      // 类的声明
// 
// template <typename ComplexType>
// Complex< ComplexType>  Sub(Complex< ComplexType>& _z1, Complex< ComplexType>& _z2);
// 



template <typename ComplexType>
Complex<ComplexType> Complex<ComplexType>::operator+(Complex<ComplexType>& _z)
{
	Complex<ComplexType> tmp(a + _z.a, b + _z.b);
	return tmp;
}

template <typename ComplexType>
Complex<ComplexType>::Complex(ComplexType a, ComplexType b)
{
	this->a = a;
	this->b = b;
}

// !!!友元函数 重载运算符
/*  // 报错了  报错信息
class std::basic_ostream<char, struct std::char_traits<char> >&
	__cdecl operator<<
	(class std::basic_ostream<char, struct std::char_traits<char> >&,
		class Complex<int>&)
*/
//  解决办法: //friend ostream& operator<<<ComplexType>(ostream& _cout, Complex& _z);
template <typename ComplexType>
ostream& operator<<(ostream& _cout, Complex<ComplexType>& _z)
{
	_cout << _z.a << "+" << _z.b << "i";
	return _cout;
}

// !!!友元函数滥用 
/*  报错信息
class Complex<int> __cdecl Sub
(class Complex<int> &,class Complex<int> &)
*/
// 解决办法
/*  类的声明和滥用友元函数的声明 类的实现和声明在同一文件中是才有用
template <typename ComplexType>
class Complex;      // 类的声明

template <typename ComplexType>
Complex< ComplexType>  Sub(Complex< ComplexType>& _z1, Complex< ComplexType>& _z2);
*/
template <typename ComplexType>
Complex<ComplexType> Sub(Complex<ComplexType >& _z1, Complex<ComplexType >& _z2)
{
	Complex<ComplexType> tmp(_z1.a - _z2.a, _z1.b - _z2.b);
	return tmp;
}
