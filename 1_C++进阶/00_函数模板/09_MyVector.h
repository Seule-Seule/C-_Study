#pragma once
#include "iostream"
using namespace std;


template <typename Type>
class MyVector
{
	friend ostream& operator<< <Type> (ostream& out, const MyVector< Type >& obj);
public:
	MyVector(int size = 0);
	MyVector(const MyVector& obj);
	~MyVector();

public:
	Type& operator[](int inedx);
	MyVector& operator=(const MyVector & obj);
private:
	int ValueLen;
	Type* ValueSpace;
};
