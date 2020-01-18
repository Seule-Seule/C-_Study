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
	// friend void operator<<(ostream& out, Complex& z1);
	friend ostream& operator<<(ostream& out, Complex& z1);
	friend istream& operator>>(istream& in, Complex& z1);
};

/*
void operator<<(ostream& out, Complex& z1)
{
	out << z1.Im << "+" << z1.Re << "i" << endl;
}
*/
ostream& operator<<(ostream& out, Complex& z1)
{
	out << z1.Im << "+" << z1.Re << "i" << endl;
	return out;
}
istream& operator>>(istream& in, Complex& z1)
{
	in >> z1.Im >> z1.Re;
	return in;
}
void main() 
{
	Complex z1(1, 2), z2(3, 4);

	// << 操作符重载
	// 1.友元函数
	//   void operator<<(ostream & out, Complex & z1);
	// 2.成员函数
	//        cout.operator<<(Complex & z1)
	//     需要修改ostream类，不可能达到，故不可行
	cout << z1;

	// 返回引用
	// ostream& operator<<(ostream& out, Complex& z1);
	cout << z1 << "\t" << z2 << endl;

	//int a, b;
	//cin >> a >> b;
	//cout << a << b << endl;
	// 右移操作符重载
	// istream&  operator>>(istream& in, Complex& z1);
	cin >> z1;
	z1.PrintComplex();

	cin >> z1 >> z2;
	z1.PrintComplex();
	z2.PrintComplex();

	cout << "Hello World!" << endl;
	system("pause");
}