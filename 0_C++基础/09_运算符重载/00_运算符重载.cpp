#include "iostream"

using namespace std;

class Complex
{
public:
	int Im;
	int Re;
public:
	Complex(int Im=0, int Re=0)
	{
		this->Im = Im;
		this->Re = Re;
	}
	void PrintComplex()
	{
		cout << Im << "+" << Re << "i" << endl;
	}
};

Complex ComplexAdd(const Complex& z1, const Complex& z2)
{
	Complex tmp(z1.Im + z2.Im, z2.Re + z1.Re);
	return tmp;
}

Complex operator+(const Complex& z1, const Complex& z2)
{
	Complex tmp(z1.Im + z2.Im, z2.Re + z1.Re);
	return tmp;
}

void main() 
{
	Complex z1(1, 2), z2(2, 3);
	//Complex z3 = z1 + z2; // 不能直接进行+操作符， 需要对操作符进行重载
	//z3.PrintComplex();
	
	Complex z4 = ComplexAdd(z1, z2);  // 函数实现两个类相加
	z4.PrintComplex();

	Complex z5 = operator+(z1, z2);
	z5.PrintComplex(); 

	Complex z6 = z1 + z2;  // 操作符重载的本质是函数调用
	z6.PrintComplex();

	cout << "Hello World!" << endl;
	system("pause");
}