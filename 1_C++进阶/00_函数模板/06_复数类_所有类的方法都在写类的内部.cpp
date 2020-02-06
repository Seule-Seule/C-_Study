
#include "iostream"
using namespace std;


// 模板类 所有方法写到类的内部
template <typename ComplexType>
class Complex
{
public:
	Complex(ComplexType a, ComplexType b)
	{
		this->a = a;
		this->b = b;
	}
public:
	friend Complex  Sub(Complex& _z1, Complex& _z2)
	{
		Complex tmp(_z1.a - _z2.a, _z1.b - _z2.b);
		return tmp;
	}
	friend ostream& operator<<(ostream& _cout, Complex& _z)
	{
		_cout << _z.a << "+" << _z.b << "i";
		return _cout;
	}
	Complex operator+(Complex& _z)
	{
		Complex tmp(a + _z.a, b + _z.b);
		return tmp;
	}
protected:
	ComplexType a;
	ComplexType b;
};

/*
ostream& operator<<(ostream& _cout, Complex& _z)
{
	_cout << _z.a << "+" << _z.b << "i";
	return _cout;
}
*/

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