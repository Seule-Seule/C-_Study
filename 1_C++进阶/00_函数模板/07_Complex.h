#pragma once

template <typename ComplexType>
class Complex;      // 类的声明

template <typename ComplexType>
Complex< ComplexType>  Sub(Complex< ComplexType>& _z1, Complex< ComplexType>& _z2);


template <typename ComplexType>
class Complex
{
public:
	Complex(ComplexType a, ComplexType b);
	Complex operator+(Complex& _z);
	friend ostream& operator<<<ComplexType>(ostream& _cout, Complex& _z);
public:
	friend Complex  Sub< ComplexType>(Complex& _z1, Complex& _z2);

protected:
	ComplexType a;
	ComplexType b;
};

