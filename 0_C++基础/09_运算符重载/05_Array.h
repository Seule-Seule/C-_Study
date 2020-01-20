#pragma once

#include "iostream"

using namespace std;

class Array
{
public:
	Array(int lenght);
	Array(const Array& tmp);
	~Array();
	void setData(int index, int value);
	int getData(int index);
	int getLenght();
	//int operator[](int index);
	int& operator[](int index);
	Array& operator=(Array& IntArray);
	bool operator==(Array& IntArray3);
	bool operator!=(Array& IntArray3);
	void operator()(int PrintLen);
	friend ostream& operator<<(ostream& out, Array& IntArray);
	friend istream& operator>>(istream& in, Array& IntArray);
private:
	int lenght;
	int* pValue;
};

// 重载 [] == != 操作符