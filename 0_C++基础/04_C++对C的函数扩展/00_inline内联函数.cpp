#include "iostream"

using namespace std;


#define MIN(a, b)  ((a) < (b) ? (a) : (b))

inline int min(int a, int b)
{
	return a < b ? a : b;
}

void main() 
{
	int a = 1;
	int b = 3; 

	int c = min(++a, b);  // a = 2, b = 3, c =2

	cout << "a:" << a << "b:" << b << "c:" << c << endl;

	a = 1;
	int d;
	d = MIN(++a, b); // ((++a) < b ? (++a) : b)  // a = 3, b = 3, d =3 //注意使用宏的时候不要使用++a这样的参数
	cout << "a:" << a << "b:" << b << "d:" << d << endl;
	
	cout << "Hello World!" << endl;
	system("pause");
}